cmake_minimum_required(VERSION 3.10)
project(folderHelper)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.hpp")

add_executable(folderHelper ${SOURCES} ${HEADERS})

target_include_directories(folderHelper PRIVATE ${Vulkan_INCLUDE_DIRS})

target_link_libraries(folderHelper PRIVATE)
