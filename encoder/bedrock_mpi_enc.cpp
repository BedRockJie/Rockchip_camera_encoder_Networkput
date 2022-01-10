/*** 
 * @Description: 
 * @Version: 2.0
 * @Autor: Bedrock
 * @Date: 2022-01-01 14:42:00
 * @LastEditors: Bedrock
 * @LastEditTime: 2022-01-10 21:16:07
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


