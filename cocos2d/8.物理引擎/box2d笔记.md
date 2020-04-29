1、创建一个物理世界

首先要引入一个头文件#include "Box2D\Box2D.h"

之后利用b2word创建一个对象，并且指定这个物理世界中的加速度方向。

word = new b2World(b2Vec2(0,-10));                        //指定物理世界的加速度

最后还要重写一下update函数，这个函数在之前的计时器学习的时候已经说过，每一帧的变动都将自动执行这个函数。所以我们要通过这个函数来进行创建的物理世界的刷新。


2、创建一个运动的物体

我们将自己实现一个在物理世界添加一个物体的函数，在其中调用createbody来创建一个物体，该函数接受一个参数。这个参数是关于创建的这个物体的一些基本信息，比如位置，动态还是静态等等。

    	b2BodyDef def;
    	def.position = b2Vec2(10,10);
    	def.type = b2_dynamicBody;
    	word->CreateBody(&def);


之后为了能够显示出创建的这个物体的运动情况，在update中，可以通过一个循环来便利整个物理世界的物体列表，找到我们定义的这个物体就可以输出他在物理世界中自由落体的坐标变化

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


最后要在init函数里面scheduleUpdate()用这个函数启动update


直接看坐标的变化可能不是很明显，那么这次通过添加一个图形来看

首先，自然要先创建一个sprite。

然后将创建的那个物体和sprite绑定在一起。

    b2Body *b =  word->CreateBody(&def);
    	auto sprite = Sprite::create();
    	addChild(sprite);
    	sprite->setTextureRect(Rect(0,0,80,80));
    	b->SetUserData(sprite);



因为BOX2d 物理世界中，它的位置是用米来进行度量的，并不是利用像素。BOX2D有一个比较精确的模拟范围就是10M。所以我们要根据像素和米的单位进行映射，找出对应的比例关系才能够确定所创建物体要指定的位置。

所以，在AppDelegate::applicationDidFinishLaunching()函数中我们将设置一下程序的分辨率glview->setDesignResolutionSize(800,600, ResolutionPolicy::SHOW_ALL);设置了一个800*600的分辨率，也就是说纵轴的800对应于物理世界中的10m，那么他们的比例就是80。


也就是说，上述的操作形成了这样的一个效果，把整个屏幕变成了800*600的分辨率，在物理世界中，最高的纵坐标范围是10.按照比例缩小的坐标系的范围。


创建的物体在物理世界中的位置可以通过def.position = b2Vec2(3,5);来进行指定，def是这个物体类型信息的一个对象。但是如果要连接一个图形的话，那么图形不是物理世界中，它是cocos2dx里面得东西，是游戏引擎的部分，所以，要通过刚才的比例设置sprite的位置。

s->setPosition(b->GetPosition().x * RATIO, b->GetPosition().y*RATIO);

s是一个sprite的指针。


上面的工作虽然将物理世界得物体和图形进行了绑定，但是，这只是静态的东西。所创建的物体在物理世界中是会因为重力的原因下落的，那么与其绑定的图形也就要随之调整位置，所以在Update函数里面要实时更新图形的位置。

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


所以在update函数里面就要检查body对象是否绑定了图形，然后获取到他所绑定的图形，进行重新设置当前的图形坐标。

