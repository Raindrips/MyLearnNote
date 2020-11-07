# 文件IO

## File类

进行文件的操作

```c#
const string FILE_PATH;
//判断文件是否存在
if(File.Exists(FILE_PATH)){
    FileStream fs=new FileStream(FILE_PATH,FileMode.Create);
    BinnaryWrite b=new BinnaryWrite();
	//BinnaryReader
    b.Close();
    fs.Close();
}
```

文件的特殊打开方式

```c#
using (StreamWrite w = File.AppendText("1.txt"){
    TextWriter tw=w;
	tw.Write("");
}
```