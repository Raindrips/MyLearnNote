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

Chrome 禁用了 WebAudio 的自动播放，而音频默认是使用 Web Audio 的方式加载并播放的，此时用户就需要在 **资源管理器** 中选中音频资源，然后在 **属性检查器** 中将音频的加载模式修改为 DOM Audio 才能在浏览器上正常播放。