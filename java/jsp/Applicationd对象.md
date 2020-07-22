# application对象

+ 实现用户间数据分享，可做全局变量
+ 开始与服务器启动，终止于服务器关闭。
+ ServletContext的实例

## 常用方法
```java
void setAttribute(String name,Object value);   //使用指定对象绑定

Object getAttribute(String name); //返回指定对象
```

# page内置对象
page对象就是jsp页面对象本身，类似与this指针

```java
class getClass();		//返回此Object类
///obejct常用类
```
# pageContext对象
+ 提供了对JSP页面内所有的对象及名字空间的访问
+ 访问到页面所在的session，applocation
+ 所有功能的集大成着

```java
JspWrite getOut() 						//返回当前客户端的JspWriter流
HttpSession getSession();			//返回当前页的HttpSession对象
Object getPage();							//返回当前页对象
ServletRequset getRequest();		//返回ServletReques对象（requeset)
ServletResponse getResponse(); //返回当前页的Servlet对象（response)
void setAttribute（String name,Object attribute); //设置属性对象
Object getAttribute(String name,int scope);				//设置属性范围内属性的值
void forward(String relativeUrlPath);							//使当前页重导到另一页面
void include(String relativeUrlPath);							//当前位置包含另一文件

```

## Config 对象
在一个Servlet对象初始化时，JSP引擎向它传递信息是

```java
	ServletContext getServletContext();//返回含有服务器相关的ServletContext对象
	String getInitParameter(String name)//返回初始化参数的值
	Enumeration getInitParameterNames() //返回Servlet初始化所需所有参数的枚举
```


## Exception对象
异常类对象，当对象运行过程中产生了异常，就产生这个对象。如果一个JSP页面要应用此对象，就必须吧isErrorPage设为true,它实际上是java.lang.Throwable对象

```java
String getMessage()   //返回异常描述信息
String toString() 		//返回关于异常简短描述信息
void printStackTrace()//显示异常及轨迹
Threwable FillInStackTrace()//重写异常执行的栈轨迹

```