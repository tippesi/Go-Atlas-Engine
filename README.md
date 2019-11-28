# Go - Atlas Engine
## Introduction
This project provides an interface between the [Atlas Engine](https://github.com/tippesi/Atlas-Engine) and Go.
## Set up
1. Download [Go](https://golang.org/).
2. Download [MSYS2](http://www.msys2.org/). (Windows only)
3. Update MSYS2 with *pacman -Syu*. (Windows only)
4. Download MingGW64 with *pacman -S mingw-w64-x86_64-toolchain*. (Windows only)
5. Add *C:/msys64/mingw64/bin/* to PATH. (Windows only)
6. Compile C++ code using Clion and gcc. (Won't work at first because we still need to link to Go)
7. Compile Go code (*go* folder) with *go build -o App.so -buildmode=c-shared* in terminal.
8. Compile c++ code again (should be able to call App.so in *go* folder)
9. Have fun