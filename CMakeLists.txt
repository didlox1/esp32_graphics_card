# A minimal CMake starter file for a simple C++ project
#
# Usage:
# 1. Configure: cmake -S. -Bbuild
# 2. Build: cmake --build build
# 3. Clean and build (optional): cmake --build build --clean-first
# 4. Run: ./build/lab (Unix) or build\Debug\lab.exe (Windows/MSVC)

# Specify the minimum CMake version required
cmake_minimum_required(VERSION 3.16)

# Define the project name, version, and language
project(esp32_graphics_card
    VERSION 1.0
    DESCRIPTION "Graphics card software"
    LANGUAGES CXX
)
# Set C++ standard to 20 and enforce it
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # Ensures the standard is required, not optional
set(CMAKE_CXX_EXTENSIONS OFF)        # Disable compiler-specific extensions (e.g., GNU extensions)
# MSVC-specific workaround for C++20 (if needed for older MSVC versions)
if(MSVC)
    set(CMAKE_CXX20_STANDARD_COMPILE_OPTION "-std:c++latest")
    set(CMAKE_CXX20_EXTENSION_COMPILE_OPTION "-std:c++latest")
endif()

# Define the executable and list source files
add_executable(${PROJECT_NAME}
    #main.cpp
    # Add additional source files here as needed, e.g.:
    # src/Student.cpp
    #in main folder
    "top.cpp"
    #in /include folder
    "include/Clock.h"
    "include/Gpu.h"
    "include/Module.h"
    "include/IResetable.h"
    "include/ITickable.h" 
    "include/VgaController.h"
    "include/Testbench.h"
    #in /src folder
    "src/VgaController.cpp"
    "src/Testbench.cpp"
    )

# Specify include directories for header files
target_include_directories(${PROJECT_NAME} PRIVATE
    include/
)
# Ensure the target uses C++20 features
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

# Print a status message to confirm configuration
# Display configuration status
message(STATUS "Project ${PROJECT_NAME} v${PROJECT_VERSION} configured")
message(STATUS "C++ standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID}")
