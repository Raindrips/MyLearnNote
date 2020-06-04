# C静态库和动态库

通过编译链接的库  `*.lib`

在vs的项目设置中 配置属性->配置类型->选择静态库(*.lib*)就可以使用了

## 使用静态库

如果`lib`已经建好了lib工程的话,直接引用就OK了



**导入lib库:**进入工具栏->项目->属性->VC++目录

进入**库目录**列表,如果目录是在当前路径的话,就用相对路径,或者是复制绝对路径放入

> 进入项目的快捷键(2019):  alt+f7

**导入头文件:**工具栏->项目->属性->C++->常规

找到附件包含目录,将lib库的目录放入`CAPI\include`

工具栏->项目->属性->链接器->输入

找到附加依赖项,填加下面两个库

# 动态库

DLL程序入口点函数：`DllMain`，**注意：大小写是区别的(仅导出资源的DLL可以没有`DllMain`函数)。**



```c++
/*
	hModule:指向DLL本身的实例句柄
	ul_reason_for_call参数：指明了DLL被调用的原因
	lpReserved参数：保留，目前没什么意义
*/
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    return TRUE;
}
```

`ul_reason_for_call`的作用

```c++

switch (ul_reason_for_call)
{
    case DLL_PROCESS_ATTACH:
        //DLL被进程 <<第一次>> 调用时，导致DllMain函数被调用

    case DLL_THREAD_ATTACH:
        //当DLL被从进程的地址空间解除映射时，系统调用了它的DllMain
    case DLL_THREAD_DETACH:
        //当进程创建一线程时，系统查看当前映射到进程地址空间中的所有DLL文件映像
    case DLL_PROCESS_DETACH:
        //如果线程调用了ExitThread来结束线程（线程函数返回时，系统也会自动调用ExitThread），系统查看当前映射到进程空间中的所有DLL文件映像，并用DLL_THREAD_DETACH来调用DllMain函数，通知所有的DLL去执行线程级的清理工作。
	break;
}
```

通过函数动态调用动态库

```c++
//调用动态库
HMODULE hmoudle = LoadLibrary(L"DLL1.dll");

int_fun p = (int_fun)GetProcAddress(hmoudle, "fnDll1");
if (p==nullptr)
{
    cout << "faild" << endl;
    return -1;
}	
p();

//释放动态库内存
FreeLibrary(hmoudle);
```

