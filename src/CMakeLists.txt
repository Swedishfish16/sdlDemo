# CMakeList.txt : CMake project for sdlDemo, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (sdlDemo "main.cpp")

cmake_minimum_required(VERSION 3.20.2)

project(sdlDemo)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# SDL2 configuration
if(WIN32)
    set(SDL2_DIR "C:/LinkerFiles/SDL2-2.30.5")
    # Find the SDL2 package
    find_package(SDL2 REQUIRED)
    #include_directories(${SDL2_INCLUDE_DIRS})
    # Link SDL2 libraries
    target_link_libraries(sdlDemo SDL2::SDL2 SDL2::SDL2main)

elseif(UNIX)
    set(SourceFiles main.cpp)
    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
    Target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
endif()


# TODO: Add tests and install targets if needed.
