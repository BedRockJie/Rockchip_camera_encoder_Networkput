/*** 
 * @Description: 
 * @Version: 2.0
 * @Autor: Bedrock
 * @Date: 2022-01-01 09:57:51
 * @LastEditors: Bedrock
 * @LastEditTime: 2022-01-01 11:26:23
 * @Author: Bedrock
 * @FilePath: /bedrock_encoder/test/debug_log_test.c
 * @版权声明
 */

#include "bedrock_control.h"
#include "bedrock_log.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*** 
 * @description: 
 * @param {*}
 * @return {*}
 * @author: Bedrock
 * @use: 打印等级测试
 */
void dlog_level_test()
{
    LOG_ERROR("0Main Start\n");
    LOG_WARN("1Main Start\n");
    LOG_INFO("2Main Start\n");
    LOG_DEBUG("3Main Start\n");
}
/*** 
 * @description: 
 * @param {*}
 * @return {*}
 * @author: Bedrock
 * @use: log打印等级调整
 */
extern int bedrock_app_log_level;
void adjust_log_level()
{
    if (!access(BEDROCK_DEBUG_LOG, 0))
    {
        bedrock_app_log_level = LOG_DEBUG;
    }
    char *log_level = getenv("bedrock_app_log_level");
    if (log_level)
    {
        LOG_INFO("bedrock_app_log=%d", atoi(log_level));
        bedrock_app_log_level = atoi(log_level);
    }
}