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

#ifndef INCLUDE_RT_MPI_RK_MPI_VPSS_H_
#define INCLUDE_RT_MPI_RK_MPI_VPSS_H_

#include "rk_common.h"
#include "rk_comm_video.h"
#include "rk_comm_mb.h"
#include "rk_comm_vpss.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/* Group Settings */
RK_S32 RK_MPI_VPSS_CreateGrp(VPSS_GRP VpssGrp, const VPSS_GRP_ATTR_S *pstGrpAttr);
RK_S32 RK_MPI_VPSS_DestroyGrp(VPSS_GRP VpssGrp);

RK_S32 RK_MPI_VPSS_StartGrp(VPSS_GRP VpssGrp);
RK_S32 RK_MPI_VPSS_StopGrp(VPSS_GRP VpssGrp);

RK_S32 RK_MPI_VPSS_ResetGrp(VPSS_GRP VpssGrp);

RK_S32 RK_MPI_VPSS_GetGrpAttr(VPSS_GRP VpssGrp, VPSS_GRP_ATTR_S *pstGrpAttr);
RK_S32 RK_MPI_VPSS_SetGrpAttr(VPSS_GRP VpssGrp, const VPSS_GRP_ATTR_S *pstGrpAttr);

RK_S32 RK_MPI_VPSS_SetGrpCrop(VPSS_GRP VpssGrp, const VPSS_CROP_INFO_S *pstCropInfo);
RK_S32 RK_MPI_VPSS_GetGrpCrop(VPSS_GRP VpssGrp, VPSS_CROP_INFO_S *pstCropInfo);

RK_S32 RK_MPI_VPSS_SendFrame(VPSS_GRP VpssGrp, VPSS_GRP_PIPE VpssGrpPipe,
                                      const VIDEO_FRAME_INFO_S *pstVideoFrame, RK_S32 s32MilliSec);

RK_S32 RK_MPI_VPSS_GetGrpFrame(VPSS_GRP VpssGrp, VPSS_GRP_PIPE VpssGrpPipe,
                                         VIDEO_FRAME_INFO_S *pstVideoFrame);
RK_S32 RK_MPI_VPSS_ReleaseGrpFrame(VPSS_GRP VpssGrp, VPSS_GRP_PIPE VpssGrpPipe,
                                               const VIDEO_FRAME_INFO_S *pstVideoFrame);

RK_S32 RK_MPI_VPSS_EnableBackupFrame(VPSS_GRP VpssGrp);
RK_S32 RK_MPI_VPSS_DisableBackupFrame(VPSS_GRP VpssGrp);

RK_S32 RK_MPI_VPSS_SetGrpDelay(VPSS_GRP VpssGrp, RK_U32 u32Delay);
RK_S32 RK_MPI_VPSS_GetGrpDelay(VPSS_GRP VpssGrp, RK_U32 *pu32Delay);

RK_S32 RK_MPI_VPSS_EnableUserFrameRateCtrl(VPSS_GRP VpssGrp);
RK_S32 RK_MPI_VPSS_DisableUserFrameRateCtrl(VPSS_GRP VpssGrp);

/* Chn Settings */
RK_S32 RK_MPI_VPSS_SetChnAttr(VPSS_GRP VpssGrp, VPSS_CHN VpssChn, const VPSS_CHN_ATTR_S *pstChnAttr);
RK_S32 RK_MPI_VPSS_GetChnAttr(VPSS_GRP VpssGrp, VPSS_CHN VpssChn, VPSS_CHN_ATTR_S *pstChnAttr);

RK_S32 RK_MPI_VPSS_EnableChn(VPSS_GRP VpssGrp, VPSS_CHN VpssChn);
RK_S32 RK_MPI_VPSS_DisableChn(VPSS_GRP VpssGrp, VPSS_CHN VpssChn);

RK_S32 RK_MPI_VPSS_SetChnCrop(VPSS_GRP VpssGrp, VPSS_CHN VpssChn, const VPSS_CROP_INFO_S *pstCropInfo);
RK_S32 RK_MPI_VPSS_GetChnCrop(VPSS_GRP VpssGrp, VPSS_CHN VpssChn, VPSS_CROP_INFO_S *pstCropInfo);

RK_S32 RK_MPI_VPSS_SetChnRotation(VPSS_GRP VpssGrp, VPSS_CHN VpssChn, ROTATION_E enRotation);
RK_S32 RK_MPI_VPSS_GetChnRotation(VPSS_GRP VpssGrp, VPSS_CHN VpssChn, ROTATION_E *penRotation);

RK_S32 RK_MPI_VPSS_SetChnRotationEx(VPSS_GRP VpssGrp, VPSS_CHN VpssChn,
            const VPSS_ROTATION_EX_ATTR_S* pstRotationExAttr);
RK_S32 RK_MPI_VPSS_GetChnRotationEx(VPSS_GRP VpssGrp, VPSS_CHN VpssChn,
            VPSS_ROTATION_EX_ATTR_S* pstRotationExAttr);

RK_S32 RK_MPI_VPSS_GetChnFrame(
            VPSS_GRP VpssGrp, VPSS_CHN VpssChn, VIDEO_FRAME_INFO_S *pstVideoFrame, RK_S32 s32MilliSec);
RK_S32 RK_MPI_VPSS_ReleaseChnFrame(VPSS_GRP VpssGrp, VPSS_CHN VpssChn, const VIDEO_FRAME_INFO_S *pstVideoFrame);

RK_S32 RK_MPI_VPSS_GetRegionLuma(VPSS_GRP VpssGrp, VPSS_CHN VpssChn, const VIDEO_REGION_INFO_S *pstRegionInfo,
                                 RK_U64 *pu64LumaData, RK_S32 s32MilliSec);

RK_S32 RK_MPI_VPSS_AttachMbPool(VPSS_GRP VpssGrp, VPSS_CHN VpssChn, MB_POOL hVbPool);
RK_S32 RK_MPI_VPSS_DetachMbPool(VPSS_GRP VpssGrp, VPSS_CHN VpssChn);

RK_S32 RK_MPI_VPSS_EnableBufferShare(VPSS_GRP VpssGrp, VPSS_CHN VpssChn);
RK_S32 RK_MPI_VPSS_DisableBufferShare(VPSS_GRP VpssGrp, VPSS_CHN VpssChn);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* INCLUDE_RT_MPI_RK_MPI_VPSS_H_ */


