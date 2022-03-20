/*** 
 * @Description: 
 * @Version: 2.0
 * @Autor: Bedrock
 * @Date: 2022-01-01 14:42:00
 * @LastEditors: Bedrock
 * @LastEditTime: 2022-03-20 10:41:46
 * @Author: Bedrock
 * @FilePath: /bedrock_encoder/test/bedrock_test.cpp
 * @版权声明
 */

#include <pthread.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>


#include "argparse.h"
#include "mpi_test_utils.h"
#include "bedrock_enc.h"
#include "filecfg.h"
#include "xop/RtspServer.h"
#include "net/Timer.h"

#define LOG_TAG "bedrock_enc_lib"

#define MAX_TIME_OUT_ME 20
#define TEST_RC_MODE 0
#define INPUT_FILE "/nfs/bridge-far_cif.yuv"
#define OUTPUT_FILE "/nfs/bride"
#define WIDTH 352
#define HEIGHT 288



static void mpi_venc_test_show_options(const Bedrock_VENC_CTX_S *ctx) {
    RK_PRINT("cmd parse result:\n");
    RK_PRINT("input  file name       : %s\n", ctx->srcFileUri);
    RK_PRINT("output file name       : %s\n", ctx->dstFilePath);
    RK_PRINT("src width              : %d\n", ctx->u32SrcWidth);
    RK_PRINT("src height             : %d\n", ctx->u32SrcHeight);
    RK_PRINT("src virWidth           : %d\n", ctx->u32srcVirWidth);
    RK_PRINT("src virHeight          : %d\n", ctx->u32srcVirHeight);
    RK_PRINT("src pixel format       : %d\n", ctx->u32SrcPixFormat);
    RK_PRINT("encode codec type      : %d\n", ctx->u32DstCodec);
    RK_PRINT("loop count             : %d\n", ctx->s32LoopCount);
    RK_PRINT("channel index          : %d\n", ctx->u32ChnIndex);
    RK_PRINT("channel num            : %d\n", ctx->u32ChNum);
    RK_PRINT("output buffer count    : %d\n", ctx->u32StreamBufCnt);
    RK_PRINT("one picture size       : %d\n", ctx->u32BufferSize);
    return;
}

void* venc_get_stream(void *pArgs) {
    Bedrock_VENC_CTX_S *pstCtx     = reinterpret_cast<Bedrock_VENC_CTX_S *>(pArgs);
    void            *pData      = RK_NULL;
    RK_S32           s32Ret     = RK_SUCCESS;
    FILE            *fp         = RK_NULL;
    char             name[256]  = {0};
    RK_U32           u32Ch      = pstCtx->u32ChnIndex;
    RK_S32           s32StreamCnt = 0;
    VENC_STREAM_S    stFrame;
    std::string suffix = "live";
	std::string ip = "172.17.3.90";
	std::string port = "554";
	std::string rtsp_url = "rtsp://" + ip + ":" + port + "/" + suffix;
    	
	std::shared_ptr<xop::EventLoop> event_loop(new xop::EventLoop());
	std::shared_ptr<xop::RtspServer> server = xop::RtspServer::Create(event_loop.get());

	if (!server->Start("0.0.0.0", atoi(port.c_str()))) {
		printf("RTSP Server listen on %s failed.\n", port.c_str());
		return 0;
	}
	xop::MediaSession *session = xop::MediaSession::CreateNew("live"); 
	session->AddSource(xop::channel_0, xop::H264Source::CreateNew()); 
	//session->StartMulticast(); 
	session->AddNotifyConnectedCallback([] (xop::MediaSessionId sessionId, std::string peer_ip, uint16_t peer_port){
		printf("RTSP client connect, ip=%s, port=%hu \n", peer_ip.c_str(), peer_port);
	});
   
	session->AddNotifyDisconnectedCallback([](xop::MediaSessionId sessionId, std::string peer_ip, uint16_t peer_port) {
		printf("RTSP client disconnect, ip=%s, port=%hu \n", peer_ip.c_str(), peer_port);
	});

	xop::MediaSessionId session_id = server->AddSession(session);
	
	std::cout << "Play URL: " << rtsp_url << std::endl;
    if (pstCtx->dstFilePath != RK_NULL) {
        mkdir(pstCtx->dstFilePath, 0777);

        snprintf(name, sizeof(name), "%s/test_%d.h264",
            pstCtx->dstFilePath, pstCtx->u32ChnIndex);

        fp = fopen(name, "wb");
        if (fp == RK_NULL) {
            RK_LOGE("chn %d can't open file %s in get picture thread!\n", u32Ch, name);
            return RK_NULL;
        }
    }
    stFrame.pstPack = reinterpret_cast<VENC_PACK_S *>(malloc(sizeof(VENC_PACK_S)));

    while (!pstCtx->threadExit) {
        s32Ret = RK_MPI_VENC_GetStream(u32Ch, &stFrame, -1);
        if (s32Ret >= 0) {
            if (stFrame.pstPack->bStreamEnd == RK_TRUE) {
                RK_LOGI("chn %d reach EOS stream", u32Ch);
                RK_MPI_VENC_ReleaseStream(u32Ch, &stFrame);
                break;
            }
            s32StreamCnt++;
            RK_LOGI("get chn %d stream %d", u32Ch, s32StreamCnt);
            if (pstCtx->dstFilePath != RK_NULL) {
                pData = RK_MPI_MB_Handle2VirAddr(stFrame.pstPack->pMbBlk);
                xop::AVFrame videoFrame = {0};
                videoFrame.type = 0; 
                videoFrame.size = stFrame.pstPack->u32Len;
                videoFrame.timestamp = xop::H264Source::GetTimestamp();
                videoFrame.buffer.reset(new uint8_t[videoFrame.size]); 
                memcpy(videoFrame.buffer.get(), pData, videoFrame.size);
                server->PushFrame(session_id, xop::channel_0, videoFrame);
                fwrite(pData, 1, stFrame.pstPack->u32Len, fp);
                fflush(fp);
            }
            RK_MPI_VENC_ReleaseStream(u32Ch, &stFrame);
        } else {
             if (pstCtx->threadExit) {
                break;
             }

             usleep(1000llu);
        }
    }

    if (stFrame.pstPack)
        free(stFrame.pstPack);

    if (fp)
        fclose(fp);

    return RK_NULL;
}

void* venc_send_frame(void *pArgs) {
    Bedrock_VENC_CTX_S     *pstCtx        = reinterpret_cast<Bedrock_VENC_CTX_S *>(pArgs);
    RK_S32               s32Ret         = RK_SUCCESS;
    RK_U8               *pVirAddr       = RK_NULL;
    FILE                *fp             = RK_NULL;
    MB_BLK               blk            = RK_NULL;
    RK_S32               s32LoopCount   = pstCtx->s32LoopCount;
    MB_POOL              pool           = pstCtx->vencPool;
    RK_U32               u32Ch          = pstCtx->u32ChnIndex;
    RK_S32               s32FrameCount  = 0;
    RK_S32               s32ReachEOS    = 0;
    VIDEO_FRAME_INFO_S   stFrame;

    fp = fopen(pstCtx->srcFileUri, "r");
    if (fp == RK_NULL) {
        RK_LOGE("chn %d can't open file %s!\n", u32Ch, pstCtx->srcFileUri);
        return RK_NULL;
    }

    while (!pstCtx->threadExit) {
        blk = RK_MPI_MB_GetMB(pool, pstCtx->u32BufferSize, RK_TRUE);

        if (RK_NULL == blk) {
            usleep(2000llu);
            continue;
        }
        pVirAddr = reinterpret_cast<RK_U8 *>(RK_MPI_MB_Handle2VirAddr(blk));
        s32Ret = read_image(pVirAddr, pstCtx->u32SrcWidth, pstCtx->u32SrcHeight,
                  pstCtx->u32srcVirWidth, pstCtx->u32srcVirHeight, pstCtx->u32SrcPixFormat, fp);
        if (s32Ret != RK_SUCCESS) {
             s32ReachEOS = 1;
             if (s32LoopCount > 0) {
                s32LoopCount--;
                RK_LOGI("finish venc count %d\n", pstCtx->s32LoopCount - s32LoopCount);
                if (s32LoopCount > 0) {
                    s32ReachEOS = 0;
                    RK_MPI_MB_ReleaseMB(blk);

                    fseek(fp, 0L, SEEK_SET);
                    RK_LOGI("seek finish ch %d", u32Ch);
                    continue;
                }
             }
        }

        RK_MPI_SYS_MmzFlushCache(blk, RK_FALSE);

        stFrame.stVFrame.pMbBlk = blk;
        stFrame.stVFrame.u32Width = pstCtx->u32SrcWidth;
        stFrame.stVFrame.u32Height = pstCtx->u32SrcHeight;
        stFrame.stVFrame.u32VirWidth = pstCtx->u32srcVirWidth;
        stFrame.stVFrame.u32VirHeight = pstCtx->u32srcVirHeight;
        stFrame.stVFrame.enPixelFormat = (PIXEL_FORMAT_E)pstCtx->u32SrcPixFormat;
        stFrame.stVFrame.u32FrameFlag |= s32ReachEOS ? FRAME_FLAG_SNAP_END : 0;
__RETRY:
        s32Ret = RK_MPI_VENC_SendFrame(u32Ch, &stFrame, -1);
        if (s32Ret < 0) {
            if (pstCtx->threadExit) {
                RK_MPI_MB_ReleaseMB(blk);
                break;
            }

            usleep(10000llu);
            goto  __RETRY;
        } else {
            RK_MPI_MB_ReleaseMB(blk);
            s32FrameCount++;
            RK_LOGI("chn %d frame %d", u32Ch, s32FrameCount);
        }
        if (s32ReachEOS) {
            RK_LOGI("chn %d reach EOS.", u32Ch);
            break;
        }
    }

    if (fp)
        fclose(fp);

    return RK_NULL;
}

static void setting_default_argc(Bedrock_VENC_CTX_S *ctx) {
    ctx->s32LoopCount    = 1;
    ctx->u32StreamBufCnt = 8;
    ctx->u32ChNum        = 1;
    ctx->u32SrcPixFormat = RK_FMT_YUV420SP;
    ctx->u32DstCodec     = RK_VIDEO_ID_AVC;
    
    ctx->srcFileUri = INPUT_FILE;
    ctx->dstFilePath = OUTPUT_FILE;
    ctx->u32SrcWidth = WIDTH;
    ctx->u32SrcHeight = HEIGHT;
    ctx->s32LoopCount = 100;
}
/*** 
 * @description: 
 * @param {Bedrock_VENC_CTX_S} *ctx
 * @return {*}
 * @author: Bedrock
 * @brief: 初始化mpi_enc相关参数
 * @use: 
 */
RK_S32 bed_mpi_enc_init(Bedrock_VENC_CTX_S *ctx)
{
    RK_S32                  s32Ret = RK_SUCCESS;
    RK_U32                  u32Ch = 0;
    VENC_CHN_ATTR_S         stAttr;
    VENC_RECV_PIC_PARAM_S   stRecvParam;
    VENC_RC_PARAM_S         stRcParam;
    MB_POOL_CONFIG_S        stMbPoolCfg;
   

    memset(&stAttr, 0, sizeof(VENC_CHN_ATTR_S));
    memset(&stRecvParam, 0, sizeof(VENC_RECV_PIC_PARAM_S));
    memset(&stRcParam, 0, sizeof(VENC_RC_PARAM_S));

    if (ctx->u32BufferSize <= 0) {
        PIC_BUF_ATTR_S stPicBufAttr;
        MB_PIC_CAL_S stMbPicCalResult;

        stPicBufAttr.u32Width = ctx->u32SrcWidth;
        stPicBufAttr.u32Height = ctx->u32SrcHeight;
        stPicBufAttr.enPixelFormat = (PIXEL_FORMAT_E)ctx->u32SrcPixFormat;
        stPicBufAttr.enCompMode = COMPRESS_MODE_NONE;
        s32Ret = RK_MPI_CAL_COMM_GetPicBufferSize(&stPicBufAttr, &stMbPicCalResult);
        if (s32Ret != RK_SUCCESS) {
            RK_LOGE("get picture buffer size failed. err 0x%x", s32Ret);
            return s32Ret;
        }
        ctx->u32BufferSize = stMbPicCalResult.u32MBSize;
        RK_LOGD("calc picture size: %d", ctx->u32BufferSize);
    }

    if (ctx->u32BufferSize > 32 * 1024 * 1024) {
        RK_LOGE("too large picture size: %d", ctx->u32BufferSize);
        return RK_FAILURE;
    }

    for (u32Ch = 0; u32Ch < ctx->u32ChNum; u32Ch++) {
        if (ctx->u32ChNum >= 1) {
            ctx->u32ChnIndex = u32Ch;
        }

        stAttr.stVencAttr.enType = (RK_CODEC_ID_E)ctx->u32DstCodec;
        stAttr.stVencAttr.u32Profile = H264E_PROFILE_HIGH;
        stAttr.stVencAttr.enPixelFormat = (PIXEL_FORMAT_E)ctx->u32SrcPixFormat;
        stAttr.stVencAttr.u32PicWidth = ctx->u32SrcWidth;
        stAttr.stVencAttr.u32PicHeight = ctx->u32SrcHeight;

        if (ctx->u32srcVirWidth <= 0) {
            ctx->u32srcVirWidth = ctx->u32SrcWidth;
        }
        stAttr.stVencAttr.u32VirWidth = ctx->u32srcVirWidth;

        if (ctx->u32srcVirHeight <= 0) {
            ctx->u32srcVirHeight = ctx->u32SrcHeight;
        }
        stAttr.stVencAttr.u32VirHeight = ctx->u32srcVirHeight;
        stAttr.stVencAttr.u32StreamBufCnt = ctx->u32StreamBufCnt;
        stAttr.stVencAttr.u32BufSize = ctx->u32BufferSize;

        RK_MPI_VENC_CreateChn(u32Ch, &stAttr);

        RK_MPI_VENC_StartRecvFrame(u32Ch, &stRecvParam);

        memset(&stMbPoolCfg, 0, sizeof(MB_POOL_CONFIG_S));
        stMbPoolCfg.u64MBSize = ctx->u32BufferSize;
        stMbPoolCfg.u32MBCnt  = 10;
        stMbPoolCfg.enAllocType = MB_ALLOC_TYPE_DMA;

        ctx->vencPool = RK_MPI_MB_CreatePool(&stMbPoolCfg);
    }
    return RK_SUCCESS;
}
RK_S32 bed_mpi_enc_remove()
{
    RK_S32 s32Ret = RK_SUCCESS;
    s32Ret = RK_MPI_SYS_Exit();
    if (s32Ret != RK_SUCCESS) {
        return s32Ret;
    }
    return s32Ret;
}

int main(int argc, char const* argv[]) 
{
    RK_S32 s32Ret = RK_SUCCESS;
    RK_U32 u32Ch = 0;
    Bedrock_VENC_CTX_S ctx;
    Bedrock_VENC_CTX_S      stVencCtx[VENC_MAX_CHN_NUM];
    pthread_t               vencThread[VENC_MAX_CHN_NUM];
    pthread_t               getStreamThread[VENC_MAX_CHN_NUM];
    memset(&ctx, 0, sizeof(Bedrock_VENC_CTX_S));
    const char* file = NULL;
    init_argc_for_cfg(&ctx, file);
    ctx.s32LoopCount    = 1;
    ctx.u32StreamBufCnt = 8;
    ctx.u32ChNum        = 1;
    ctx.u32SrcPixFormat = RK_FMT_YUV420SP;
    ctx.u32DstCodec     = RK_VIDEO_ID_AVC;
    setting_default_argc(&ctx);

    mpi_venc_test_show_options(&ctx);
    
    s32Ret = bed_mpi_enc_init(&ctx);
    
    for (u32Ch = 0; u32Ch < ctx.u32ChNum; u32Ch++) {
        memcpy(&(stVencCtx[u32Ch]), &ctx, sizeof(Bedrock_VENC_CTX_S));
        pthread_create(&vencThread[u32Ch], 0, venc_send_frame, reinterpret_cast<void *>(&stVencCtx[u32Ch]));
        pthread_create(&getStreamThread[u32Ch], 0, venc_get_stream, reinterpret_cast<void *>(&stVencCtx[u32Ch]));
    }
    for (u32Ch = 0; u32Ch < ctx.u32ChNum; u32Ch++) {
        pthread_join(vencThread[u32Ch], RK_NULL);
        pthread_join(getStreamThread[u32Ch], RK_NULL);

        stVencCtx[u32Ch].threadExit = RK_TRUE;
        RK_MPI_VENC_StopRecvFrame(u32Ch);

        RK_MPI_VENC_DestroyChn(u32Ch);
        RK_MPI_MB_DestroyPool(stVencCtx[u32Ch].vencPool);
    }

    s32Ret = bed_mpi_enc_remove();
    return RK_SUCCESS;
__FAILED:
    RK_MPI_SYS_Exit();
    RK_LOGE("test running failed!");
    return s32Ret;
}
