音频播放的方式有两种,一个是组件精通加载的方式播放,一个是直接使用代码引擎进行播放

## 音频cc.AudioSource

### 属性

| 属性         | 说明                         |
| ------------ | ---------------------------- |
| Clip         | 用来播放的音频资源对象       |
| Volume       | 音量大小，范围在 0~1 之间    |
| Mute         | 是否静音                     |
| Loop         | 是否循环播放                 |
| Play on load | 是否在组件激活后自动播放音频 |
| preload      | 是否在未播放的时候预先加载   |

### 脚本控制

```js
//播放音乐
this.audioSource.play();
//暂停音乐
this.audioSource.pause();
```

## AudioEngine

AudioEngine 是纯代码播放,不需要通过组件的方式进行,只需要`cc.AudioClip`音频资源便可以直接进行播放

```js
// this.audio 是 cc.AudioClip 组件
this.current = cc.audioEngine.play(this.audio, false, 1);
//停止播放音乐
cc.audioEngine.stop(this.current);
```

## 兼容性
```ts
audioSource=this.node.getCompoent(cc.AudioSource);
//播放
audioSource.player();

//暂停
audioSource.pause()
```

## AudioEngine

直接使用 `cc.audioEngine.play(audio, loop, volume);` 播放

```ts
//声明音频资源
audio:cc.AudioClip;

//播放音频资源
this.current = cc.audioEngine.play(this.audio, false, 1);

//播放音效
cc.audioEngine.playEffect();
//播放音乐
cc.audioEngine.playMusic();
```



## 声音的加载模式

在资源管理器内选中一个 audio，属性检查器内会有加载模式的选项。**这个选项只对 Web 平台有效**

通过 Web Audio 方式加载的声音资源，在引擎内是以一个 buffer 的形式缓存的。这种方式的优点是兼容性好，问题比较少。缺点是占用的内存资源过多。

通过生成一个标准的 audio 元素来播放声音资源，缓存的就是这个 audio 元素。使用标准的 audio 元素播放声音资源的时候，在某些浏览器上可能会遇到一些限制。比如：每次播放必须是用户操作事件内才允许播放（Web Audio 只要求第一次），且只允许播放一个声音资源等。

Chrome 禁用了 WebAudio 的自动播放，而音频默认是使用 Web Audio 的方式加载并播放的，此时用户就需要在 **资源管理器** 中选中音频资源，然后在 **属性检查器** 中将音频的加载模式修改为 DOM Audio 才能在浏览器上正常播放。