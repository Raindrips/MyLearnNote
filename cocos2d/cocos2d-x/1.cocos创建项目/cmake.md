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


