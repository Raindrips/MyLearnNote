# Cocos2d-x test

## Action Manage Test

Sprite运行动画

```c++
//运行动画
Action * Node::runAction(Action* action);

//运行运行连续的动画
node->runAction(Sequence::create(
    MoveBy::create(1, Vec2(150,0)),	//调用动画
    CallFuncN::create(CC_CALLBACK_1(LogicTest::bugMe,this)),  //调用函数
                                                nullptr));
```

延时5秒后运行

```cpp
schedule( CC_SCHEDULE_SELECTOR(CLASS::FUNC), 3); 

//延时3秒执行代码
CLASS::FUNC{
	unschedule( CC_SCHEDULE_SELECTOR(CLASS::FUNC) );
}
```

两个动画同时运行

```
auto pMove1 = MoveBy::create(2, Vec2(200, 0));
auto pMove2 = MoveBy::create(2, Vec2(-200, 0));
Sequence::createWithTwoActions(pMove1, pMove2);
```



反向播放刚刚运行的动画

```c++
auto director = Director::getInstance();
director->getActionManager()->resumeTarget(ACTION);
```



