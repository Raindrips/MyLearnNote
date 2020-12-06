# UI控件

### 多分辨率适配

- **Label（文字）** 组件内置了提供各种动态文字排版模式的功能，当文字的约束框由于 Widget 对齐要求发生变化时，文字会根据需要呈现完美的排版效果。
- **Sliced Sprite（九宫格精灵图）** 则提供了可任意指定尺寸的图像，同样可以满足各式各样的对齐要求，在任何屏幕分辨率上都显示高精度的图像。

比如目前安卓设备中 `800 x 480` 和 `1280 x 720` 两种屏幕分辨率，或 iOS 设备中 `1136 x 640` 和 `960 x 640` 两种屏幕分辨率

- **设计分辨率**(`Design Resolution`)
- **适配高度**(`Fit Height`)
- **适配宽度**(`Fit Width`)
- **尺寸**(`Size`)
- **位置**(`Position`):位置会保持在 `(width / 2, height / 2)`，也就是和设计分辨率相同大小的屏幕中心。
- **锚点**(`Anchor`):锚点默认为 `(0.5, 0.5)`,由于 `Canvas` 会保持在屏幕中心位置，因此 **Canvas 的子节点会以屏幕中心作为坐标系原点**.这一点和 `cocos2d-x` 引擎中的习惯不同，请格外注意。

## Label 组件

Label 组件用来显示一段文字，文字可以是系统字体或艺术数字.Label 还具有排版功能.点击 **属性检查器** 下面的 **添加组件** 按钮,然后从 **渲染组件** 中选择 **Label**，即可添加 Label 组件到节点上.

### Label 属性

| 属性               | 功能说明                                                     |
| ------------------ | ------------------------------------------------------------ |
| String             | 文本内容字符串。                                             |
| Horizontal Align   | 文本的水平对齐方式。可选值有 LEFT，CENTER 和 RIGHT。         |
| Vertical Align     | 文本的垂直对齐方式。可选值有 TOP，CENTER 和 BOTTOM。         |
| Font Size          | 文本字体大小。                                               |
| Line Height        | 文本的行高。                                                 |
| SpacingX           | 文本字符之间的间距。（使用 BMFont 位图字体时生效）           |
| Overflow           | 文本的排版方式，目前支持 CLAMP，SHRINK 和 RESIZE_HEIGHT。详情见下方的 [Label 排版](https://docs.cocos.com/creator/manual/zh/components/label.html#label-排版)。 |
| Enable Wrap Text   | 是否开启文本换行。（在排版方式设为 CLAMP、SHRINK 时生效）    |
| Font               | 指定文本渲染需要的字体文件，如果使用系统字体，则此属性可以为空。 |
| Font Family        | 文字字体名字。(使用系统字体时生效)                           |
| Enable Bold        | 是否启用黑体。(使用系统字体或 TTF 字体时生效)                |
| Enable Italic      | 是否启用斜体。(使用系统字体或 TTF 字体时生效)                |
| Enable Underline   | 是否启用下划线。(使用系统字体或 TTF 字体时生效)              |
| Underline Height   | 下划线的高度                                                 |
| Cache Mode         | 文本缓存类型包括 **NONE**、**BITMAP**、**CHAR** 三种。仅对系统字体或 TTF 字体有效，BMFont 字体无需进行这个优化 |
| Use System Font    | 是否使用系统字体                                             |
| `Src Blend Factor` | 混合文本图片时，源图片的取值模式上                           |
| `Dst Blend Factor` | 混合显示两张图片时，目标图片的取值模式                       |
| Materials          | 材质资源，详情请参考文档 [Material](https://docs.cocos.com/creator/manual/zh/render/material.html). |

### 画布canvas

组件随时获得设备屏幕的实际分辨率并对场景中所有渲染元素进行适当的缩放。组件类型`cc.Canvas`

#### 选项

| 选项              | 说明                                                 |
| ----------------- | ---------------------------------------------------- |
| Design Resolution | 设计分辨率（内容生产者在制作场景时使用的分辨率蓝本） |
| Fit Height        | 适配高度（设计分辨率的高度自动撑满屏幕高度）         |
| Fit Width         | 适配宽度（设计分辨率的宽度自动撑满屏幕宽度）         |

适配屏幕尺寸,只会对整个游戏的画面进行缩放或拉伸，并不会修改所在节点的尺寸,节点尺寸将默认跟设计分辨率保持一致，因此不会跟屏幕实际大小完全贴合。

### 对齐挂件weight

Widget 放置在渲染元素上，能够根据需要将元素对齐父节点的不同参考位置。

Weight组件(对齐挂件),会自动根据分辨率进行适配,它能使当前节点自动对齐到父物体的任意位置，或者约束尺寸，让你的游戏可以方便地适配不同的分辨率。

|       选项        |          说明          |
| :---------------: | :--------------------: |
|        Top        |       对齐上边界       |
|      Bottom       |       对齐下边界       |
|       Left        |       对齐左边界       |
|       Right       |       对齐右边界       |
| Horizontal Center |      水平方向居中      |
|  Vertical Center  |      竖直方向居中      |
|      Target       |        对齐目标        |
|    Align Mode     | 指定 widget 的对齐方式 |

#### 对齐模式

Align Mode  

+ ONCE
+ ON_WINDOWS_RESIZE
+ ALWAYS

### 滚动视图ScrollView

| 属性             | 功能说明                                                     |
| ---------------- | ------------------------------------------------------------ |
| Handle           | `ScrollBar` 前景图片,它的长度/宽度会根据 `ScrollView `的 content 的大小和实际显示区域的大小来计算. |
| Direction        | 滚动方向,目前包含水平和垂直两个方向.                         |
| Enable Auto Hide | 是否开启自动隐藏,如果开启了,那么在 `ScrollBar` 显示后的 `Auto Hide Time` 时间内会自动消失. |
| Auto Hide Time   | 自动隐藏时间,需要配合设置 `Enable Auto Hide`                 |



### 按钮Button

按钮组件,点击然后相应一个事件的UI控件,按钮有多种动画过渡效果,Button 组件可以响应用户的点击操作,当用户点击 Button 时,可以触发指定的自定义行为

### 通过脚本设置点击事件

```js
//脚本设置点击事件
let clickEvent = new cc.Component.EventHandler()	  // 	
clickEvent.target = this.node					    // 这个 node 节点是你的事件处理代码组件所属的节点
clickEvent.component = "setting_btn"			     // 这个是代码文件名
clickEvent.handler = "callback"					     // 触发函数
clickEvent.customEventData = "foobar"			     // 自定义函数

let button = this.node.getComponent(cc.Button)	     // 创建按钮组建
button.clickEvents.push(clickEvent)				    // 设置按钮事件
```

### layout水平布局

- 水平布局容器	Horizontal
- 垂直布局容器    Vertical
- 网格布局容器    Grid

点击 **属性检查器** 下面的 **添加组件** 按钮，然后从 **UI 组件** 中选择 **Layout**，即可添加 Layout 组件到节点上。

**注意**:

1. `Layout` 不会考虑子节点的缩放和旋转。
1. `Layout` 设置后的结果需要到下一帧才会更新，除非你设置完以后手动调用 `updateLayout` API

