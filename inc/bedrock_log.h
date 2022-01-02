#ifndef __BEDROCK_LOG_H__
#define __BEDROCK_LOG_H__

#ifdef ENABLE_MINILOGGER
#include "minilogger/log.h"
#else
#define minilog_warn(...)
#define minilog_error(...)
#define minilog_info(...)
#define minilog_debug(...)
#define __minilog_log_init(...)
#endif

extern int enable_minilog;
extern int bedrock_app_log_level;

#define LOG_LEVEL_ERROR 0
#define LOG_LEVEL_WARN 1
#define LOG_LEVEL_INFO 2
#define LOG_LEVEL_DEBUG 3

#ifndef LOG_TAG
#define LOG_TAG "bedrock_app"
#endif // LOG_TAG

//#define ENABLE_BUFFER_TIME_DEBUG

#define LOG_INFO(format, ...)                                                  \
  do {                                                                         \
    if (bedrock_app_log_level < LOG_LEVEL_INFO)                                \
      break;                                                                   \
    if (enable_minilog)                                                        \
      minilog_info("[%s][%s][INFO]:" format, LOG_TAG, __FUNCTION__, ##__VA_ARGS__);  \
    else                                                                       \
      fprintf(stderr, "[%s][%s][INFO]:" format, LOG_TAG, __FUNCTION__,               \
              ##__VA_ARGS__);                                                  \
  } while (0)

#define LOG_WARN(format, ...)                                                  \
  do {                                                                         \
    if (bedrock_app_log_level < LOG_LEVEL_WARN)                                \
      break;                                                                   \
    if (enable_minilog)                                                        \
      minilog_warn("[%s][%s][WARN]:" format, LOG_TAG, __FUNCTION__, ##__VA_ARGS__);  \
    else                                                                       \
      fprintf(stderr, "[%s][%s][WARN]:" format, LOG_TAG, __FUNCTION__,               \
              ##__VA_ARGS__);                                                  \
  } while (0)

#define LOG_ERROR(format, ...)                                                 \
  do {                                                                         \
    if (bedrock_app_log_level < LOG_LEVEL_ERROR)                               \
      break;                                                                   \
    if (enable_minilog)                                                        \
      minilog_error("[%s][%s][ERROR]:" format, LOG_TAG, __FUNCTION__, ##__VA_ARGS__); \
    else                                                                       \
      fprintf(stderr, "[%s][%s][ERROR]:" format, LOG_TAG, __FUNCTION__,               \
              ##__VA_ARGS__);                                                  \
  } while (0)

#define LOG_DEBUG(format, ...)                                                 \
  do {                                                                         \
    if (bedrock_app_log_level < LOG_LEVEL_DEBUG)                               \
      break;                                                                   \
    if (enable_minilog)                                                        \
      minilog_debug("[%s][%s][DEBUG]:" format, LOG_TAG, __FUNCTION__, ##__VA_ARGS__); \
    else                                                                       \
      fprintf(stderr, "[%s][%s][DEBUG]:" format, LOG_TAG, __FUNCTION__,               \
              ##__VA_ARGS__);                                                  \
  } while (0)

#endif
