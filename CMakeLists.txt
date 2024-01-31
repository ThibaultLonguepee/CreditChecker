cmake_minimum_required(VERSION 3.5)

project(rtype)

set(CMAKE_CXX_STANDARD 23)

set(SFML_STATIC TRUE)
set(BUILD_SHARED_LIBS FALSE)
add_subdirectory(SFML)

include_directories(SFML/include)
include_directories(snappy)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

file(GLOB_RECURSE SOURCES
    "src/*.hpp"
    "src/*.cpp"
)

foreach(file ${SOURCES})
    set(MYFILE_DIR)
    # print the file name
    message(STATUS "Found file: ${file}")
    if(file MATCHES ".*.hpp")
        get_filename_component(MYFILE_DIR ${file} DIRECTORY)
        include_directories(${MYFILE_DIR})
    endif()
endforeach()

add_executable(creditschecker ${SOURCES})

target_link_libraries(creditschecker sfml-graphics sfml-window sfml-system sfml-network sfml-audio)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    message(STATUS "Debug mode for creditschecker")
    target_compile_definitions(creditschecker PUBLIC DEBUG)
endif()

