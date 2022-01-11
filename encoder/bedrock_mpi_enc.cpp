/*** 
 * @Description: 
 * @Version: 2.0
 * @Autor: Bedrock
 * @Date: 2022-01-01 14:42:00
 * @LastEditors: Bedrock
 * @LastEditTime: 2022-01-10 22:42:07
 * @Author: Bedrock
 * @FilePath: /bedrock_encoder/encoder/bedrock_mpi_enc.cpp
 * @版权声明
 */

#include <cstdio>
#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "rk_debug.h"
#include "rk_mpi_sys.h"
#include "rk_mpi_mb.h"
#include "rk_mpi_venc.h"
#include "rk_mpi_cal.h"
#include "argparse.h"
#include "mpi_test_utils.h"

#include "bedrock_enc.h"

#define LOG_TAG "bedrock_enc_lib"


#define MAX_TIME_OUT_ME 20
#define TEST_RC_MODE 0

typedef struct _rkMpiVENCCtx {
    const char     *srcFileUri;
    const char     *dstFilePath;
    RK_U32          u32SrcWidth;
    RK_U32          u32SrcHeight;
    RK_U32          u32srcVirWidth;
    RK_U32          u32srcVirHeight;
    RK_S32          s32LoopCount;
    RK_U32          u32ChnIndex;
    RK_U32          u32ChNum;
    RK_U32          u32SrcPixFormat;
    RK_U32          u32DstCodec;
    RK_U32          u32BufferSize;
    RK_U32          u32StreamBufCnt;
    RK_BOOL         threadExit;
    MB_POOL         vencPool;
} Bedrock_VENC_CTX_S;

int main(int argc, char const *argv[])
{
    RK_S32 s32Ret = RK_SUCCESS;
    Bedrock_VENC_CTX_S ctx;
    memset(&ctx, 0, sizeof(Bedrock_VENC_CTX_S));

    ctx.s32LoopCount = 1;
    ctx.u32StreamBufCnt = 8;
    ctx.u32ChNum = 1;
    ctx.u32SrcPixFormat = RK_FMT_YUV420SP;
    ctx.u32DstCodec = RK_VIDEO_ID_AVC;
    
    return 0;
}
