## Cmake项目构建

创建一个文件命名为`CMakeLists.txt`



指定最Cmake小的一个版本,如果低于该版本,就会出现致命错误

```cmake
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
```

第二行，声明了项目的名称(`recipe-01`)和支持的编程语言(CXX代表C++)：

```cmake
project(recipe-01 LANGUAGES CXX)
```

指示CMake创建一个新目标：可执行文件`hello-world`。这个可执行文件是通过编译和链接源文件`hello-world.cpp`生成的。CMake将为编译器使用默认设置，并自动选择生成工具：

```cmake
add_executable(hello-world hello-world.cpp)
```

设置c++标准

```cpp
set(CMAKE_CXX_STANDARD 20)
```