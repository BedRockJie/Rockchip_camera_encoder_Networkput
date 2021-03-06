/*** 
 * @Description: 
 * @Version: 2.0
 * @Autor: Bedrock
 * @Date: 2021-12-28 19:48:06
 * @LastEditors: Bedrock
 * @LastEditTime: 2022-01-21 18:23:21
 * @Author: Bedrock
 * @FilePath: /bedrock_encoder/main.cpp
 * @版权声明
 */

#include <stdio.h>
#include <stdlib.h>
#include "bedrock_log.h"
#include "bedrock_control.h"
#include "bedrock_test.h"
#include "bedrock_enc.h"
#include "bedrock_rtsp.h"
/*
* main->
* 1. 初始化变量及内存
* 2. 调整打印等级
* 3. 
*/
int main(int argc, char const *argv[])
{
    /*初始化函数*/
    enable_minilog = 0;
    bedrock_app_log_level = LOG_ERROR;
    dlog_level_test();
    printf("Hello word!\n");
    adjust_log_level();
    dlog_level_test();
    bedrock_main(argc, argv);
    //bendrock_rtsp_test(argc,argv);
    return 0;
}
