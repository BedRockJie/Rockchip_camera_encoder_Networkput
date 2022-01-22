/*** 
 * @Description: 
 * @Version: 2.0
 * @Autor: Bedrock
 * @Date: 2022-01-21 19:51:51
 * @LastEditors: Bedrock
 * @LastEditTime: 2022-01-22 17:27:07
 * @Author: Bedrock
 * @FilePath: /bedrock_encoder/test/bedrock_cfgf_test.cpp
 * @版权声明
 */

#include <cstring>
#include "filecfg.h"
#include "bedrock_enc.h"

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

int main(int argc, char const *argv[])
{
    RK_S32 ret = RK_SUCCESS;
    Bedrock_VENC_CTX_S ctx;
    const char *file = NULL;
    memset(&ctx, 0, sizeof(Bedrock_VENC_CTX_S));
    ret = init_argc_for_cfg(&ctx, file);
    mpi_venc_test_show_options(&ctx);
    return 0;
}
