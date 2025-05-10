cmake_minimum_required(VERSION 3.31)
project(LearnX86Assembly)

set(CMAKE_CXX_STANDARD 20)

# Enable ASM provided by NASM
enable_language(ASM_NASM)

# Add executable from asm code
add_executable(main-asm main.asm)
