# Cmake命令

## project

用于指定项目的名称

```cmake
## 项目的名称的Main
project(Main)

## 命令语法
project(<projectName> [fileName...])
```

## cmake_minmum_required

用于指定cmake编译器的最低版本

```cmake
## 最小版本为3.7
cmake_minmun_required(VERSION 3.7);
```



## aux_source_directory

将dir目录下所以的源文件(`.cpp` `.h` `.c`)和名字保存在变量`variable` 中

```cmake
## 将本地的文件保存为变量 DIR_SRCS
aux_source_directory("." DIR_SRCS);
```

## add_executable

从一组源文件中编译成一个可执行的文件

```cmake
## 将文件编译成  Main 的可执行文件
add_executable(Main "main.cpp" "test.cpp" "test.h")
##将保存的变量添加上去
add_executable(Main ${DIR_SRCS})
```

## add_library

从一组指定的库文件中添加一组库目录

```cmake
## 添加lib文件
add_library(libfn "lib/libfn.cpp" "lib/libfn.h" )
```

## add_dependencies

用于指定目标,依赖与其他目标,目标必须是`add_executeable`,`add_libaray`,`add_custom_target`命令创建的目标

```cmake
## 用于指定某个目标,依赖于其他目标
add_dependencise(Main)
add_dependencise(libfn)
```

## add_subdirectory

用于添加一个需要进行构建的子目录

```cmake
## 添加目录
add_subdirectory(Lib)
## 包含子项目
add_subdirectory("./test")
```

## target_link_libraries

用于指定需要链接的`target`,这里`target` 必须是被创建的项目

```cmake
## 添加到Main
target_link_libraries(Main libfn)
```

## set命令

用于设定变量`variable`的值

```cmake
set(abc,on)
```

## unset

用于移除变量

```cmake
unset(abc)
```

## massage

用于输出信息

```cmake
massage("hello world")
```

## include_directories

寻找头文件路径

```cmake
include_directories("/user/local/include")
```

## find_path

用于查找库文件的路径,将找到的路径保存

```cmake
## 将变量保存在var上
find_path(VAR "path")
```

## find_library

用于查找库文件`name`路径

```cmake
find_library()
```

## file

此命令提供了丰富的文件和目录相关操作

```cmake
file()
```



