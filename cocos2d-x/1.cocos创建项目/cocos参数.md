# cocos
cocos 命令,自动运行cocos.bat文件

可用的参数：
 -h, --help 									显示帮助信息。
 -v, --version								显示命令行工具的版本号。
 --ol ['en', 'zh', 'zh_tr']				   指定输出信息的语言。
 --agreement ['y', 'n'] 				   使用指定的值来同意或拒绝协议。


可用的命令：

-------------------------------------------------------------
+ run              					在设备或者模拟器上编译，部署和运行工程。
> -s <SRC_DIR>, --src				指定工程路径。
> -q, --quiet           			较少的输出。
> -p <PLATFORM>, --platform			指定目标平台

> --list-platforms      			List available platforms
> --proj-dir <PROJ_DIR>   			指定目标平台路径。
> -m ['debug','release'], --mode   	设置运行模式，默认值为 debug。

+ new 	创建一个新的工程。
> -p <包名>		--package	设置包名
> -d <路径>		--directory	工程的路径
> -t <模板> 	--template	设置使用的模板名称
> --ios-bundleid IOS_BUNDLEID
	iOS Bundle ID。
> --mac-bundleid MAC_BUNDLEID
	设置工程的 Mac Bundle ID。	
> -e <引擎>			设置引擎路径
> --portrait		设置工程为竖屏
> -l [cpp,lua,js]	设置工程使用的编程语言


+ luacompile       对 lua 文件进行加密和编译为字节码的处理。

+ deploy           编译并在设备或模拟器上部署工程。

+ compile          编译并打包工程。

+ gen-simulator    生成 Cocos 模拟器。



+ jscompile        对 js 文件进行加密和压缩处理。



创建硬链接

windows 下

```shell
mklink /D cocos2d ..\cocos2d
```

