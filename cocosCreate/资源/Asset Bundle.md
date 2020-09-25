# Asset Bundle

Asset Bundle 主要用于对工程中的资源按照开发者的意愿进行模块划分，可以将不同场景不同需求的资源划分在多个包中，从而可以减少首次下载和加载游戏时所需要的时间，也可以跨项目复用

获取Asset Bundle资源

```js
let bundleA = cc.assetManager.getBundle('bundleA');
```

