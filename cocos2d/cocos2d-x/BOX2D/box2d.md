# box2d

## 创建物理引擎

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





