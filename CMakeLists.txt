cmake_minimum_required(VERSION 3.28)
project(LearnX86Assembly)

set(CMAKE_CXX_STANDARD 20)

# Enable ASM provided by NASM
enable_language(ASM_NASM)

# Add executable from asm code
add_executable(asm-main src/001-asm-main/main.asm)

# Add executable from cpp and asm code
add_executable(asm-lib
        src/002-asm-lib/main.cpp
        src/002-asm-lib/lib.hpp
        src/002-asm-lib/lib.asm
        src/002-asm-lib/lib.cpp
)
