# 节点Node

## 节点的属性

```tsx
//禁用节点 同时，它所有子节点，以及子节点上的组件也会跟着被禁用
this.node.active = false;

this.node.activeInHierarchy;	//判断是否激活,如果没有被添加到场景中,是无法激活的

this.node.x = 100;
this.node.y = 50;

this.node.setPosition(100, 50);
this.node.setPosition(cc.v2(100, 50));

this.node.rotation = 90;

this.node.scaleX = 2;
this.node.scaleY = 2;
this.node.setScale(2);

// 更改节点尺寸	
this.node.setContentSize(100, 100);
this.node.setContentSize(cc.size(100, 100));
```



## 常用节点和组件接口

+ name 节点名字
+ active 是否激活
+ position 坐标位置
+ Rotation 旋转
+ Scale 缩放
+ Ancher 锚点
+ Size 大小
+ Color 颜色
+ Opacity 透明度 范围(0~255)
+ Skew 扭曲
+ group 分组
+ parent 父亲节点

## 使用`typescript`脚本

下载[Visual Studio Code](https://visualstudio.microsoft.com/zh-hans/),然后安装该软件

在资源管理器中,新建一个`typescript`脚本,然后用双击打开

## 节点属性

我们在一个组件脚本中，通过 `this.node` 访问当前脚本所在节点。节点默认是激活的，我们可以在代码中设置它的激活状态，方法是设置节点的 `active` 属性

```js
this.node.active = false;
```

这些组件上如果有 `onEnable` 方法，这些方法将被执行

```js
this.node.active = false;
```

这些组件上如果有 `onDisable` 方法，这些方法将被执行

### 更改节点的父节点

```js
this.node.parent = parentNode;
//或者
this.node.removeFromParent(false);
parentNode.addChild(this.node);
```

## 修改节点属性

```cpp
//坐标属性
this.node.x = 100;
this.node.y = 50;
//或者
this.node.setPosition(100, 50);
this.node.setPosition(cc.v3(100, 50,0));
//更改节点旋转
this.node.rotation = 90;
this.node.setRotation(90);
//更改节点尺寸
this.node.setContentSize(100, 100);
this.node.setContentSize(cc.size(100, 100))
// 更改节点锚点位置
this.node.anchorX = 1;
this.node.anchorY = 0;

//获取
mySprite.node.color = cc.Color.RED;
mySprite.node.opacity = 128;
```

### 显示顺序

+ 上面的节点会被下面的节点遮挡
+ 子节点永远都会遮盖住父节

**坐标**

x 向右,y 向上,z 向外

**节点（Node）** 之间可以有父子关系的层级结构，我们修改节点的 **位置（Position）** 属性设定的节点位置是该节点相对于父节点的 **本地坐标系** 

## 创建和销毁节点

### 创建新节点

通过 `new cc.Node()`,并通过场景`addChild`添加

```js
start: function () {
    //创建新节点
    var node = new cc.Node('Sprite');
    //添加脚本组件
    var sp = node.addComponent(cc.Sprite);

    sp.spriteFrame = this.sprite;
    node.parent = this.node;
},
```

### 复制已有节点

​	可以通过 `cc.instantiate` 方法完成

```js
cc.Class({
    extends: cc.Component,
    properties: {
        target: {
            default: null,
            type: cc.Node,
        },
    },
    start: function () {
        var scene = cc.director.getScene();
        //复制节点
        var node = cc.instantiate(this.target);
        node.parent = scene;
        node.setPosition(0, 0);
    },
});
```

## 创建预制节点

和克隆已有节点相似，你可以设置一个预制（Prefab）并通过 `cc.instantiate` 生成节点。使用方法如下：

```js
cc.Class({
    extends: cc.Component,

    properties: {
        target: {
            default: null,
            type: cc.Prefab,
        },
    },

    start: function () {
        //获取场景
        var scene = cc.director.getScene();
        //生成预制节点
        var node = cc.instantiate(this.target);
        node.parent = scene;
        node.setPosition(0, 0);
    },
});
```

### 销毁节点

通过 `node.destroy()` 函数，可以销毁节点。

通过 `cc.isValid` 判断当前节点是否已经被销毁。

除此之外,可以使用`removeFromParent `从父亲节点移除,如果直接移除只是解除引用,可以移除父亲节点后

```js
//销毁节点
node.destroy();
//判断是否被销毁
cc.isValid(node);
//从父亲节点移除
node.removeFromChild();
```

### 获取所有子节点

```tsx
//获取所有子节点
let childern=node.childern;
//子节点通过子节点名称进行查找
let child=node.getChildernName('子节点名称');
```

## 坐标系转换

```ts
//获取当前节点的相对路径
let pos=this.node.convertToNodeSpaceAR(w_pos);	

//获取当前事件节点坐标
let w_pos=this.node.convertToWorldSpaceAR(pos);
```

