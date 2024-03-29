cmake_minimum_required(VERSION 3.1.0)
set(CMAKE_CXX_STANDARD 11)

project(Bedrock_encoder)

include_directories(inc)
include_directories(encoder/inc)
include_directories(rtsp/inc)

set(ROCKIT_INCLUDE ${CMAKE_CURRENT_LIST_DIR}/lib/rockit/include
                   ${CMAKE_CURRENT_LIST_DIR}/lib/libconfig/include                
)

include_directories(${ROCKIT_INCLUDE})

add_subdirectory(encoder)
add_subdirectory(rtsp)
add_subdirectory(test)

set(LIB_SOURCE
    control/bedrock_control.c
    test/debug_log_test.c)
# 生成动态库
add_library(bedrock_lib SHARED ${LIB_SOURCE})

set(BEDROCK_DEPENDENT_LIBS
    bedrock_lib
    bedrock_encoder
    bedrock_rtsp
)

set(SOURCES main.cpp)


add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${BEDROCK_DEPENDENT_LIBS})



install(TARGETS Bedrock_encoder DESTINATION bin)
install(TARGETS bedrock_lib DESTINATION lib)
install(FILES ./test/bedrock_mpi.cfg DESTINATION bin)
# install(FILES ./inc/bedrock_control.h DESTINATION include)
# install(DIRECTORY ./inc DESTINATION include FILES_MATCHING PATTERN "*.h")
