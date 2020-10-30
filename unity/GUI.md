## GUI 界面

界面类是Unity手工定制的GUI的接口。Unity引擎早期的界面绘制系统

因为GUI的绘制总是在每帧都要重新绘制，而且他的事件不支持委托或者消息这样的机制，处理起来极度麻烦，让绘制和控件逻辑处理代码混合了。

UI和你的世界摄像机无关，他只关心游戏视窗。

GUI的原点参照是游戏视窗的左上角。（单位：像素)

| 静态变量        | 说明                                             |
| --------------- | ------------------------------------------------ |
| backgroundColor | 全局染色由GUI渲染的所有背景元素                  |
| changed         | true如果任何控制按钮改变输入数据的值那么返回true |
| color           | 全局GUI染色，将影响背景和文本颜色                |
| contentColor    | 全局染色由GUI渲染的所有文本，得到乘以颜色        |
| depth           | 当前执行的GUI行为的深度排序                      |
| enabled         | 判断GUI是否启用了                                |
| matrix          | GUI变换矩阵                                      |
| skin            | 全局皮肤使用                                     |
| tooltip         | 控制鼠标当前通过对象的提升信息，或具有键盘焦点   |

| 静态方法                            | 说明                                                         |
| ----------------------------------- | ------------------------------------------------------------ |
| BeginGroup                          | 开始组，必须配套以EndGroup结束关闭容器                       |
| BeginScrollView                     | 在你的GUI里，开始一个滚动视图，注意BeginScrollView和EndScrollView它们是成对出现的 |
| Box                                 | 在界面布局创建盒子。盒子包含文本，图像或者带有工具提示的这些的组合，通过使用GUIContent参数。你也可以使用GUIStyle去调整盒子中所有的物体的布局，文本颜色和其他属性。 |
| BringWindowToBack                   | 使一个特定的窗口到浮动窗口的后面。                           |
| BringWindowToFront                  | 使一个特定的窗口到浮动窗口的前面                             |
| Button                              | 创建一个单次按下按钮。用户点击按钮事件立即触发。             |
| DragWindow                          | 创建一个可拖动窗口                                           |
| DrawTextureDrawTextureWithTexCoords | 在给定的纹理坐标矩形范围内绘制纹理。使用该函数为了裁剪或者铺盖图像到指定的矩形内部 |
| EndGroup                            | 结束组，和开数组BeginGroup成对使用                           |
| EndScrollView                       | 结束被开始的滚动视图，注意BeginScrollView和EndScrollView它们是成对出现的 |
| FocusControl                        | 移动键盘焦点到被命名的控件                                   |
| FocusWindow                         | 使一个窗口成为活动窗口                                       |
| GetNameOfFocusedControl             | 获取有焦点被命名控件的名字                                   |
| HorizontalScrollbar                 | 创建水平滚动条,可以使用scrollView代替                        |
| Window                              | 创建一个弹出窗口                                             |



| Delegates 委托 | 说明                                      |
| :------------- | :---------------------------------------- |
| WindowFunction | 在窗口内回调绘制GUI(和GUI.Window一起使用) |

```c#
public Texture aTexture;	//GUI引用
void OnGUI() {

    if (!aTexture) {
        Debug.LogError("Assign a Texture in the inspector.");
        return;
    }
    GUI.DrawTexture(new Rect(10, 10, 60, 60), aTexture, ScaleMode.ScaleToFit, true, 10.0F);

    if (GUI.Button(new Rect(10, 10, 50, 50), btnTexture))
        Debug.Log("Clicked the button with an image");
    if (GUI.Button(new Rect(10, 70, 50, 30), "Click"))
        Debug.Log("Clicked the button with text");
}
```

