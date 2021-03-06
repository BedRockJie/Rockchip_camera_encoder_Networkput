/*** 
 * @Description: 
 * @Version: 2.0
 * @Autor: Bedrock
 * @Date: 2022-01-02 15:46:02
 * @LastEditors: Bedrock
 * @LastEditTime: 2022-01-21 20:00:20
 * @Author: Bedrock
 * @FilePath: /bedrock_encoder/encoder/inc/bedrock_enc.h
 * @版权声明
 */

#ifndef __BEDROCK_ENC_H__
#define __BEDROCK_ENC_H__

#include "rk_debug.h"
#include "rk_mpi_cal.h"
#include "rk_mpi_mb.h"
#include "rk_mpi_sys.h"
#include "rk_mpi_venc.h"

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

int bedrock_main(int argc, char const* argv[]);
RK_S32 mpi_enc_init(Bedrock_VENC_CTX_S *ctx);
RK_S32 mpi_enc_remove();
RK_S32 read_image(RK_U8 *pVirAddr, RK_U32 u32Width, RK_U32 u32Height,
                                  RK_U32 u32VirWidth, RK_U32 u32VirHeight, RK_U32 u32PixFormat, FILE *fp);
                                  
#endif // BEDROCK_ENC_H
