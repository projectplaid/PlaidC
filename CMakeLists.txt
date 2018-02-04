cmake_minimum_required (VERSION 3.5)
project (Plaid C ASM)

# We had to adjust the CMAKE_C_FLAGS variable in the toolchain file to make sure
# the compiler would work with CMake's simple program compilation test. So unset
# it explicitly before re-setting it correctly for our system
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -nostartfiles")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -nostdlib")

# Set the linker flags so that we use our "custom" linker script
set (CMAKE_EXE_LINKER_FLAGS "-Wl,-T,${PROJECT_SOURCE_DIR}/rpi2.ld -lgcc")

# The version number.
set (PLAID_VERSION_MAJOR 1)
set (PLAID_VERSION_MINOR 0)
 
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/plaidconfig.h.in"
  "${PROJECT_BINARY_DIR}/plaidconfig.h")
 
# add the binary tree to the search path for include files
# so that we will find plaidconfig.h
include_directories ("${PROJECT_BINARY_DIR}")

add_executable (Plaid 
    start.S
    cstartup.c
    plaid.c
    gpio.c
    uart.c)

add_custom_command (
    TARGET Plaid POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} ./Plaid${CMAKE_EXECUTABLE_SUFFIX} -O binary ./kernel.img
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Convert the ELF output file to a binary image" )