# Object 对象

UnityEngine.Object

Object对象可以对继承自该对象的方法进行一些操作

| 变量      | 说明                                       |
| --------- | ------------------------------------------ |
| hideFlags | 由用户保存在场景或可修改的对象应该被隐藏么 |
| name      | 对象的名称                                 |

| 方法          | 说明             |
| ------------- | ---------------- |
| GetInstanceID | 返回对象的实例ID |
| ToString      | 返回对象的名称。 |

| 静态方法          | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Destroy           | 删除一个游戏对象、组件或资源                                 |
| DestroyImmediate  | 立即销毁物体对象，强烈建议使用 Destroy 代替。因为它可以永久性地销毁资源，此函数只应在编写编辑器代码时使用 |
| DontDestroyOnLoad | 加载新场景的时候使目标对象不被自动销毁                       |
| FindObjectOfType  | 返回Type类型第一个激活的加载的对象。（效率非常低，不建议使用) |
| FindObjectsOfType | 返回Type类型的所有激活的加载的物体列表。（效率非常低，不建议使用） |
| Instantiate       | 克隆原始物体并返回克隆物体                                   |

| Operators 操作符 | 说明                     |
| ---------------- | ------------------------ |
| bool             | 对象是否存在             |
| operator !=      | 比较如果两个对象不相同。 |
| operator ==      | 比较如果两个物体相同。   |

### Object.Destroy

```c#
// 删除对象,t 指定时间删除
public staticvoid Destroy(Object obj,float t =0.0f);
```

### Object.Instance

```c#
// original 				需要被克隆的原始物体
// parent 					指定的父亲物体
// position 				新物体位置
// worldPositionStays 		 当指定父物体以后仍保持原始的世界坐标
public static Object Instantiate(Object original);

public static Object Instantiate(Object original,Transform parent);

public static Object Instantiate(Object original,Transform parent,boolworldPositionStays);

public static Object Instantiate(Object original,Vector3 position,Quaternion rotation);

public static Object Instantiate(Object original,Vector3 position,Quaternion rotation,Transform parent);
```

可以生成传入的对象,也可以使用泛型的方式

## GameObject 对象

| 变量              | 说明                                         |
| ----------------- | -------------------------------------------- |
| activeInHierarchy | 场景中的游戏对象是否激活                     |
| activeSelf        | 该游戏对象的局部激活状态                     |
| isStatic          | 如果一个游戏对象是静态仅在编辑器API指定      |
| layer             | 游戏对象所在的层，层的范围是在[0...31]之间。 |
| scene             | 场景物体。                                   |
| tag               | 这个游戏对象的标签。                         |
| transform         | 附加于这个游戏对象上的变换。                 |

方法

| 方法                    | 说明                                                         |
| ----------------------- | ------------------------------------------------------------ |
| **AddComponent**        | 添加一个名称为className的组件到游戏对象。                    |
| BroadcastMessage        | 对此游戏对象及其子对象的所有MonoBehaviour中调用名称为methodName的方法 |
| CompareTag              | 此游戏对象是否被标记为tag标签                                |
| **GetComponent**        | 如果这个游戏对象附件了一个类型为type的组件，则返回该组件，否则为空。 |
| GetComponentInChildren  | 返回此游戏对象或者它的所有子对象上                           |
| GetComponentInParent    | 从父对象查找组件                                             |
| GetComponents           | 返回该游戏对象所有type类型的组件列表                         |
| GetComponentsInChildren | 回此游戏对象与其子对象所有type类型的组件。                   |
| GetComponentsInParent   | 返回此游戏对象与其父对象所有type类型的组件。                 |
| SampleAnimation         | 用于任何动画剪辑在给定的时间采样动画。                       |
| SendMessage             | 在这个游戏物体上的所有MonoBehaviour上调用名称为methodName的方法 |
| SendMessageUpwards      | 在这个游戏物体及其祖先物体的所有MonoBehaviour中调用名称为methodName的方法 |
| SetActive               | 激活/停用此游戏对象                                          |

| 静态方法               | 说明                                                      |
| ---------------------- | --------------------------------------------------------- |
| CreatePrimitive        | 创建一个带有原型网格渲染器和适当的碰撞器的游戏对象        |
| Find                   | 找到并返回一个名字为name的游戏物体                        |
| FindGameObjectsWithTag | 返回具体tag标签的激活的游戏对象列表，如果没有找到则为空。 |
| FindWithTag            | 返回标记为tag的一个游戏对象，如果没有找到对象则为空       |



## 预制体

提前制作，然后保存至硬盘，可以持久化使用的数据文件

可以将预设体文件直接拖拽入“层次面板”中，他会自动克隆一个对象出现。我们可以借助Unity引擎自带的文件装载API实现动态加载。

```c#
Instantiate(prefab)
Missile missileCopy =Instantiate<Missile>(missile);
```

### 修改预设体

 需要将预设体文件拽入场景中，然后通过"监视体面板"修改对应的数据。修改后的游戏对象保存的时候需要点击“监视体面板”中的"Apply"按钮实现真的保存。

*预设体的克隆对象数据更改不会影响你的母版文件，所以可以放心大胆的使用克隆体*

