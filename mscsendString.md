mciSendString



```cpp
MCIERROR mciSendString(
  LPCTSTR lpszCommand,  		//要发送的命令字符串。字符串结构是:[命令][设备别名][命令参数].
  LPTSTR lpszReturnString,       //返回信息的缓冲区,为一指定了大小的字符串变量.  
  UINT cchReturn,                
  HANDLE hwndCallback   
);
```

