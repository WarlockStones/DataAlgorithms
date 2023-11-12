# Data and Algorithms school work. 2023

This project requires CMake to build.

The source code is in /src

## Building on Windows using Visual Studio
Download the 'C++ CMake tools for Windows' if it is not already installed.\
Tools > Get Tools and Features... > Individual components > C++ CMake tools for Windows.

Open the folder like normal and Visual Studio will load it as a CMake project.\
Build like normal.

## Building on GNU/Linux using CMake, GCC, and Make
Prerequisites: CMake, gcc, make
You can probably build using other tools and compilers but this works for me.\
From the git repository you downloaded, run these commands.
```
mkdir build
cd build
cmake ../
make
```
