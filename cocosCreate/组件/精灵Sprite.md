# 精灵cc.Sprite

## 组件设置

+ Atlas	图集属性
+ type	精灵的模式
  + simple   最普通的模式	
  + filed       填充模式
  + silced  九宫格模式
  + tiled 
  + mesh
+ SizeMode 图片大小模式
  + custom  自定义模式,大小可以自定义
  + RAW		原始大小模式
  + Timmed  自动裁剪透明边距
  +  Trim 裁剪透明的边距
  + Blend 图片ALpha混合模式



## 组件属性

```ts
//获取精灵组件
let sp = this.node.getCompoment(cc.Sprite);
//设置精灵
sp.spriteFrame=null;
```

