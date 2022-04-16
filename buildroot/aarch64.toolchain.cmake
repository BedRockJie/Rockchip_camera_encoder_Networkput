set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

if(DEFINED ENV{aarch64_TOOLCHAIN_ROOT_PATH})
    file(TO_CMAKE_PATH $ENV{aarch64_TOOLCHAIN_ROOT_PATH} TOOLCHAIN_ROOT_PATH)
else()
    message(FATAL_ERROR "aarch64_TOOLCHAIN_ROOT_PATH env must be defined")
endif()


set(CMAKE_C_COMPILER "${TOOLCHAIN_ROOT_PATH}/bin/aarch64-buildroot-linux-gnu-gcc")
set(CMAKE_CXX_COMPILER "${TOOLCHAIN_ROOT_PATH}/bin/aarch64-buildroot-linux-gnu-g++")

set(CMAKE_TOOLCHAIN_FILE "${TOOLCHAIN_ROOT_PATH}")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

#set(CMAKE_C_FLAGS "-march=rv64gcvxtheadc -mabi=lp64d -mtune=c906 -DRVV_SPEC_0_7 -D__riscv_zfh=1 -static -lm")
#set(CMAKE_CXX_FLAGS "-march=rv64gcvxtheadc -mabi=lp64d -mtune=c906 -DRVV_SPEC_0_7 -D__riscv_zfh=1 -static")

# cache flags
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}" CACHE STRING "c flags")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" CACHE STRING "c++ flags")

# export RISCV_ROOT_PATH=/home/nihui/osd/riscv64-linux-x86_64-20210512
# cmake -DCMAKE_TOOLCHAIN_FILE=../toolchains/c906.toolchain.cmake -DCMAKE_BUILD_TYPE=relwithdebinfo -DNCNN_BUILD_TESTS=ON -DNCNN_OPENMP=OFF -DNCNN_THREADS=OFF -DNCNN_RUNTIME_CPU=OFF -DNCNN_RVV=ON -DNCNN_SIMPLEOCV=ON -DNCNN_BUILD_EXAMPLES=ON ..
