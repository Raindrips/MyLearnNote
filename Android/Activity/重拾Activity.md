# 重拾Activity

## Activity的本质



## Activiy的生命周期

### Activity的交互

```java

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



