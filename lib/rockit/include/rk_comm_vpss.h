/*
 * Copyright 2020 Rockchip Electronics Co. LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef INCLUDE_RT_MPI_RK_COMMON_VPSS_H_
#define INCLUDE_RT_MPI_RK_COMMON_VPSS_H_


#include "rk_type.h"
#include "rk_common.h"
#include "rk_errno.h"
#include "rk_comm_video.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

#define RK_VPSS_OK                   RK_SUCCESS
#define RK_ERR_VPSS_NULL_PTR         RK_DEF_ERR(RK_ID_VPSS, RK_ERR_LEVEL_ERROR, RK_ERR_NULL_PTR)
#define RK_ERR_VPSS_NOTREADY         RK_DEF_ERR(RK_ID_VPSS, RK_ERR_LEVEL_ERROR, RK_ERR_SYS_NOTREADY)
#define RK_ERR_VPSS_INVALID_DEVID    RK_DEF_ERR(RK_ID_VPSS, RK_ERR_LEVEL_ERROR, RK_ERR_INVALID_DEVID)
#define RK_ERR_VPSS_INVALID_CHNID    RK_DEF_ERR(RK_ID_VPSS, RK_ERR_LEVEL_ERROR, RK_ERR_INVALID_CHNID)
#define RK_ERR_VPSS_EXIST            RK_DEF_ERR(RK_ID_VPSS, RK_ERR_LEVEL_ERROR, RK_ERR_EXIST)
#define RK_ERR_VPSS_UNEXIST          RK_DEF_ERR(RK_ID_VPSS, RK_ERR_LEVEL_ERROR, RK_ERR_UNEXIST)
#define RK_ERR_VPSS_NOT_SUPPORT      RK_DEF_ERR(RK_ID_VPSS, RK_ERR_LEVEL_ERROR, RK_ERR_NOT_SUPPORT)
#define RK_ERR_VPSS_NOT_PERM         RK_DEF_ERR(RK_ID_VPSS, RK_ERR_LEVEL_ERROR, RK_ERR_NOT_PERM)
#define RK_ERR_VPSS_NOMEM            RK_DEF_ERR(RK_ID_VPSS, RK_ERR_LEVEL_ERROR, RK_ERR_NOMEM)
#define RK_ERR_VPSS_NOBUF            RK_DEF_ERR(RK_ID_VPSS, RK_ERR_LEVEL_ERROR, RK_ERR_NOBUF)
#define RK_ERR_VPSS_SIZE_NOT_ENOUGH  RK_DEF_ERR(RK_ID_VPSS, RK_ERR_LEVEL_ERROR, RK_ERR_SIZE_NOT_ENOUGH)
#define RK_ERR_VPSS_ILLEGAL_PARAM    RK_DEF_ERR(RK_ID_VPSS, RK_ERR_LEVEL_ERROR, RK_ERR_ILLEGAL_PARAM)
#define RK_ERR_VPSS_BUSY             RK_DEF_ERR(RK_ID_VPSS, RK_ERR_LEVEL_ERROR, RK_ERR_BUSY)
#define RK_ERR_VPSS_BUF_EMPTY        RK_DEF_ERR(RK_ID_VPSS, RK_ERR_LEVEL_ERROR, RK_ERR_BUF_EMPTY)
#define RK_ERR_VPSS_BUF_FULL         RK_DEF_ERR(RK_ID_VPSS, RK_ERR_LEVEL_ERROR, RK_ERR_BUF_FULL)

#define VPSS_INVALID_FRMRATE         -1
#define VPSS_CHN0                    0
#define VPSS_CHN1                    1
#define VPSS_CHN2                    2
#define VPSS_CHN3                    3
#define VPSS_INVALID_CHN             -1

typedef struct rkVPSS_GRP_ATTR_S {
    RK_U32                     u32MaxW;           /* RW; Range: [64, 16384]; Width of source image. */
    RK_U32                     u32MaxH;           /* RW; Range: [64, 16384]; Height of source image. */
    PIXEL_FORMAT_E             enPixelFormat;     /* RW; Pixel format of source image. */
    DYNAMIC_RANGE_E            enDynamicRange;    /* RW; DynamicRange of source image. */
    FRAME_RATE_CTRL_S          stFrameRate;       /* Grp frame rate contrl. */
    COMPRESS_MODE_E            enCompressMode;    /* RW; Reference frame compress mode */
} VPSS_GRP_ATTR_S;

typedef enum rkVPSS_CHN_MODE_E {
    VPSS_CHN_MODE_USER  = 0,       /* User mode. */
    VPSS_CHN_MODE_AUTO  = 1,       /* Auto mode. */
    VPSS_CHN_MODE_PASSTHROUGH = 2, /* Pass through mode */
    VPSS_CHN_MODE_BUTT
} VPSS_CHN_MODE_E;

typedef struct rkVPSS_CHN_ATTR_S {
    VPSS_CHN_MODE_E     enChnMode;          /* RW; Vpss channel's work mode. */
    RK_U32              u32Width;           /* RW; Range: [64, 16384]; Width of target image. */
    RK_U32              u32Height;          /* RW; Range: [64, 16384]; Height of target image. */
    VIDEO_FORMAT_E      enVideoFormat;      /* RW; Video format of target image. */
    PIXEL_FORMAT_E      enPixelFormat;      /* RW; Pixel format of target image. */
    DYNAMIC_RANGE_E     enDynamicRange;     /* RW; DynamicRange of target image. */
    COMPRESS_MODE_E     enCompressMode;     /* RW; Compression mode of the output. */
    FRAME_RATE_CTRL_S   stFrameRate;        /* Frame rate control info */
    RK_BOOL             bMirror;            /* RW; Mirror enable. */
    RK_BOOL             bFlip;              /* RW; Flip enable. */
    RK_U32              u32Depth;           /* RW; Range: [0, 8]; User get list depth. */
    ASPECT_RATIO_S      stAspectRatio;      /* Aspect Ratio info. */
} VPSS_CHN_ATTR_S;

typedef enum rkVPSS_CROP_COORDINATE_E {
    VPSS_CROP_RATIO_COOR = 0,   /* Ratio coordinate. */
    VPSS_CROP_ABS_COOR          /* Absolute coordinate. */
} VPSS_CROP_COORDINATE_E;

typedef struct rkVPSS_CROP_INFO_S {
    RK_BOOL                 bEnable;            /* RW; Range: [0, 1];  CROP enable. */
    VPSS_CROP_COORDINATE_E  enCropCoordinate;   /* RW; Range: [0, 1]; Coordinate mode of the crop start point. */
    RECT_S                  stCropRect;         /* CROP rectangular. */
} VPSS_CROP_INFO_S;

typedef struct rkVPSS_ROTATION_EX_ATTR_S {
    RK_BOOL       bEnable;                      /* Whether ROTATE_EX_S is enbale */
    ROTATION_EX_S stRotationEx;                 /* Rotate Attribute */
} VPSS_ROTATION_EX_ATTR_S;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* INCLUDE_RT_MPI_RK_COMMON_VPSS_H_ */


