## JavaScript 对象（Object）

我们像这样声明一个对象（object）：

```js
myProfile = {
    name: "Jare Guo",
    email: "blabla@gmail.com",
    'zip code': 12345,
    isInvited: true
}
```

JavaScript 中的对象无处不在，在函数的参数传递中也会大量使用，比如在 Cocos Creator 中，我们就可以像这样定义 FireClass 对象：



```js
var MyComponent = cc.Class({
    extends: cc.Component
});
```