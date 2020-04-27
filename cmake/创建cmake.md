# cmake

创建`cmake`文件

*`CMakeLists.txt`*

**NOTE**:*文件的名称区分大小写，必须命名为`CMakeLists.txt`，CMake才能够解析。*

具体步骤如下：

1. 用编辑器打开一个文本文件，将这个文件命名为`CMakeLists.txt`。

2. 第一行，设置CMake所需的最低版本。如果使用的CMake版本低于该版本，则会发出致命错误：

   ```cmake
   cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
   ```

3. 第二行，声明了项目的名称(`recipe-01`)和支持的编程语言(CXX代表C++)：

   ```cmake
   project(Main LANGUAGES CXX)
   ```

4. 指示CMake创建一个新目标：可执行文件`hello-world`。这个可执行文件是通过编译和链接源文件`hello-world.cpp`生成的。CMake将为编译器使用默认设置，并自动选择生成工具：

   ```cmake
   add_executable(Main "main.cpp" "main.h")
   ```

5. 将该文件与源文件`hello-world.cpp`放在相同的目录中。记住，它只能被命名为`CMakeLists.txt`

6. 现在，可以通过创建`build`目录，在`build`目录下来配置项目：

   ```shell
   mkdir -p build
   cd build
   cmake ..
   ```

7. 如果一切顺利，项目的配置已经在`build`目录中生成。我们现在可以编译可执行文件：

```sh
cmake --build .
```



用其他方式生成,这个会自动生成一个`Makefile`文件

```sh
 ## Linux 上生成
 cmake -G"Unix Makefiles" ../
 
 ## windows 系统上生成
 cmake ../ -G"Visual Studio 12 2013"
```

