#
# add_library
#
include_directories(inc)
include_directories(${ROCKIT_INCLUDE})


add_subdirectory(src)

set(ROCKIT_DEP_COMMON_LIBS 
    ${CMAKE_CURRENT_LIST_DIR}/../lib/rockit/lib/librockit.so
    ${CMAKE_CURRENT_LIST_DIR}/../lib/libconfig/lib/libconfig.so)
    
if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(ROCKIT_DEP_COMMON_LIBS
        ${ROCKIT_DEP_COMMON_LIBS}
        -lpthread
    )
    message(STATUS "Build WITH linker libs for Linux")
endif()
#静态库
add_library(bedrock_encoder STATIC
            bedrock_mpi_enc.cpp
            ${RK_MPI_BEDROCK_COMMON_SRC}
            )


target_link_libraries(bedrock_encoder ${ROCKIT_DEP_COMMON_LIBS})