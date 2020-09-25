# 层级关系

## 场景

`Scene`

+ 场景大小不能更改
+ 场景不能嵌套使用

## 层

父节点与子节点的关系,子节点相对于父节点存在的

## 节点

+ 节点没有大小

## 脚本执行顺序

### 使用统一的控制脚本来初始化其他脚本

```js
// Game.js

const Player = require('Player');
const Enemy = require('Enemy');
const Menu = require('Menu');

cc.Class({
    extends: cc.Component,
    properties: {
        player: Player,
        enemy: Enemy,
        menu: Menu
    },

    onLoad: function () {
        this.player.init();
        this.enemy.init();
        this.menu.init();
    }
});
```

### 设置组件优先级

组件的 executionOrder。executionOrder ,默认为0,只对onLoad`、`onEnable`、`start`、`update` 和 `lateUpdate有效

```js
editor: {
    executionOrder: -1
},
```