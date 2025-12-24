cmake_minimum_required(VERSION 3.28)
project(BinarySearch LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++ -static") # i want this but it doesn't work HELP
set(CMAKE_CXX_STANDARD 23)

# optimizers
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -flto -ffast-math")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -static -static-libgcc -static-libstdc++")

# profiling
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -pg")

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_executable(BinarySearch ${SOURCES})
target_compile_features(BinarySearch PRIVATE cxx_std_23)
target_include_directories(BinarySearch PRIVATE ${CMAKE_SOURCE_DIR}/include)
if(WIN32)
    target_link_libraries(BinarySearch PRIVATE ws2_32)
endif()
