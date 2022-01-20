#
# add_library
#
set(RTSP_INCLUDE ${CMAKE_CURRENT_LIST_DIR}/src
                 ${CMAKE_CURRENT_LIST_DIR}/src/3rdpart
                 ${CMAKE_CURRENT_LIST_DIR}/src/net
                 ${CMAKE_CURRENT_LIST_DIR}/src/xop
                )

include_directories(${RTSP_INCLUDE})
include_directories(inc)


if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(RTSP_LIBS
        -lrt
        -lpthread
    )
    message(STATUS "Build WITH linker libs for Linux")
endif()
#静态库

file(GLOB_RECURSE net_src src/net/*.cpp)
file(GLOB_RECURSE xop_src src/xop/*.cpp)

add_library(bedrock_rtsp STATIC
                bedrock_rtsp.cpp
                ${net_src}
                ${xop_src}
            )

target_link_libraries(bedrock_rtsp ${RTSP_LIBS})