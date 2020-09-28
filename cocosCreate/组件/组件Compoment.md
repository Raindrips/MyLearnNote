# cc.Compoent组件的使用

cc.Compoent是每个组件的基类,组件在加载的使用运行,

## 组件属性

|   参数名    | 说明                                       |       类型       |  默认值   | 备注                                                         |
| :---------: | ------------------------------------------ | :--------------: | :-------: | ------------------------------------------------------------ |
|    type     | 限定属性的数据类型                         |      (Any)       | undefined | 详见 [type 参数](https://docs.cocos.com/creator/manual/zh/scripting/reference/class.html#type) |
|   visible   | 在 **属性检视器** 面板中显示或隐藏         |     boolean      |   (注1)   | 详见 [visible 参数](https://docs.cocos.com/creator/manual/zh/scripting/reference/class.html#visible) |
| displayName | 在 **属性检视器** 面板中显示为另一个名字   |      string      | undefined |                                                              |
|   tooltip   | 在 **属性检视器** 面板中添加属性的 Tooltip |      string      | undefined |                                                              |
|  multiline  | 在 **属性检视器** 面板中使用多行文本框     |     boolean      |   false   |                                                              |
|  readonly   | 在 **属性检视器** 面板中只读               |     boolean      |   false   |                                                              |
|     min     | 限定数值在编辑器中输入的最小值             |      number      | undefined |                                                              |
|     max     | 限定数值在编辑器中输入的最大值             |      number      | undefined |                                                              |
|    step     | 指定数值在编辑器中调节的步长               |      number      | undefined |                                                              |
|    range    | 一次性设置 min, max, step                  | [min, max, step] | undefined | step 值可选                                                  |
|    slide    | 在 **属性检视器** 面板中显示为滑动条       |     boolean      |   false   |                                                              |

## 组件的属性

组件的属性声明需要加上`@property`装饰器,将该**装饰器**加载属性上,之后便可以在编辑器中调用该组件的时候,可以通过编辑的对话框进行该属性的编辑

```ts
//声明一个基本数据类型
@property
text:string;			//表示一个string类型的数据

//声明一个cocos creator特殊数据类型
@property(cc.Label)		//文字标签类
label:cc.Label

@preperty(cc.Node)		//节点类型
node:cc.Node
```



## 组件的生命周期

生命周期回调函数主要有

- onLoad
- start
- update
- lateUpdate
- onDestroy
- onEnable
- onDisable

#### onLoad

在节点首次激活时触发,通常我们会在 `onLoad` 阶段去做一些初始化相关的操作

### start

`start` 回调函数会在组件第一次激活前，也就是第一次执行 `update` 之前触发

### update

游戏开发的一个关键点是在每一帧渲染前更新物体的行为，状态和方位。

### lateUpdate

`update` 会在所有动画更新前执行，但如果我们要在动效（如动画、粒子、物理等）更新之后才进行一些额外操作，或者希望在所有组件的 `update` 都执行完之后才进行其它操作

### onEnable

当组件的 `enabled` 属性或者 `active`从 `false` 变为 `true` 时，会激活 `onEnable` 回调。

倘若节点第一次被创建且 `enabled` 为 `true`，则会在 `onLoad` 之后，`start` 之前被调用。

### onDisable

当组件的 `enabled` 属性从 `true` 变为 `false` 时，或者所在节点的 `active` 属性从 `true` 变为 `false` 时，会激活 `onDisable` 回调。

### onDestroy

当组件或者所在节点调用了 `destroy()`，则会调用 `onDestroy` 回调，并在当帧结束时统一回收组件

#### 调用顺序

生命周期函数调用顺序为：

`onLoad` -> `onEnable` -> `start` -> `update` -> `lateUpdate` -> `onDisable` -> `onDestroy`。

 `start` 和 `update` 必须组件在enable的时候才会调用的回调

## 组件的一些属性和方法

每个组件被添加后都有`Node`类型的引用,可以直接调用到``node``节点对象

```ts
//访问组件下的node节点
this.node;
```



