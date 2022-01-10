/*** 
 * @Description: 
 * @Version: 2.0
 * @Autor: Bedrock
 * @Date: 2022-01-10 18:01:58
 * @LastEditors: Bedrock
 * @LastEditTime: 2022-01-10 18:07:27
 * @Author: Bedrock
 * @FilePath: /bedrock_encoder/inc/bedrock_control.h
 * @版权声明
 */
#ifndef __BEDROCK_CONTROL_H__
#define __BEDROCK_CONTROL_H__

extern int enable_minilog;
extern int bedrock_app_log_level;

#define BEDROCK_DEBUG_LOG "/tmp/bedrock_log_debug"

enum {
  LOG_ERROR,
  LOG_WARN,
  LOG_INFO,
  LOG_DEBUG
};

#endif // BEDROCK_CONTROL_H