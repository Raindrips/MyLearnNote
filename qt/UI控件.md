# UI控件

## 按钮

+ `QPushButton`(按钮)
+ `QToolButton`(工具按钮)
+ `QRadioButton`(单选按钮)
+ `QCheckBox`(多选按钮)
+ `QCommandLinkButton`(命令链接按钮)
+ `QButtonBox`(按钮盒)

### 按钮(QPushButton)



## 标签

+ `QLabel`文字标签
+ `QLabel`图片标签

### 工具栏

```cpp

```



### 进度条ProgressBar

```cpp
/// 进度条
auto progressBar= this->ui->progressBar;
/// 设置范围
progressBar->setRange(30,70);
/// 修改值
progressBar->setValue(60);
```

### 滚动条ScrollArea

`QScrollArea`  提供了一个滚动视图到另外一个部件，滚动区域用于显示一个画面中的,子部件的内容。如果部件超过画面的大小，视图可以提供滚动条，这样就都可以看到,部件的整个区域。

### 堆栈窗口

```cpp
//创建堆栈窗口
QStackedWidget *stack = new QStackedWidget(this);

//创建控件
QLabel *plabel1 = new QLabel("第一个窗口内容.....");
QLabel *plabel2 = new QLabel("第2个窗口内容.....");
QLabel *plabel3 = new QLabel("第3个窗口内容.........");

//把基本控件添加到堆栈窗口中
stack->addWidget(plabel1);
stack->addWidget(plabel2);
stack->addWidget(plabel3);

//创建一个list控件
QListWidget * ls = new QListWidget(this);
ls->insertItem(0,"显示第一个窗口");
ls->insertItem(1,"显示第2个窗口");
ls->insertItem(2,"显示第3个窗口");

QHBoxLayout * main = new QHBoxLayout(this);
main->addWidget(ls);
main->addWidget(stack);

connect(ls,SIGNAL(currentRowChanged(int)),stack,SLOT(setCurrentIndex(int)));
```

### QToolButton

QToolButton类提供了命令或选项的快速访问按钮，通常在1QToolBar中使用

