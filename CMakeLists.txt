cmake_minimum_required(VERSION 3.1)


project(CW2)

set(CW2_SRC main.cpp CIntN.cpp At.cpp CW2.cpp)
set(CW2_HDR  CIntN.h )

#add_library(vector STATIC ${VECTOR_SRC} ${VECTOR_HDR})

add_executable(${PROJECT_NAME} ${CW2_SRC} ${CW2_HDR})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 /std:c++14")
