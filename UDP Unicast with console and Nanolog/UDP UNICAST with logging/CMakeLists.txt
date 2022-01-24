#### ------ COMPILING OPTIONS ----- ####
# RELEASE for client delivery: cmake -DCMAKE_BUILD_TYPE=Release ..
# DEBUG for dev debugging : cmake -DCMAKE_BUILD_TYPE=Debug ..
# RELEASE with DEBUG Symbols for profiling  : cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo ..
#### ------ COMPILING OPTIONS ----- ####
cmake_minimum_required(VERSION 2.8)


project (NSE_BROADCAST_CM)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O1")
#set(CMAKE_CXX_STANDARD 11)
add_compile_options(-std=c++11)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_DIR ${CMAKE_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_LIBRARY_DIR})

set(CMAKE_CXX_STANDARD 11)

#add_executable (NSE_TBT "cmake_testing.cpp" "cmake_testing.h" "src/Adapter.h" "src/Adapter.cpp")
add_executable (udpUnicast "main.cpp" "Nanolog.cpp" )


target_link_libraries( udpUnicast
-lpthread
)


