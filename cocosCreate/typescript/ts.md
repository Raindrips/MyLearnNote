## 配置

ts常用配置方案

```json
{
    "compilerOptions": {
        "module": "commonjs",
        "lib": [ "es2015", "es2017", "dom" ],
        "target": "es5",
        "experimentalDecorators": true,
        "skipLibCheck": true,
        "outDir": "temp/vscode-dist"
    },
    "exclude": [
        "node_modules",
        "library",
        "local",
        "temp",
        "build",
        "settings"
    ]
}
```

使用装饰器声明类属性

```typescript
// 使用装饰器声明 CCClass
@ccclass 
export default class NewClass extends cc.Component { 
    // 使用 property 装饰器声明属性，括号里是属性类型，装饰器里的类型声明主要用于编辑器展示
    @property(cc.Node)     
    label: cc.Node = null; 
    // 也可以使用完整属性定义格式
    @property({
        type: cc.Integer
        visible: false
    })
      myInteger = 1;
    //成员对象
    text: string = 'hello';
    // 成员方法
    onLoad() {
        // init logic
    }
}
```

某些特殊数据类型需要显示声明类型

```typescript
@property({
    type: cc.Texture2D,
})
texture: cc.Texture2D = null;
@property({
    type: cc.Texture2D,
})
textures: cc.Texture2D[] = [];
```



## 使用命名空间

在 **属性检查器** 里设置该脚本 `导入为插件`,设为插件的脚本将不会进行模块化封装，也不会进行自动编译。

```typescript
//全局变量
window.data = {};
```