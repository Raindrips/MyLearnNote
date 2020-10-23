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

## 数据类型

```cpp
//二维向量
b2Vec2 gravity;
//设置坐标属性
gravity.Set(0.0f,-10.0f)
```

## 物理组建

## 创建box2D物理引擎

引入一个头文件

```cpp
#include "Box2D/Box2D.h"
```

### 世界

利用`b2word`创建一个对象，并且指定这个物理世界中的加速度方向。

```cpp
//创建一个世界并指定它的加速度方向
b2World* world = new b2World(b2Vec2(0, -10));
```

### 物体

```cpp
//创建物理组建
b2BodyDef gound;
//创建形状
b2EdgeShape box;
//设置形状大小
box.Set(b2Vec2(0,0),b2Vec2(vsize.width,0));
//添加形状
gound->CreateFixture(&gound,0);
//设置物理种类
gound.type=b2_dynamicBody; 
//创建物理属性
b2FixtureDef fixture;
//创建物理形状
b2PolygonShape dynamicBox;
dynamicBox.SetAsBox(0.5f,0.5f);
//绑定物理形状
fixture.shape=&gound;
fixture.density=1.0f;		//密度
fixture.friction=0.3f;		//摩擦力
fixture.restitution=0.6f;	//恢复
```

### 创建刚体

```cpp
//物理对象添加到世界后就会变成刚体
b2Body* body = _world->CreateBody(&bodydef);
//绑定形状
body->CreateFixture(&fixdef);
```



### 更新

```cpp
//世界更新
world->Step(dt,8,1);
//遍历
for (b2Body *b = _world->GetBodyList(); b != nullptr; b = b->GetNext())
{
}
```

### 碰撞检测

```cpp
//继承碰撞监听属性
class My :public b2ContactListener{
    //开始碰撞
    virtual void BeginContact(b2Contact* contact){
        ContractInfo info;
        info.fixtureA=contact->GetFixtureA();
        info.fixtureB=contact->GetFixtureB();
        
        destoryList.push_back(info);
    }

    //结束碰撞
    virtual void BeginContact(b2Contact* contact);
};
```

#### 碰撞过滤



### 物体类型

```}cpp
/// static: zero mass, zero velocity, may be manually moved
/// kinematic: zero mass, non-zero velocity set by user, moved by solver
/// dynamic: positive mass, non-zero velocity determined by forces, moved by solver
enum b2BodyType
{
	b2_staticBody = 0,
	b2_kinematicBody,
	b2_dynamicBody
}
```

### 设置夹具

```cpp
b2FixtureDef fixDef;
//密度
fixDef.density = 1;
//摩擦力
fixDef.friction = 0.3;
//形状
b2PolygonShape polygon = {};
polygon.SetAsBox(0.5, 0.5);
fixDef.shape = &polygon;
body->CreateFixture(&fixDef);
```

## 

### 创建一个运动的物体

#### 初始化

定义box2d数据节点

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

设置初始位置

```cpp
s->setPosition(b->GetPosition().x * RATIO, b->GetPosition().y*RATIO);
def.position = b2Vec2(3,5);
```

所以在update函数里面就要检查body对象是否绑定了图形，然后获取到他所绑定的图形，进行重新设置当前的图形坐标。

#### 绑定精灵

然后让这个物体和sprite绑定在一起

```cpp
b2Body *body =  word->CreateBody(&def);
auto s = Sprite::create();
s->setTextureRect(Rect(0, 0, 80, 80));
s->setPosition(def.position.x*RAD, def.position.y*RAD);
this->addChild(s);
//将创建的那个物体和sprite绑定在一起。
body->SetUserData(s);
```

#### 更新

调用update函数

之后为了能够显示出创建的这个物体的运动情况，在update中，可以通过一个循环来便利整个物理世界的物体列表，找到我们定义的这个物体就可以输出他在物理世界中自由落体的坐标变化

```cpp
void CLASS::update(float dt)
{
    //更新速率
    world->Step(dt, 8, 3);
    Sprite *s;
    //遍历物理世界
    for (b2Body *b = world->GetBodyList(); b!=nullptr; b=b->GetNext())
    {
        if (b->GetType()== b2BodyType::b2_dynamicBody)
        {
            log("x:%f, y:%f", b->GetPosition().x, b->GetPosition().y);
            //获取节点数据并进行操作
            if (b->GetUserData())
            {
                s=(Sprite*)b->GetUserData();
                s->setPosition(b->GetPosition().x*RAD, b->GetPosition().y*RAD);
            }
        }
    }
}
```

