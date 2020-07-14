# Box2D引擎

## 核心概念

1. 世界`b2World ` 物理引擎中的物理世界
2. 物体`b2Body`,物理世界中的物体
3. 形状(`b2Shape`),物体中的形状
4. 夹具(`b2Joint`) 将形状固定在物体的装置上,有了形状才能具有碰撞等物理特性
5. 关节(`b2Fixture`) 引擎中的关节

## 使用Box2D引擎

1. 创建物理世界
2. 指定世界边界
3. 创建世界中的物体
4. 创建形状
5. 创建夹具
6. 使用夹具固定到物体上
7. 连接精灵和物体
8. 碰撞检测

## 创建box2D物理引擎

引入一个头文件

```cpp
#include "Box2D/Box2D.h"
```

创建一个世界并指定它的加速度方向

```cpp
world = new b2World(b2Vec2(0, -10));
```

创建一个运动的物体

```cpp
//定义运动的物体
b2BodyDef def;
//运动的类型
def.type = b2BodyType::b2_dynamicBody;
//运动的位置
def.position = b2Vec2(4, 5);
//创建物体
b2Body* body= world->CreateBody(&def);
```

然后让这个物体和sprite绑定在一起

```cpp
 auto s = Sprite::create();
  s->setTextureRect(Rect(0, 0, 80, 80));
  s->setPosition(def.position.x*RAD, def.position.y*RAD);
  this->addChild(s);
  body->SetUserData(s);
```

调用update函数

```cpp
void CLASS::update(float dt)
{
  world->Step(dt, 8, 3);
  Sprite *s;
  for (b2Body *b = world->GetBodyList(); b!=nullptr; b=b->GetNext())
  {
	if (b->GetType()== b2BodyType::b2_dynamicBody)
	{
	  if (b->GetUserData())
	  {
		s=(Sprite*)b->GetUserData();
		s->setPosition(b->GetPosition().x*RAD, b->GetPosition().y*RAD);
	  }
	}
  }
```

## 创建一个Box2d世界

1. 创建一个物理世界

```cpp
#include "Box2D\Box2D.h"
```

利用`b2word`创建一个对象，并且指定这个物理世界中的加速度方向。

```cpp
word = new b2World(b2Vec2(0,-10));                        //指定物理世界的加速度
```

创建一个运动的物体

```
b2BodyDef def;
def.position = b2Vec2(10,10);
def.type = b2_dynamicBody;
word->CreateBody(&def);
```

之后为了能够显示出创建的这个物体的运动情况，在update中，可以通过一个循环来便利整个物理世界的物体列表，找到我们定义的这个物体就可以输出他在物理世界中自由落体的坐标变化

```
void HelloWorld::update(float dt)
{
	word->Step(dt, 8, 3);
	for(b2Body *b = word->GetBodyList(); b; b = b->GetNext())
	{
		if(b->GetType() == b2_dynamicBody)
		{
			log("x:%f, y:%f", b->GetPosition().x, b->GetPosition().y);
		}
	}
}
```

将创建的那个物体和sprite绑定在一起。

```
b2Body *b =  word->CreateBody(&def);
auto sprite = Sprite::create();
addChild(sprite);
sprite->setTextureRect(Rect(0,0,80,80));
b->SetUserData(sprite);
```

设置`box2d`模拟范围

```cpp
AppDelegate::applicationDidFinishLaunching();
glview->setDesignResolutionSize(800,600, ResolutionPolicy::SHOW_ALL);
```

设置初始位置

```cpp
s->setPosition(b->GetPosition().x * RATIO, b->GetPosition().y*RATIO);
def.position = b2Vec2(3,5);
```

不断更新图像

```cpp
void HelloWorld::update(float dt)
{
	word->Step(dt, 8, 3);
	Sprite *s;
	for(b2Body *b = word->GetBodyList(); b; b = b->GetNext())
	{
		if(b->GetType() == b2_dynamicBody)
		{
			if(b->GetUserData())
			{
				s = (Sprite*)b->GetUserData();
				s->setPosition(b->GetPosition().x * RATIO, b->GetPosition().y*RATIO);
			}
		}
	}
}
```

所以在update函数里面就要检查body对象是否绑定了图形，然后获取到他所绑定的图形，进行重新设置当前的图形坐标。