#
# add_library
#
include_directories(inc)
include_directories(${ROCKIT_INCLUDE})


set(ROCKIT_DEP_COMMON_LIBS 
    ${CMAKE_CURRENT_LIST_DIR}/../lib/rockit/lib/librockit.so)

#静态库
add_library(bedrock_encoder STATIC
            bedrock_mpi_enc.cpp
            )


target_link_libraries(bedrock_encoder ROCKIT_DEP_COMMON_LIBS)