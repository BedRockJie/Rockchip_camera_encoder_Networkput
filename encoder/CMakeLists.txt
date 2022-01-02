#
# add_library
#
include(FindPkgConfig)
pkg_check_modules(ROCKCHIP_MPP REQUIRED rockchip_mpp)
include_directories(inc)

message(STATUS   ${ROCKCHIP_MPP})

#静态库
add_library(bedrock_encoder STATIC
            bedrock_mpi_enc.c
            )


target_link_libraries(bedrock_encoder ROCKCHIP_MPP)