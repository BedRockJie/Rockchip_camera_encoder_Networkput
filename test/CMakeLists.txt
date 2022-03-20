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
add_executable(bedrock_cfg_test bedrock_cfgf_test.cpp)
add_executable(bedrock_mpi_vi_test bedrock_mpi_vi_test.cpp)

target_link_libraries(bedrock_test ${BEDROCK_DEPENDENT_LIBS})
target_link_libraries(bedrock_cfg_test ${BEDROCK_DEPENDENT_LIBS})
target_link_libraries(bedrock_mpi_vi_test ${BEDROCK_DEPENDENT_LIBS})

install(TARGETS bedrock_test DESTINATION bin)
install(TARGETS bedrock_cfg_test DESTINATION bin)
install(TARGETS bedrock_mpi_vi_test DESTINATION bin)