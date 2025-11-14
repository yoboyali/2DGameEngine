cmake_minimum_required(VERSION 3.10)
project(2DGameEngine_ CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Path to your local raylib folder (adjust if needed)
set(RAYLIB_DIR "${CMAKE_SOURCE_DIR}/raylib")

# Include Raylib headers
include_directories(${RAYLIB_DIR}/src)

# Link to the Raylib static library
link_directories(${RAYLIB_DIR}/src)

# Add your source files
add_executable(${PROJECT_NAME}
        main.cpp
        Engine.cpp
        Engine.h
        PrimitiveRenderer.cpp
        PrimitiveRenderer.h
        Player.cpp
        Player.h
        Logger.cpp
        Logger.h
        TileMap.cpp
        TileMap.h
        Enemy.cpp
        Enemy.h
        # add more cpp files here if needed
)

# Link Raylib and required macOS frameworks
target_link_libraries(${PROJECT_NAME}
        raylib
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
)
