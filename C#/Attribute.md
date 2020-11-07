# Attribute属性

给函数增加条件

```c#
using System.Diagnostics;
class MyClass{
    //在debug模式下触发的函数,
	[Conditional("DEBUG")]
    void fn(){
        //函数内容会在debug模式才会执行
        //使用预处理语句 #define Debug 也能激活
    }
    //true 会报错   false 报警告
    [Obsolete("函数已被弃用",true)]
    void fn2(){}
}
```

## 自定义Attribute

类的的名字后缀加上Attribute

```c#
//AttrbuteUsage使用场合   enum AttributeTargets
//AllowMutiple 是否可以放置多个
//inherited 是否可以被继承
[AttrbuteUsage(AttributeTargets.Class),AllowMutiple=false,inherited=false]
class MyAttribute:Attribute{
	protected string desription;
    
    MyAttribute(string msg){}
	
    //设置参数
    public string Name{
    	set;
    	get;
    }	
}
```

使用自定义的Attribute

```c#

[My("msg"),Name="123"]
class MyClass{
    
}
```

## 通过反射获取Attribute

```c#
MyAttribute myAttribute;
foreach(var attr in typeof(AnyClass).GetCustomAttributes(true)){
    myAttribute = attr as MyAttribute;
    if(null !=myAttribute){
        
    }
}
```

