cmake_minimum_required(VERSION 3.10)
project(WinosTestPlugin)

set(CMAKE_CXX_STANDARD 17)

# Create the DLL
add_library(WinosTestPlugin SHARED WinosTestPlugin.cpp)

# Windows specific settings
if(WIN32)
    # Set output name
    set_target_properties(WinosTestPlugin PROPERTIES OUTPUT_NAME "WinosTestPlugin")
    
    # Link Windows libraries
    target_link_libraries(WinosTestPlugin user32)
    
    # Set DLL export definitions
    target_compile_definitions(WinosTestPlugin PRIVATE BUILDING_DLL)
endif()

# For cross-compilation from other platforms
if(CMAKE_CROSSCOMPILING AND CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(WinosTestPlugin user32)
endif()