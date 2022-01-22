/*** 
 * @Description: 接口功能测试程序
 * @Version: 2.0
 * @Autor: Bedrock
 * @Date: 2022-01-21 16:38:50
 * @LastEditors: Bedrock
 * @LastEditTime: 2022-01-21 18:42:47
 * @Author: Bedrock
 * @FilePath: /bedrock_encoder/test/bedrock_test.cpp
 * @版权声明
 */

#include <cstring>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include "bedrock_rtsp.h"
#include "bedrock_enc.h"
#include "xop/RtspServer.h"
#include "net/Timer.h"
#include "pthread.h"

void* bedrock_venc_send_frame(void *pArgs) {
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
void* bedrock_venc_get_stream(void *pArgs) {
    Bedrock_VENC_CTX_S *pstCtx     = reinterpret_cast<Bedrock_VENC_CTX_S *>(pArgs);
    void            *pData      = RK_NULL;
    RK_S32           s32Ret     = RK_SUCCESS;
    FILE            *fp         = RK_NULL;
    char             name[256]  = {0};
    RK_U32           u32Ch      = pstCtx->u32ChnIndex;
    RK_S32           s32StreamCnt = 0;
    VENC_STREAM_S    stFrame;

    std::string suffix = "live";
	std::string ip = "192.168.0.108";
	std::string port = "554";
	std::string rtsp_url = "rtsp://" + ip + ":" + port + "/" + suffix;
	
	// std::shared_ptr<xop::EventLoop> event_loop(new xop::EventLoop());
	// std::shared_ptr<xop::RtspServer> server = xop::RtspServer::Create(event_loop.get());

	// if (!server->Start("0.0.0.0", atoi(port.c_str()))) {
	// 	printf("RTSP Server listen on %s failed.\n", port.c_str());
	// 	return 0;
	// }
	// xop::MediaSession *session = xop::MediaSession::CreateNew("live"); 
	// session->AddSource(xop::channel_0, xop::H264Source::CreateNew()); 
	// //session->StartMulticast(); 
	// session->AddNotifyConnectedCallback([] (xop::MediaSessionId sessionId, std::string peer_ip, uint16_t peer_port){
	// 	printf("RTSP client connect, ip=%s, port=%hu \n", peer_ip.c_str(), peer_port);
	// });
   
	// session->AddNotifyDisconnectedCallback([](xop::MediaSessionId sessionId, std::string peer_ip, uint16_t peer_port) {
	// 	printf("RTSP client disconnect, ip=%s, port=%hu \n", peer_ip.c_str(), peer_port);
	// });

	// xop::MediaSessionId session_id = server->AddSession(session);
	
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
                // xop::AVFrame videoFrame = {0};
                // videoFrame.type = 0; 
                // videoFrame.size = stFrame.pstPack->u32Len;
                // videoFrame.timestamp = xop::H264Source::GetTimestamp();
                // videoFrame.buffer.reset(new uint8_t[videoFrame.size]); 
                // memcpy(videoFrame.buffer.get(), pData, videoFrame.size);
                // server->PushFrame(session_id, xop::channel_0, videoFrame);
                
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
int main(int argc, char const *argv[])
{
    RK_U32                  u32Ch = 0;
    Bedrock_VENC_CTX_S      stVencCtx[VENC_MAX_CHN_NUM];
    pthread_t               vencThread[VENC_MAX_CHN_NUM];
    pthread_t               getStreamThread[VENC_MAX_CHN_NUM];
    std::cout << "Hello world" << std::endl;
    Bedrock_VENC_CTX_S ctx;
    memset(&ctx, 0, sizeof(Bedrock_VENC_CTX_S));
    RK_S32 ret = RK_SUCCESS;
    ret = mpi_enc_init(&ctx);
    if (ret != RK_SUCCESS) {
        std::cout << "mpi init faild" << std::endl;
        goto __FAILD;
    }
    memcpy(&(stVencCtx[u32Ch]), &ctx, sizeof(Bedrock_VENC_CTX_S));
    pthread_create(&vencThread[u32Ch], 0, bedrock_venc_send_frame, reinterpret_cast<void *>(&stVencCtx[u32Ch]));
    pthread_create(&getStreamThread[u32Ch], 0, bedrock_venc_get_stream, reinterpret_cast<void *>(&stVencCtx[u32Ch]));
    for (u32Ch = 0; u32Ch < ctx.u32ChNum; u32Ch++) {
        pthread_join(vencThread[u32Ch], RK_NULL);
        pthread_join(getStreamThread[u32Ch], RK_NULL);

        stVencCtx[u32Ch].threadExit = RK_TRUE;
        RK_MPI_VENC_StopRecvFrame(u32Ch);

        RK_MPI_VENC_DestroyChn(u32Ch);
        RK_MPI_MB_DestroyPool(stVencCtx[u32Ch].vencPool);
    }

    return RK_SUCCESS;

__FAILD:
    ret = mpi_enc_remove();
    return 0;
}
