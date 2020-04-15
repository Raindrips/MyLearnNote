# 物理引擎

物理引擎能够模仿真实世界的运动规律,使精灵能够做出自由落体,抛物线运动,互相碰撞,反弹等效果

使用物理引擎还可以进行碰撞检测,往往自己写的碰撞检测没有优化而效率低下

## 核心概念

1. 世界(world)游戏中的物理世界
2. 物体(body)构成物理世界的基础,具有位置,旋转角度等特性,他们上面的任何两点之间的距离是完全不变的可以称为刚体(rigid body)
3. 形状 (Sharp)物体的形状,一个二维碰撞的集合结构
4. 接触点(Contact) 管理检测碰撞
5. 关节(joint) 把两个或多个物体固定到一起的约束

## 物体与精灵之间的关系

物理引擎本身不包括精灵,通常是通过程序使精灵与物理引擎进行连接



## cocos2d自带引擎

```c++
c

//创建场景对象
static Scene* createWithPhysics();

//初始化具有物理引擎的的场景对象

```





## Box2d 引擎


