\1. 分割窗口

 分割窗口类: Qsplitter 在文件管理 资源管理器(设置窗口拖拽)

 分割窗口的流程:

   1.创建Qsplitter 的对象.设置主分割窗口.可以设在属性

​    设在水平分割:Qt::Horizontal

​    设置垂直分割:Qt::Vertical

 

   2.创建一个要插入主分割窗口的控件,QtextEdit,QListWidget

   3.创建主分割窗口的子分割窗口 (水平/垂直)

   4.设置窗口的属性

​     设置立马更新:

​     设置控件伸缩:

   5.在子分割窗口中设置子控件

   6.显示窗口

​     

\2. 停靠窗口

  停靠窗口类:QDockWidget--随意的拖拽,让窗口停靠在某一个位置

  处理流程:

   \1. 创建一个停靠窗口QDockWidget的对象

   \2. 设置窗口属性

​     停靠方式:

​     停靠区域

   3.创建新的控件,一般 LISTwidget

   4.把控件添加到停靠窗口中

   5.通过addDockWidget()把分割窗口添加到主窗口中.

\3. 堆栈窗口

  堆栈窗口的类: QStackedWidget 继承于QFrame 是多个窗口的叠加 一次显示一个

  Int addWidget().添加页面,返回索引

  Int insertWidget(位置,控件对象)

  Void removeWidget(控件对象);

  获取当前页面 currentIndex();

\4. 布局管理

 水平布局

  相关类: QHBoxLayout 在水平方向上排列控件  左右排列

   添加控件addWidget();

   设置默认:setLayout();

   添加控件addLayout();

  

 垂直布局

QVBoxLayout

  // Phlayout->setMargin(30);

 // Phlayout->setContentsMargins(50,20,50,70);

 

 网格布局

 QGridLayout 

 表格布局

 

 

 1.运算符重载的格式

成员函数: 

单目运算符:返回值 operator操作符(){  }

双目运算符:返回值 operator操作符(const 类& 对象){  }

全局函数: 

单目: 返回值 operator操作数(const 类& 对象){}

双目:返回值 operator操作数(const 类& 对象1,const 类& 对象2){}

\2. 调用:

第一种:A+B

第二种:A.operator+(B)

 

 \3. 注意:

   运算符至少有一个操作数是自定义的.

   不能违反正常运算符规则. 比如单目不可以重载成多目,结合性

   不能创建新的运算符. 比如说@ $  ....

   有一些运算符不能重载  ? :  .  *  sizeof  ::

\4. 有些运算符只可以是成员函数.  =  [ ]  ( )  -> 访问成员变量的运算符

\5. 所有运算符汇总:

数学运算符: A operator#(const A& a);   + - * /  %

​      Friend operator#(const A& a,const A& b);

关系运算符:

​     bool operator==(const A& a);  ==  !=  >  <  >=  <=

​     bool operator==(A& a,const A& b);

逻辑运算符: 

​    bool operator||(const A& a);  ||  &&  !  

bool operator==(A& a,A& b);

单目运算符:  A operator#()   + -

​        A operator#(const A& a);

   加加减减 

前减减:friend integer& operator--(integer& a)

后加加integer& operator++(int)

赋值运算符: 

A operator += (const A& a); 

位运算符:

  A operator |(const A& a); 

A operator ~(); 

内存申请运算符:

  void* operator new(int size)

  Void* operator delete(void* p);

特殊运算符;

   A operator[](int i);

T operator->(); 

A& operator()( )  A(1,2); 

侧写师李昂

 

作业: 需要实现的运算符:  =  ==  new  -负号

​    

​    

 

 