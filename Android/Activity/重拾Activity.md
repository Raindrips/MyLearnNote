# 重拾Activity

+ Activity是一个应用程序组建
+ 为应用程序提供一个可视化页面
+ 用户通过此页面与应用程序进行交互



## Activity的本质

+ Mainifast.xml
+ MainActivity
+ Layout(通过setConentView)







## Activiy的生命周期

### Activity的交互

```java
//通过id获取控件
TextView textView =(TextView)findViewById(R.id.xxx);
```



### Activity的横竖屏切换

横竖屏切换会删除原来的Activity界面然后创建一个新的界面,在创建时保存Bundle类

```java
protected void onSaveInstanceState(Bundle outState){
    
}

protected void onCreate(Bundle saveInstance){
    super.onCreate(saveInstance);
    
}
```



## Activity的启动方式

显示状态

```java
@override
protected void onCreate(){}

@override
protected void onStart(){}

@override
protected void onReStart(){}

@override
protected void onResume(){}
```

看不见状态

```java
@override
protected void onPause(){}

@override
protected void onStop(){}
```

销毁状态

```cpp
@override
protected void onDestory(){}
```



### 直接启动

### 匿名启动



## 如何启动系统的Activity



