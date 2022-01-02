/*
 * @Description: 
 * @Version: 2.0
 * @Autor: Bedrock
 * @Date: 2021-12-30 21:29:27
 * @LastEditors: Bedrock
 * @LastEditTime: 2022-01-01 10:48:26
 */

#ifndef __BEDROCK_CONTROL_H_
#define __BEDROCK_CONTROL_H_

#define BEDROCK_DEBUG_LOG "/tmp/bedrock/bedrock_debug_log.log"


extern int enable_minilog;
extern int bedrock_app_log_level;

enum {
  LOG_ERROR,
  LOG_WARN,
  LOG_INFO,
  LOG_DEBUG
};

#endif /*__BEDROCK_CONTROL_H*/
