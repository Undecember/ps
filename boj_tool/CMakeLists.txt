cmake_minimum_required(VERSION 3.14)
project(BojTool VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_compile_options(-Ofast)

# myhtml
include(FetchContent)
FetchContent_Declare(
    myhtml
    GIT_REPOSITORY https://github.com/lexborisov/myhtml
    GIT_TAG        v4.0.5
)
FetchContent_MakeAvailable(myhtml)
include_directories(${myhtml_SOURCE_DIR}/include)

# curl
find_package(CURL REQUIRED)
if(CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "libcurl not found")
endif()

add_executable(boj main.cpp web.cpp)
target_compile_options(boj PRIVATE -std=c++20)
target_link_libraries(boj PRIVATE myhtml ${CURL_LIBRARIES})
