cmake_minimum_required( VERSION 3.1.0 )

add_definitions(-fno-rtti)

add_compile_options(-std=c++11)

add_definitions(-std=c++11 -Wno-attributes -Wno-deprecated-declarations -DANDROID_STL=c++_shared)


set(RK_MPI_BEDROCK_COMMON_SRC
    ${CMAKE_CURRENT_LIST_DIR}/
    )