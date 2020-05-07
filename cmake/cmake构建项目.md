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

# CMake 构建项目

- **-G**，通过 CMake 生成特定 IDE 的项目配置文件。这个操作依赖 IDE，即无法在一个没安装 Xcode 的 macOS 上通过 CMake 生成对应的工程文件。
  - -GXcode 生成 Xcode 工程文件
  - -GVisual Studio 15 2017 生成 Visual Studio 2017 工程文件
- **CMAKE_BUILD_TYPE**, 指定构建模式，比如 Debug 还是 Release，默认值 Debug。
  - -DCMAKE_BUILD_TYPE=Release 指定以 Release 模式生成工程。
- **-H -B**，-H 用来指定一个源码目录，指定的目录必须含有一个 CMakeLists.txt 文件，-B 用来指定 CMake 生成的中间文件的存放目录。
  - -H..\cocos2d-x  -Bmsvc_build 指定要构建工程的工程路径是上一级目录的 cocos2d-x 子目录，指定 CMake 生成的文件存放在 msvc_build 目录。
- **—build** 
  执行构建过程，同时指定曾使用 CMake 命令生成的构建文件所在目录。

- cmake —build ./msvc_build 在执行这个构建过程时，CMake 会自动选择对应的构建工具。

