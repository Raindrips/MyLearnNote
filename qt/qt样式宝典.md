 

#   Qt Style Sheet开发总结



  为了书写方便,文中一律使用Qss代替Qt  style sheet.  



  个人认为使用Qss的好处:  

1. 可读性高并且非常直观,便于设置界面样式;  

2. 在每个平台上都有相同的显示效果.  

3. 可以在界面代码中省去与显示效果相关的大量代码,将界面逻辑独立出来.  (4)在界面风格(配色,字体等)改变的情况下,可以不用修改c++源码就可以实现.  

### 控件选择器

  基本语法  

```css
/**/
selector { attribute: value; }
/*设置颜色为红色*/
QPushButton{ color: red;}
```

###   通用选择器

> {属性:值;  }  

  通用选择器用(  * )来表示,它表示匹配程序中所有的widget.  

  *由于通用选择器会匹配程序中所有的 widgets,效率较低,因此应该尽量减少或者不使用*  

```css
/** 这条语句表示将程序中所有widget的字体大小都设置为20px大小,字体采用微软雅黑.  */ 
*{font: normal 20px“微软雅黑”;}  
```

### 类选择器

> 类名  {属性:值;  }  

```css
 .QPushButton{  color:   blue;  }  
 .QFrame{  padding:  15px  25px;  }  
```

###   ID选择器

>  #id{属性:值;   }  

  ```css
  #button_1{  color:   red;  }  
  ```



  objectName是大小写敏感的.  “#”与 ID之间不可以有空格  

  3.由于   objectName是所有  QObject类对象的一个属性,在运行过程中可以改变,所以一般  情况下,要使用   ID选择器时,保证    objectName不要在运行时被改变  ,否则重新加载  stylesheet文件时,对应的  ID选择器将不会匹配到原来的控件.  

  4.由于   objectName允许字符串中含有空格,但是   ID选择器中,  ID是从紧跟#后的第一个字  符开始直到遇到空格或  “{”之间的字符串 ,因此  ,如果是为了使用    ID选择器而设置  objectName,则  objectName中不能含有空格  

  5.由于任何对象的   objectName都可以出现重复,因此在设置   objectName时,尽量保持其  唯一性  

> 类名**#id**{属性:值;   }  

  但实际上不加类名也是可以的(加了类名的 ID选择器在 CSS中被称为交集选择器),在正  式开发中,还是建议加上类名,因为这样可以看出这个   id选择器所匹配的对象的类型,  有利于提高阅读性.  

  基于以上特点,我们在设置  objectName时,一般使用下划线”_”连接的多个单词表明此对象  的功能.  

  一般用法  

  ID选择器一般用于为比较特殊的控件设置样式,例如在我的某个页面中,需要突出一个重要  的按钮,那么此时我可以给这个按钮设置一个独特的样式用以提醒用户,如:  



```css
QPushButton#settings_popup_fileDialog_button{  
    min-height:   31px;  
    min-width:  70px;  border: 1px  solid black;  color:  #F0F0F0;  
    min-height:  10px;  border-radius:3px;  
    background:  qlineargradient(spread:pad,  x1:0, y1:0, x2:0, y2:1,  stop:0 #454648, stop:1   #7A7A7A);  
}
```



###   后代选择器 

> 选择器  **1**选择器  **2**{属性:值;   }  



1. 后代选择器必须用空格隔开每个选择器  

2. 后代选择器可以通过空格一直延续下去,例如:  

> 选择器  1选择器  2选择器  3 …选择器  N{属性:值;   }  

3. 顾名思义,后代选择器不仅包含”儿子”,还包含”孙子”,     “重孙子”等,一般来说,只要   B控  件显示在 A控件上,那么  B控件就是  A控件的后代.  

4. 后代选择器不仅可以使用类型选择器,还可以使用类选择器,    id选择器等.  

  Qt中,各控件的父子关系:  

  通过简单的验证,各控件的父子关系并非我们在创建对象时所指定的那样  ,实际父子关  系取决于如何布局.  

 ```css
BaseDialog QPushButton{  
    min-width: 120px;  
    min-height: 40px;  
    max-width: 120px;  
    max-height: 40px;  
    font-size: 20px;  
    padding: 0px;  
}  
 ```

> 选择器  **1 >**选择器 **2** {属性:值;   }  

  ### 子元素选择器

子元素选择器表示找到指定选择器所匹配的对象中的所有特定直接子元素然后设置属性   ,  即找到选择器 1匹配到的对象中的被选择器 2匹配盗的直接子元素然后设置属性  

  注意点  

  1.子元素选择器必须用”>”连接,   “>”两边有没有空格都可以,但是不建议写空格,因为会与  后代选择器的连接符混淆.  

2. 子元素选择器只会查找”儿子”,不会查找其他后代.  

3. 子元素选择器不仅可以使用类型选择器,还可以使用类选择器,id等选择器  4.子元素选择器不能通过”>”一直延续下去,只能有一个”>”  

5. 由于   Qt中有继承关系的  Widgets较多,在使用子元素选择器时,请特别注意继承关系,  比如我只想选中 QGroupBox中的 QPushButton,那么我即可以写成  

```css
QWidget >QPushButton{color: red;}  
QGroupBox>QPushButton{color: red;}  
```



###   属性选择器

 ```css
 [attribute=value]{属性:值;   }  
[attribute|=value]{属性:值;  }  
[attribute~=value]{属性:值;  }  
 ```

attribute=value表示匹配有特定属性 attribute,并且值为  value的所有控件,然后设置样式;  

  attribute|=value表示匹配有特定属性  attribute,并且值以  value开头的所有控件,然后设置  

  attribute~=value表示匹配有特定属性  attribute,并且值包含  value的所有控件,然后设置样  式;  

  attribute|=value表示  attribute属性的值以 value开头,无论  value后面还有没有值,或者  value后面是什么,均能匹配到,

```css
/*这表示将 objectName属性以 button开头的所有控件的前景色设置为红色.  */
[objectName|="button"]{color: red;}  
```

attribute~=value表示  attribute属性的值中包含  value,这里要注意的是:value必须是独  立的单词,也就是包含  value并且 value是被空格隔开的,例如:  

```css
[objectName~="button"]{color:red;}
```

  而我在代码中,设置的  objectName的语句为:  

  结果是只匹配到了 pBtn2所指的对象  



  通常情况下,这里的属性指的是,使用   Q_PROPERTY宏所声明的属性,并且属性类型  要受 支持.  

  这个选择器类型也可以用来判断动态属性，要了解更多使用自定义动态属性的细节，  请参考使用自定义动态属性。  

  除了使用=，你还可以使用~=来判断一个 QStringList中是否包含给定的 QString。  警告：如果在设置了样式表后，相应的属性值发生了改变(如：flat变成了”true”)，  则有必要重新加载样式表，一个有效的方法是，取消样式表，再重新设置一次,下面的代  码是其中一种方式：  

  style()->unpolish(this);  

  style()->polish(this);  



 ###   并集选择器  

> 选择器  **1,**选择器 **2,**选择器  **3**{属性:值;   }  

  

  并集选择器表示,将每个单独选择器匹配到的控件放在同一个结果集中,并给结果集中的每  个控件都设置声明语句中的样式.  

1. 并集选择器必须使用”,”来连接不同的选择器  

2. 并集选择器可以使用类选择器,类型选择器,    id选择器,属性选择器等.  

  主要用于给具有相同属性并且外观相似的的控件设置样式,例

 

```css
.QLineEdit, .QComboBox{  
    border:  1px  solid gray;  
    background-color:white;  
}  
```

  两个特殊的选择器  子控件选择器  格式  

  类型选择器**::**子控件{属性:值;   }  

  类选择器**::**子控件{属性:值;   }  

  表示对类型选择器或类选择器指定的所有控件的子控件设置样式;  

  Qt官方说明  

  为了样式化你的复杂 widget，很有必要使用 widget的 subcontrol，比如 QComboBox的   drop-  down部分或者是  QSpinBox的上和下箭头。选择器也许会包含  subcontrols用于限制  widget  的 subcontrols,举个例子:  



```css
QComboBox::down-arrow{  
	image:url(:/res/arrowdown.png);  
}  
```



  上述规则样式化所有 QComboBox的  drop-down部分，虽然双冒号(::)让人联想到  CSS3的伪  元素语法，但是 Qt的  Sub-Controls跟它是不一样的。  

  Sub-Controls始终相对于另一个元素来定位–一个参考元素。这个参考元素可以是一个  Widget又或者是另一个  Sub-Control。举个例子，QComboBox的::drop-down默认被放置于  QComboBox的   Padding rectangle(盒子模型 )的右上角。 ::drop-down默认会被放置于另一  个::drop-down Sub-Control的中心。查看可样式化的 Widget列表以了解更多使用  Sub-Control  来样式化 Widget和初始化其位置的内容。  

  源 rectangle可以使用 subcontrol-origin来改变。举个例子，如果我们想要把 drop-down放置  于 QComboBox的 margin rectangle而不是默认的  Padding rectangle，我们可以像下面这样指  定：  



```css
QComboBox  
{  
    margin-right:  20px;  
}  
QComboBox::drop-down  
{  
    subcontrol-origin:  margin;  
}  
```



  drop-down在 Margin rectangle内的排列方式可以由 subcontrol-position来改变.  

  width和 height属性可以用来控制 Sub-control的  size.需要注意的是，设置了 image就隐  

式的设置了 Sub-control的 size了。  

  相对定位方案`position:relative`,允许 Sub-Control的位置从它的初始化位置作出偏移。  举个例子，当 QComboBox的  drop-down按钮被  pressed时，我们也许想要那个箭头作出位  移以显示一种`pressed`的效果，为了达到目标，我们可以像下面那样指定  

```css
QComboBox::down-arrow  {  image:   url(down_arrow.png);  }  

  QComboBox::down-arrow:pressed  {  position:   relative;  top:  1px;  left:   1px;  }  

  绝对定位方案(position : absolute)，使得 Sub-control的  position和 size基于其参考元素而改  变。  

```

  一旦定位，它们将会与 widget同等对待并且可以使用盒子模型来样式化。  查看  Sub-Control列表以了解那些    sub-control是被支持的，并且可以查看自定义  QPushButton的菜单指示器 Sub-Control来了解一个实际的使用例子。  注意：像 QComboBox和  QScrollBar这样的复杂部件，如果  sub-control的一项属性是自  定义的，那么其他所有的属性跟 sub-control也都应该自定义。  

###   伪类选择器  

> 类型选择器**:**状态{属性:值;   }  
>
> 类选择器**:**状态{属性:值;   }  

  表示对类型选择器或类选择器指定的所有控件设置它在指定状态时的样式.  

  选择器也许会包含基于 widget的 state的程序限制规则的伪状态。伪状态以冒号(:)作为分隔  紧跟着选择器。举个例子，下面的规则在鼠标悬浮在 QPushButton的上方时生效：  QPushButton:hover { color: white  }  

  伪状态可以使用感叹号进行取反，下面一条规则在鼠标没有悬浮在 QRadioButton上方时生  

```css
QRadioButton:!hover { color: red  } 
```

  伪状态可以链接，在这样的情况下，隐式地包含了逻辑与。举个例子，下面一条规则在鼠标  悬浮到一个已 check的 `QCheckBox`上时生效：  

```css
QCheckBox:hover:checked { color: white  }  
```

  伪状态的取反也可以出现在伪状态链中，举个例子，下面的规则在鼠标悬浮到一个没有被  press的 QPushButton上时生效：  

```css
QPushButton:hover:!pressed { color: blue;  }  
```

  如果有需要，可以使用逗号来表示逻辑或,即并集选择器  

```css
  QCheckBox:hover,  QCheckBox:checked { color: white  }  
```

  伪状态可以与 subcontrol组合使用，举个例子： 

```css
QComboBox::drop-down:hover{ image: url(dropdown_bright.png)  }  
```



  没有选择器的情况  

  如果在 c++的代码中直接调用控件对象的 setStyleSheet函数来设置样式,但样式中  没有任何选择器,例如下面这样  

```cpp
pBtn1->setStyleSheet("color:   green;");  
```

  即使这种写法可以生效,但它不符合语法规则,因此不推荐使用.  

  经过测试,这样的语句被忽略的选择器相当于通用选择器或下面例子中的选择  器,假如pBtn1是一个QPushButton对象的指针,那么这条语句等价于 

```cpp
 pBtn1->setStyleSheet("QPushButton,  QPushButton  *{color: green;}");  
```




  这里用户名输入框是一个 QComboBox对象,密码输入框是一个   QLineEdit对象,它们的父控  件是一个 QDialog,有这样一个需求:给这两个输入框设置相同的边框属性:  1个像素宽的蓝色  实线框,为了方便更改风格,我有一个   css文件,将所有样式都写在了这个文件里,这时,观  察发现,这两个控件都是  QDialog的子控件,于是可以用后代选择器或者子元素选择器,如下:  第一种:  

  QDialog QComboBox,QLineEdit{  border:1px  solid  blue;  

  }  

  第二种:  

  QDialog>QComboBox,QLineEdit{  border:1px  solid  blue;  }  

  当我写完并运行程序后,发现无论采用哪种写法  QComboBox是正常的,但是我的程序界面  中,其他所有的  QLineEdit的边框都变成了  1个像素款的蓝色实线框,而这并不是我想要的  效果.  

  因此对于上面的现象,我们很容易得出结论:多个选择器组合使用时,它们的结合方向是自  右向左 ,而不是我们认为的自左向右    .也就是说 ,这两个选择器分别被理解为    (QDialog  QComboBox),  QLineEdit和  (QDialog>QComboBox),QLineEdit.  

  其实,这应该与  CSS的选择器匹配规则是一样的,是为了提高效率的一种做法,具体原因这  里不细谈.  



  正确的写法应该是  

  QDialog QComboBox, QDialog  QLineEdit{  border:1px  solid  blue;  

  }  

  或  

  QDialog>QComboBox,  QDialog>QLineEdit{  border:1px  solid  blue;  }  

  **Qss**的特性  

  层叠性  

  qss的语法来源于  css,而  css的全称是 Cascading StyleSheet,翻译过来叫做层叠样式表,  

  也叫级联样式表,本文中一律使用层叠样式表.  层叠性是 css处理冲突的一种能力.  

  只有在多个选择器匹配到同一个控件时才会发生层叠性,如下面的例子:  

  pBtn1->setStyleSheet("QPushButton{color:   blue;}");  pBtn1->setStyleSheet(".QPushButton{color:   green;}");  

  这两个选择器匹配到了同一个按钮,结果是后面的样式覆盖掉了前面的,这就是层叠现象.  

  继承性(Qt-Version >= 5.7)   

  在典型的 CSS中，如果一个标签的字体和颜色没有显式设置，它会自动从其父亲获得。当使  用 Qt样式表时，控件不会从其父亲继承字体和颜色的设置(请注意，父亲和父类、孩子和子  类都是不同的概念，不要搞混)  

  举个例子，考虑一个 QGroupBox内有一个 QPushButton：  

  qApp->setStyleSheet("QGroupBox{  color:  red; }");  

  QPushButton没有任何显式的 color设置。因此，它会获得系统的颜色而不是从父亲继承  color  的值。如果我们要设置 QGroupBox及其所有孩子的 color，我们可以这样写：  qApp->setStyleSheet("QGroupBox,QGroupBox  * {  color: red; }");  

  注意 QGroupBox和*之间的空格.  



  与此相反，使用 QWidget::setFont()可以设置字体包括孩子的字体，使用 QWidget::setPalette()  

  可以设置调色板包括孩子的调色板。  

  如果想要字体和调色板被孩子继承                    ,可以给  Qt::AA_UseStyleSheetPropagationInWidgetStyles(Qt5.7加入)属性,例如:  

  QApplication  

  设置  

  QCoreApplication::setAttribute(Qt::AA_UseStyleSheetPropagationInWidgetStyles,   true);  

  优先级  

  为什么要有优先级？  

  当一个控件被多个选择器选中并且设置了相同的属性（值不同）时，不能仅仅根据设置样  式语句出现的先后顺序进行层叠,那么控件的样式如何确定，于是引出了选择器的优先级问  题。  

  一般通过下面两步进行选择器优先级的判定.  

  第一步：设置方式所产生的优先级问题  

  在 CSS 中，有如下层叠优先级规则：  

  内联样式 **>**内部样式   **>**外部样式  **>**浏览器缺省  而在 Qss中,这个规则表现为:  

  给控件直接设置的样式 **>**给  **QApplication**设置的样式  就是说，调用控件的  setStylesheet设置的样式的优先级永远高于给 QApplication设置的样  式，即使  QApplication中的选择器优先级更高  

  第二步：样式表本身的优先级问题  

  当设置方式相同，且几个样式规则为同一个控件的同一个属性指定不同的值时 ,就产生了冲  突.此时,如何层叠就由选择器的优先级来确定.  

  一般而言，选择器越特殊，它的优先级越高。也就是选择器指向的越准确，它的优先级就越  高。  

  优先级判断的三种方式  

  1.间接选中  

  间接选中就是指继承,也就是在  Qt5.7及以上版本,程序中给   QApplication对象设置了  Qt::AA_UseStyleSheetPropagationInWidgetStyles属性时,才会有间接选中.  

  如果是间接选中 ,那么最终的样式就是离目标最近的那个 ,这里的近指的是两个控件的  父子关系.例如一个  QPushButton对象被布局在  QGroupBox中,而  QGroupBox又被布局  



  在 QWidget中,此时如果给   QGroupBox和  QWidget都设置了 color属性的颜色,那么无  论设置顺序如何 , QPushButton的前景色总是表现为    QGroupBox设置的颜色  ,因为  QGroupBox显然是离 QPushButton最近的那一个.  

  2.相同选择器(直接选中)  

  如果都是直接选中,并且都是同类型的选择器,那么写在后面的样式会覆盖掉前面的样  式,例如  

  pBtn1->setStyleSheet("QPushButton{color:   green;}");  

  pBtn1->setStyleSheet("QPushButton{color:   blue;}");  

  显而易见, pBtn1的前景色是蓝色.  

  3.不同选择器(直接选中)  

  如果都是直接选中,并且不是相同类型的选择器,那么就会按照选择器的优先级来层叠.  具体的优先级如下:  

  Id >类  >类型   >通配符  >继承   >默认  

  优先级权重  

  为什么会有优先级权重？  

  当多个选择器混合在一起使用时 ,我们可以通过计算权重来判断谁的优先级最高  ,从而确定  控件的样式.  

  注意点：只有选择器是直接选中控件时才需要计算权重，否则直接选择器高于一切间接选  中的选择器  

  优先级权重的计算方式:  

  1.计算选择器中的   id选择器数量[=a]  

  2.计算选择器中类选择器的数量+属性选择器的数量[=b]  3.计算选择器中类型选择器的数量[=c]  4.忽略子控件选择器  

  串联这三个数字 a-b-c就得到优先级权重,数字越大优先级越高.  

  这里给出我写的一个例子， qss文件位于资源文件中：  

  Qt官方关于冲突解决的说明  

  当几个样式规则为同一个属性指定不同的值时，就产生了冲突。请考虑下面的样式表：  

  QPushButton#okButton {  color: gray;   }  

  QPushButton {  color: red;   }  

  两条规则都匹配名为 okButton的  QPushButton实例并且冲突于颜色属性。为了解决冲  突，我们必须考虑到选择器的特殊性。在上面的例子中， QPushButton#okButton被视为比  

 

  QPushButton更特殊，因为它（通常）指向一个单一的对象而不是 QPushButton的所有实例。  相似的，指定了伪状态的选择器比没有指定伪状态的更特殊。从而，下面的样式表指明  了当鼠标悬浮到 QPushButton上方时其字体颜色应该为白色，而其余情况则为红色：  

  QPushButton:hover {  color: white;   }  QPushButton {  color: red;   }  接下来看一个很有意思的：  

  QPushButton:hover {  color: white;   }  QPushButton:enabled {  color: red;   }  

  两个选择器都有相同的特殊性，所以当鼠标悬浮在一个 enabled的按钮上时，第二条规则优  先。如果在这种情况下我们想要文字变成白色，我们可以像下面那样重新排布一下样式规则：  

  QPushButton:enabled {  color: red;   }  QPushButton:hover {  color: white;   }  另外，我们可以使第一条规则更特殊一些：  

  QPushButton:hover:enabled {  color: white;   }  QPushButton:enabled {  color: red;   }  

  相似的问题出现在相互配合的类型选择器上。考虑以下情况：  

  QPushButton {  color: red;   }  

  QAbstractButton {  color: gray;   }  

  两条规则都应用于 QPushButton的实例（因为 QPushButton继承于 QAbstractButton）并且冲  突于 color属性。因为  QPushButton继承于  QAbstractButton，这让人不禁想到  QPushButton  比 QAbstractButton更特殊。然而，对于样式表的运算，所有的类型选择器都具有同等的特  殊性，并且出现在更后面的规则优先级更高。换句话说，QAbstractButton的 color会被设置  成灰色，包括 QPushButton。如果我们确实想要 QPushButton字体颜色设置为红色，我们总  是可以使用重新排列样式表规则顺序的方式实现。  

  为确定规则的特殊性，Qt样式表跟随 CSS2规范  

  一个选择器的特殊性由下面的方式计算：  -计算选择器中  ID属性的数量[=a]  -计算选择器中其他属性和伪类的数量[=b]  -计算选择器中元素名字的数量[=c]  -忽略伪原素[如:subcontrol]  

  串联这三个数字 a-b-c（在一个大基数的数字系统）就得到了特殊性等级。  

  举个例子：  

  * {} /* a=0 b=0 c=0 ->  specificity = 0 */  LI {} /* a=0 b=0 c=1 ->  specificity = 1 */  UL LI {} /* a=0 b=0 c=2 -> specificity = 2 */  UL OL+LI {} /* a=0 b=0 c=3 ->  specificity = 3 */ 

  H1 + *[REL=up]{} /* a=0 b=1 c=1 -> specificity = 11 */  UL OL   LI.red {} /* a=0 b=1 c=3 -> specificity = 13 */  LI.red.level {} /* a=0 b=2 c=1 ->  specificity = 21 */  #x34y {} /* a=1 b=0 c=0 ->  specificity = 100 */  

  盒模型  

  在讲解属性之前,我们必须了解一下  QSS的盒模型.  

  什么是盒模型?   

  盒模型仅仅是一个形象的比喻,所有的  widget都被看做是一个”盒子”,一个盒子包括：外边  

  距，边框，内边距，和实际内容.它们可以看作是有包含关系的矩形,并且这种包含关系是  

  固定不变的.  

  如图所示  



  **Margin**（外边距） - 与其他盒子之间的距离.   




  **Border**（边框）  - 外边距与内边距之间的区域.边框有自己的颜色不会受到盒子的背景颜色  影响  



  **Padding**（内边距） - 内容和边框之间的区域.会受到背景颜色影响.   **Content**（内容） - 盒子的内容,显示文本,图像或其他控件  

  除了内容外, 其他三个部分均不能单独设置颜色,  只能设置其宽度,  并且是以像素为单位  

  对比一张生活中的一张照片墙来看会更容易理解  

  盒模型中的宽度与高度  

  在属性中将要学到的 width, height两个属性,设置的均是盒子的内容的宽高,而我们在    c++  代码中的窗口的 width与 height指的是整个盒子的宽度与高度,这一点非常重要.  整个盒子的宽度应该等于:  

  左外边距 +左边框   +左内边距  +内容宽度  +右内边距   +右边框  +右外边距,  同理,整个盒子的高度也是上下外边距,内边距,边框和内容高度的和.  

  属性  

  属性即控件的具体外观样式,比如背景颜色,边框宽度等等.本节主要列举一些常用的属性,  

  并介绍它们的具体格式或取值  



  注意:一个属性并不是被所有 widget都支持的,要想查看什么   widget支持哪些属性,或一个  属性被哪些 widget支持,请查看文档后面给出的官方链接.  

  背景属性 background   

  背景共有 7个属性,既可以每个属性单独设置   ,也可以连写,下面将对他们逐一进行分析   ,  

  并在最后给出其连写格式  

  **background-color**   

  取值: Brush类型(Brush类型介绍见本节最后)  

  作用:设置控件的背景颜色,默认是   border之内的矩形区域,包括内边距和内容矩形.  

  **background-image**   

  取值: Url类型,格式是  url(filename), filename是一个本地文件路径或 Qt资源文件路径,不支  持网络图片  

  作用:设置控件的背景图片.可以与背景颜色共存   ,背景图片会覆盖背景颜色  ,在没有被图  片覆盖的区域,显示背景颜色.  

  **background-repeat**   

  取值:  

  repeat-x:在水平方向上平铺  

  repeat-y:在垂直方向上平铺  

  repeat:在水平和垂直方向上都平铺,这是默认值(但是   Qt好像有 bug,设置了  repeat反  

  而不会平铺,不设置才平铺)  no-repeat:不平铺  

  作用:设置背景图片的平铺方式.  例子:  

  给一个 QTextEdit设置背景图片,代码和效果分别如下  

  QTextEdit{  

  background-color:  skyblue;  

  background-image:   url(:/resource/girl.jpg);  background-repeat:  no-repeat;/*repeat-x;  repeat-y;  repeat;*/  }  

  **23** /  **62**  

 

  repeat-x  

  repeat-y  

  repeat  

  no-repeat  

  **background-position**   

  取值:  

  top:向上对齐  bottom:向下对齐  center:居中  格式:  

  left:向左对齐  right:向右对齐  

  background-position:水平对齐方式垂直对齐方式;  

  这是 css规定的标准顺序,而  qss并未严格规定,但建议按照   css的顺序写  作用:设置背景图片的对齐方式,默认情况下向左向上对齐,  举例:水平向左垂直居中对齐,代码和效果如下  

  QTextEdit{  

  background-color:   skyblue;  background-image:   url(:/resource/girl.jpg);  background-position:  right  center;  }  

  **24** /  **62**  

![img](clip_image058.jpg)![img](clip_image061.jpg)![img](file:///C:/Users/ADMINI~1/AppData/Local/Temp/msohtmlclip1/01/clip_image063.jpg)![img](file:///C:/Users/ADMINI~1/AppData/Local/Temp/msohtmlclip1/01/clip_image065.jpg)![img](file:///C:/Users/ADMINI~1/AppData/Local/Temp/msohtmlclip1/01/clip_image067.jpg)


  **background-attachment**   

  取值:  

  scroll :滚动,这是默认值  

  fixed:固定  

  作用:设置背景图片在带滚动条的控件  (QAbstractScrollArea)中是固定在一个位置还是随着  

  滚动条滚动.  

  比如: css代码分别如下  

  QTextEdit{  

  background-color:  skyblue;  

  background-image:   url(:/resource/girl.jpg);  background-repeat:  no-repeat;/*repeat-x;  repeat-y;  repeat;*/  background-position:  right  center;  background-attachment:   scroll;  }  

  QTextEdit{  

  background-color:  skyblue;  

  background-image:   url(:/resource/girl.jpg);  background-repeat:  no-repeat;/*repeat-x;  repeat-y;  repeat;*/  background-position:  right  center;  background-attachment:   fixed;  }  

  **25** /  **62**  




  scroll  

  fixed  

  **background-clip**   

  取值:  

  margin:外边距矩形  border:边框矩形  padding:内边距矩形  content:内容矩形  

  作用:设置背景颜色覆盖的区域  ,默认情况下背景只覆盖内边距矩形  ,如果没有指定,默认  

  值为  border  

  例子:为了区别各矩形,我们先给   QTextEdit设置边框,内边距和外边距,为了区别明显,我  

  们将边框宽度设置大一点  

  代码和图片如下:  

  QTextEdit{  

  background-color:  skyblue;  border: 20px  solid purple;  padding:  20px;  

  margin:  20px;  

  background-image:   url(:/resource/girl.jpg);  background-repeat:  no-repeat;/*repeat-x;  repeat-y;  repeat;*/  background-position:  left  top;  background-attachment:   fixed;  }  

  **26** /  **62**  

 

  分别将 background-clip属性的值设为 margin, border, padding,  content,效果图如下  

  margin  

  border  

  padding  

  content  

  **27** /  **62**  

 

  可见, background-clip属性只对背景的渲染区域有关系,背景图片始终是靠在  padding边上  

  **background-origin**   

  取值:与  background-clip一样  

  作用:与  background-position和 background-image一起使用,指明背景图片的覆盖范围矩形,  如果没有指定,默认为   padding  

  下面是分别设置为 margin, border, padding和 content的代码和效果图  

  QTextEdit{  

  background-color:  skyblue;  border: 20px  solid purple;  

  padding:  20px;  margin:  20px;  

  background-image:   url(:/resource/girl.jpg);  /*background-repeat:  no-repeat;*//*repeat-x; repeat-y; repeat;*/  background-position:  left  top;  background-attachment:   fixed;  background-clip:  margin;  /*border;  padding; content;*/  background-origin:  margin;  /*border;  padding; content;*/  }  

  margin  

  border  

  **28** /  **62**  

 

  padding  

  content  

  注意观察 border与  padding的图片,它们是不同的,差别就是    border的 20个像素所造成的  

  不一致  

  背景属性的连写格式  

  格式:  

  **background:  color image repeat position;**  

  在这种连写格式中,只能包含着四个属性,其他几个仍然需要单独写,而且这四个属性可以  省略任何一个,最多可以省略三个,也就是最少需要保留一个,即属性值不能为空  另外让人比较迷惑的是,在这种连写方式中,  repeat确实是平铺了图片,而单独写时,它又是  不平铺的,具体原因还未找到.  

  举个例子:  

  QTextEdit{  

  border: 20px  solid purple;  

  padding:  20px;  

  margin:  20px;  

  background:  skyblue  url(:/resource/girl.jpg)  repeat left top;  }  

  效果图  

  **29** /  **62**  

 

  前景属性 color   

  与背景相对应,背景设置的是控件的最底层的颜色,作为背景,但    color设置的前景色,也就  

  是控件文字的颜色, color属性是被所有 widget都支持的.  

  格式:  

  color: Brush类型的值;  举个例子:  

  QTextEdit{  

  color:  red;  

  background-color:   skyblue;  }  

  **30** /  **62**  




  边框属性 border   

  边框属性有四种书写方式,同样,先逐一进行分析,最后给出书写格式  

  属性  

  border-width  

  取值: ?px 像素宽度,数值后面一定要加上像素单位 px,也有其他单位,但不推荐使用  

  作用:用于边框宽度  例子:  

  QTextEdit{  

  border-width:   10px;  border-style:   solid;  border-color:purple;  padding:   20px;  margin:   20px;  }  

  **31** /  **62**  

 

  border-style  

  设置边框的渲染样式.  取值以及效果如下:  dashed  

  dot-dash  

  dot-dot-dash  dotted  

  double  

  groove  inset  

  outset  

 

 

  ridge  

 


  solid  

  none  

 

  border-color  

  取值: Brush类型  

  作用:设置边框的颜色  

  border-radius  

  取值:水平半径垂直半径;  

  均是以像素为单位,值必须带   px,第二个值是可选的,如果只有一个值,表示同时水平  半径和垂直半径,如果有两个值,则第一个代表水平半径,第二个代表垂直半径.  示例图  

  作用:设置边框四个角的弧度  举个例子:  


  QTextEdit{  

  border-width:   10px;  border-style:   solid;  border-color:   red;  border-radius:   50px;  padding:   20px;  margin:   20px;  }  


  QTextEdit{  

  border-width:  10px;  border-style:  solid;  border-color:  red;  border-radius: 50px  20px;  padding:  20px;  margin:  20px;  

  }  

  **35** /  **62**  


  代码 1效果图  

  代码 2效果图  

  **border-image**  

  取值:这是一个连写格式,下面给出具体的书写格式,由于    Qt对这个属性支持不是很好,因  

  此不建议使用,下面简要介绍一下  

  格式:  

  CSS的连写格式如下,每一项分别代表分开写时的一个属性.  

  **border-image:  border-image-source    border-image-slice (fill)/ border-image-width**  

  **/  border-image-outset**  

  **border-image-repeat**  

  其中, fill, border-image-width和 border-image-outset在  Qt中不被支持,而且   Qt只支持连写  格式,因此在  Qt中,我们实际的代码格式是  

  **border-image:  border-image-source**  

  **border-image-slice**  

  **border-image-repeat**  

  下面简略说一下每项的含义:  

  border-image-source:图片路径,还是只支持本地路径和  Qt资源文件路径  border-image-slice:图片切片,单位只能是像素值   ,因此数值不必带单位   px,它最多可以指  定 4个值,按照顺序分别代表上右下左,最少指定   1个值,左省略时和右相同,下省略时和上  相同,右省略时和上相同;它们的含义是,距图片顶部,右侧,下部,左侧分别按照指定的像  素值进行切片,将图片分成四个角(左上,右上,右下,左下)   +四个边(上右下左)  +中间部分    =  共 9个部分,在  CSS中,如果指定了  fill,则中间部分会覆盖元素(控件)的背景,否则中间部分  默认被省略  

  border-image-repeat:最多两个值最少一个值  ,第一个值表示水平方向  ,第二个值表示垂直  方向.作用是指定边框图片的四条边和四个角的平铺方式,不包括中间部分,有三种取值,分  别为 **stretch**(默认), **round**(均分平铺), **repeat**(平铺). stretch表示拉伸四条边相应的切片图片,  来填补边框的间隙.round是把四个角和四条边分成均等区域然后用背景图片切好能铺满整  个边框空隙,不能多也不能少,正好合适.   repeat是做直接复制填满空隙.  下面是一个切片的具体示例:  

  **36** /  **62**  


  利用上面这张图片,来看一下 border-image的一些效果图  效果  1:  

  QTextEdit{  

  border: 30px  solid red;  border-image: url(:/resource/border.png)  30  round;  background-color:  skyblue;  

  background-image:   url(:/resource/girl.jpg);  }  

  效果  2:  

  QTextEdit{  

  border: 30px  solid red;  border-image: url(:/resource/border.png)  30  stretch;  background-color:  skyblue;  

  background-image:  url(:/resource/girl.jpg);  

  **37** /  **62**  




  }  

  效果  3:  

  QTextEdit{  

  border: 30px  solid red;  border-image: url(:/resource/border.png)  30 repeat;  background-color:  skyblue;  

  background-image:  url(:/resource/girl.jpg);  

  }  




  效果  4:  

  QTextEdit{  

  border: 30px  solid red;  

  border-image: url(:/resource/border.png)  30 repeat  stretch;  background-color:  skyblue;  

  background-image:  url(:/resource/girl.jpg);  

  }  

 

  格式  

  border属性的  style, color, width可以连写也可以单独写,并且可以分别设置四条边的边框,  

  下面进行详细介绍  

  连写格式   1  

  **border:  width style color;**  

  这种格式将四条边框的宽度,风格,颜色全部设置为一样.  

  例子如下  

  QTextEdit{  

  border:  10px  solid red;  background-color:   skyblue;  }  




  连写格式   2  

  这种格式设置指定方向的边框的样式,可以只设置一条边,格式如下  

  **border-top:  width style color;**  **border-right: width style color;**  **border-bottom: width style color;**  **border-left: width style color;**  

  例子如下:  

  QTextEdit{  

  border-top: 10px  solid red;  

  background-color:   skyblue;  }  

  连写格式   3  

  这种连写格式是指定一种属性,按照上右下左四个方向进行设置边框,格式如下  

  **border-style:**上右下左**;**  **border-width:**上右下左**;**  **border-color:**上右下左**;**  

```css
QTextEdit
{  
	border-style:  solid  dashed dotted double; 
    border-color:  red  green blue purple; 
    border-width:  5px  10px 15px 20px;  
    background-color:   skyblue; 
}  
```


  单写格式  

  单写格式指的是,对每条边框的每个属性分别进行设置,格式如下  

  **border-top-width**  **border-right-width**  **border-bottom-width**  **border-left-width**  

  **border-top-style**  

  **border-top-color**  

  **border-  right -style**  **border-  bottom -style**  **border-  left -style**  

  **border-  right -color**  **border- bottom -color**  **border-  left -color**  

  字体属性 font   

  **font-style**   

  作用:设置字体风格  取值:  

  normal:正常  

  italic:斜体  

  oblique:倾斜的字体  关于 italic和 oblique的区别:  

  他们都是向右倾斜的文字,大多数情况下看不出任何区别,但是原理却不一样.  要搞清楚这个问题，首先要明白字体是怎么回事。一种字体有粗体、斜体、下划线、删除线  等诸多属性。  

  但是并不是所有字体都做了这些，一些不常用的字体，或许就只有个正常体，如果你用 Italic，  就没有效果了,这时候就要用  Oblique.  

  可以理解成 Italic是使用文字的斜体，Oblique是让没有斜体属性的文字倾斜！  

  **font-weight**   

  作用:设置文字的粗细  取值:  

  它有两种取值,一种是单次表示:  normal:正常粗细  

  bold:加粗  

  另一种是整数表示,整数越大,字体越粗  100, 200, 300, …, 900  




  **font-size**   

  作用:设置字体大小  

  取值:  

  字体大小的取值是一个数值加上单位,它的单位有  px , pt ,但一般都使用  px,表示多少  

  个像素,如  20px,表示字体的宽和搞  

  说明:  

  注意，实际上它设置的是字体中字符框的高度；实际的字符字形可能比这些框高或矮（通  

  常会矮）。  

  各关键字对应的字体必须比一个最小关键字相应字体要高，并且要小于下一个最大关键字  对应的字体。  

  **font-family**   

  作用:设置文字字体  

  取值:各种字体名称  

  如果字体是中文,尽量用双引号括起来  QSS中 font-family只能指定一种字体  

  连写格式  

  字体属性可以单写,也可以连写,连写格式如下:  

  **font:  style**  

  **weight**  

  **size**  

  **family**  

  这种书写格式中的注意点:  

  style和 weight的位置可以交换,并且可以省略;  size不能被省略  

  size和  family必须写在其他两个属性的后面,并且位置不能交换  family可以省略,省略后使用默认字体  

  举个例子:  QTextEdit{  

  font: normal normal 30px "隶书";  background-color:  skyblue;  

  }  




  文本属性  

  **text-align**   

  作用:设置文本的对齐方式  

  取值:  top  

  bottom  

  left  

  right  

  center  

  注意点:支持这个属性的控件目前只有  QPushButton和   QProgressBar.  格式:  

  **text-align:**水平对齐方式**(left,  right, center)**垂直对齐方式**(top   bottom center);**  

  举个例子  

  QPushButton{  

  background-color:   pink;  min-height:   80px;  text-align:  left  top;  }  

 

  **text-decoration**   

  作用:给文本添加装饰  取值:  

  none:没有装饰  underline:下划线  overline:上划线  line-through:删除线  

  举个例子:  

  QTextEdit{  

  font: normal normal 30px "微软雅黑";  

  }  

  #text_edit_1{  

  text-decoration:  none;  

  }  

  #text_edit_2{  

  text-decoration:  underline;  

  }  

  #text_edit_3{  

  text-decoration:  overline;  

  }  

  #text_edit_4{  

  text-decoration:   line-through;  }  

 

  padding和  margin   

  盒模型中的 padding和  margin都可以连写,也可以单独写,它们都能完成四个方向上  的边距设置,默认情况下都是   0.  

  与边框和其他连写格式一样,如果它们连写时,最多可以指定   4个值,最少指定  1个值,  指定 4个时,分别表示上右下左方向的边距,省略时,也有相同的效果,即左省略时默认和  右一样,下省略时默认和上一样,右省略时和上一样.  

  设置边距时,数值后面必须要带像素单位,即    px;  

  **padding**   

  padding既可以连写也可以分四个方向单独设置,  

  格式如下  

  **padding:**上右下左**;**  或  **padding-top: ?px;**  **padding-right: ?px;**  **padding-bottom: ?px;**  **padding-left: ?px;**  

  **margin**   

  格式与 padding类似,具体如下  

  **margin:**上右下左**;**  或  **margin -top: ?px;**  **margin -right: ?px;**  **margin -bottom: ?px;**  **margin -left: ?px;**  

  由于 Qt将整个盒子看做是一个控件,因此在布局时,不会考虑每个盒子的垂直方向的外边  

  距是否有合并现象等,所以一个控件的外边距只会对自己产生影响,不会对其他的控件产生  

  影响.  

  下面看一个例子:  

  QTextEdit{  

  border:  2px  solid red;  background:   skyblue;  background-clip:   margin;  font:  normal  normal 30px "微软雅黑";  }  


  #text_edit_1{  margin:   5px;  

  padding:   5px;  text-decoration:   none;  }  

  #text_edit_2{  margin:   10px;  padding:   10px;  text-decoration:   underline;  }  

  #text_edit_3{  margin:   15px;  padding:   15px;  text-decoration:   overline;  }  

  #text_edit_4{  margin:   20px;  padding:   20px;  text-decoration:   line-through;  }  


  width  与  height    

  **width, height**   

  这两个属性设置的是盒子内容的宽高.  

  这两个属性只对子控件选择器选中的对象有效  这两个属性的取值均是像素值,即数字加像素单位   px;  

  **max-width min width** 与  **max-height  min-height**   

  这四个属性对所有的 widget都有效,用来设置盒子内容的最小或最大尺寸  当最小宽度与最大宽度相等时,意味着给这个盒子的内容设置了一个固定宽度.  当最小高度与最大高度相等时,意味着给这个盒子的内容设置了一个固定高度.  

  举个例子:  

 

```css
 QComboBox{  
     background-color:  skyblue;  border: 1px  solid red;  padding:  10px;  
     margin:  10px;  
     background-clip:   content;  min-height:   50px;  max-height:   50px; 
}  
```



  outline（轮廓）是控件有焦点时,绘制在边框边缘的外围,可起到突出作用,轮廓线不占据控  

  件,也不一定是矩形. 

+ outline-color  
+ outline-offset  
+ outline-style  
+ outline-radius  



  Brush类型介绍  

  brush一般用来设置颜色,其取值有  3种,分别是   Color, Gradient和  PaletteRole,下面简单介  

  绍一下  

  **Color**   

  color本身又支持很多格式,列举所有格式,如下:  

  rgb(r, g, b) 每个数字表示每个通道的值,依次分别是红绿蓝  rgba(r, g, b, a)与   rgb相同, a代表 α通道,是一个范围   0~1的浮点数,表示透明度,  1代表不  透明, 0表示全透明  


  hsv(h, s, v)  

  hsva(h, s, v, a)  

  #rrggbb: 16进制表示的  rgb值,每个值占两位,但如果每个通道的两位都一样,可以简写为  #rgb,如#66FFAA可以简写为    #6FA,并且大小写不敏感.  name:常见的表示颜色的单次,如   red, green, blue, yellow,  purple等  常用的是 rgb, rgba, #rrggbb, name  

  **Gradient**   

  可实现渐变效果,三种取值:  qlineargradient线性渐变  qradialgradient径向渐变  qconicalgradient锥形渐变  

```css
QTextEdit{  
    border: 2px  solid red;  
    background-color: qlineargradient(x1:0,  y1:0, x2:1, y2:1, stop:0  #ace,  stop:  0.4  #f96, stop:1   #ace);  background-clip:  margin;  
    font:  normal  normal 30px "微软雅黑";  }  
QTextEdit{  
    border: 2px  solid red;  
    background: qradialgradient(cx:0,  cy:0, radius:  1,  fx:0.5,  fy:0.5, stop:0 #ace,  stop:1   #f96);  background-clip:  margin;  
    font: normal normal 30px "微软雅黑";  
}  

QTextEdit{  
    border: 2px  solid red;  
    background: qconicalgradient(cx:0.5,  cy:0.5, angle:30,  stop:0  #ace,  stop:1   #f96);  
    background-clip:  margin;  
    font: normal normal 30px "微软雅黑";  
}  

```

  **Qt**官方链接  

  链接地址:  http://doc.qt.io/qt-5/stylesheet.html  

##   与  **CSS**的对比

  CSS与 Qss的基本语法一模一样,这里主要对比选择器与属性  