set(BEDROCK_DEPENDENT_LIBS
    bedrock_lib
    bedrock_encoder
    bedrock_rtsp
)
set(RTSP_INCLUDE ${CMAKE_CURRENT_LIST_DIR}/../rtsp/src
                 ${CMAKE_CURRENT_LIST_DIR}/../rtsp/src/3rdpart
                 ${CMAKE_CURRENT_LIST_DIR}/../rtsp/src/net
                 ${CMAKE_CURRENT_LIST_DIR}/../rtsp/src/xop
                )

include_directories(${RTSP_INCLUDE})

add_executable(bedrock_test bedrock_test.cpp)

target_link_libraries(bedrock_test ${BEDROCK_DEPENDENT_LIBS})

install(TARGETS bedrock_test DESTINATION bin)