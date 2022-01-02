cmake_minimum_required(VERSION 3.1.0)
set(CMAKE_CXX_STANDARD 11)

project(Bedrock_encoder)

include_directories(inc)
include_directories(encoder/inc)

add_subdirectory(encoder)

set(LIB_SOURCE
    control/bedrock_control.c
    test/debug_log_test.c)
# 生成动态库
add_library(bedrock_lib SHARED ${LIB_SOURCE})

set(BEDROCK_DEPENDENT_LIBS
    bedrock_lib)

set(SOURCES main.c)


add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${BEDROCK_DEPENDENT_LIBS})



install(TARGETS Bedrock_encoder DESTINATION bin)
install(TARGETS bedrock_lib DESTINATION lib)
#install(FILES ./inc/bedrock_control.h DESTINATION include)
install(DIRECTORY ./inc DESTINATION include FILES_MATCHING PATTERN "*.h")
