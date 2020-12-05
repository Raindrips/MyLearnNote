# 场景

## 游戏场景

游戏场景也是显示给玩家查看的一个舞台,每一个游戏场景,都包含了一个节点树,通过每个节点树进行管理

游戏场景保存文件格式为 `.fire`,在cocos creator中,后缀是不显示的,不同类型的名称同样不允许重复

使用脚本进行场景的切换

```tsx
//加载场景  MyScene 表示的是场景的名称
bundle.loadScene('MyScene', (err, scene)=> {
    //切换场景
    cc.director.runScene(scene);
});
```

