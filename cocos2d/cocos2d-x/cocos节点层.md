# 音频处理

cocos2d-x能够跨平台支持音频系统

## 初始化音频资源

预处理音频资源,可以让加载时不会卡顿,建议放在 `runWithScene` 函数之后

```cpp
//初始化背景音乐
SimpleAudioEngine::getInstance()->preloadBackgroundMusic(string& soundfile);

//初始化音效
SimpleAudioEngine::getInstance()->preloadEffect(string& soundfile);
```

## 播放音乐

```cpp
//背景音乐的播放
SimpleAudioEngine::getInstance()->playBackgroundMusic();

//关闭背景音乐
SimpleAudioEngine::getInstance()->stopBackgroundMusic();

//暂停背景音乐的播放
SimpleAudioEngine::getInstance()->stopBackgroundMusic();

void preloadBackgroundMusic();

void preloadBackgroundMusic();


```

## 背景音乐放的位置





## OpenAL引擎

该引擎封装了Open AL 音频处理库

需要导入头文件

```cpp
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
```



使用函数

```cpp

 /** 
     *播放音乐
     * @param filePath 音频文件路径
     * @param loop 音频文件是否循环
     * @param volume 音乐大小
     * @param profile 音频实例的配置文件。当没有指定配置文件时，将使用默认配置文件。
     * @return An audio ID. It allows you to dynamically change the behavior of an audio instance on the fly.
     *
     * @see `AudioProfile`
     */
    static int play2d(const std::string& filePath, bool loop = false, float volume = 1.0f, const AudioProfile *profile = nullptr);
```

## 播放音乐

```cpp
// 循环播放音乐
auto backgroundAudioID = AudioEngine::play2d("mymusic.mp3", true);

// 播放一次
auto soundEffectID = AudioEngine::play2d("gameeffect.mp3", false);
```

## 暂停

```cpp
//通过音乐返回的ID来操作
// pause music.
AudioEngine::pause(audioID);

// pause all sound effects.
AudioEngine::pauseAll();
```



## 恢复

```cpp
// resume music.
AudioEngine::resume(audioID);

// resume all sound effects.
AudioEngine::resumeAll();
```



## 停止

```cpp
// stop music.
AudioEngine::stop(audioID);

// stops all running sound effects.
AudioEngine::stopAll();
```

移动设备上的游戏会遇到一些特殊的情景，比如游戏应用被切换至后台又切换回前台，正在玩游戏的时候电话来了，电话打完继续玩游戏，这些你在进行声音控制的时候都得考虑。

## 预加载

加载音乐和音效通常是个耗时间的过程，为了防止由加载产生的延时导致实际播放与游戏播放不协调的现象，在播放音乐和音效前，可以预加载音乐文件。

```cpp
#include "AudioEngine.h"
using namespace cocos2d::experimental;


// pre-loading background music and effects. You could pre-load
// effects, perhaps on app startup so they are already loaded
// when you want to use them.
AudioEngine::preload("myMusic1.mp3");
AudioEngine::preload("myMusic2.mp3");


// unload a sound from cache. If you are finished with a sound and
// you wont use it anymore in your game. unload it to free up
// resources.
AudioEngine::uncache("myEffect1.mp3");
```

通过回调, 你也可以 **`preload`** 完成后进行一些操作

```cpp
AudioEngine::preload("myMusic1.mp3", [](bool success){
    //do some stuff 
});
```

## 音量控制

可以像下面这样，通过代码控制音乐和音效的音量：

```cpp
#include "AudioEngine.h"
using namespace cocos2d::experimental;

// setting the volume specifying value as a float
// set default volume
AudioEngine::setVolume(audioID, 0.5);
```