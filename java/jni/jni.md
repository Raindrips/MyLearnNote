## jni

首先声明一个本地方法

```java
public class MyClass {  
	//本地方法,底层通过语言来实现  
    public native void sayHello();
}
```

通过命令行生成`.h`头文件

```sh
javah -jni <类名> -d <目录>
```