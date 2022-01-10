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

#ifndef INCLUDE_RT_MPI_MPI_ADEC_H_
#define INCLUDE_RT_MPI_MPI_ADEC_H_

#include "rk_common.h"
#include "rk_comm_adec.h"
#include "rk_comm_aio.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */


RK_S32 RK_MPI_ADEC_CreateChn(ADEC_CHN AdChn, const ADEC_CHN_ATTR_S *pstAttr);
RK_S32 RK_MPI_ADEC_DestroyChn(ADEC_CHN AdChn);
RK_S32 RK_MPI_ADEC_SendStream(ADEC_CHN AdChn, const AUDIO_STREAM_S *pstStream, RK_BOOL bBlock);
RK_S32 RK_MPI_ADEC_ClearChnBuf(ADEC_CHN AdChn);
RK_S32 RK_MPI_ADEC_GetFrame(ADEC_CHN AdChn, AUDIO_FRAME_INFO_S *pstFrmInfo, RK_BOOL bBlock);
RK_S32 RK_MPI_ADEC_ReleaseFrame(ADEC_CHN AdChn, AUDIO_FRAME_INFO_S *pstFrmInfo);
RK_S32 RK_MPI_ADEC_SendEndOfStream(ADEC_CHN AdChn, RK_BOOL bInstant);
RK_S32 RK_MPI_ADEC_QueryChnStat(ADEC_CHN AdChn, ADEC_CHN_STATE_S *pstBufferStatus);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif  /* End of INCLUDE_RT_MPI_MPI_ADEC_H_ */
