# Sprite组件

Sprite（精灵）是 2D 游戏中最常见的显示图像的方式，在节点上添加 Sprite 组件，就可以在场景中显示项目资源中的图片。

点击 **属性检查器** 下面的 **添加组件** 按钮，然后从 **渲染组件** 中选择 **Sprite**，即可添加 Sprite 组件到节点上。

## Sprite 属性

| 属性             | 功能说明                                                     |
| ---------------- | ------------------------------------------------------------ |
| Atlas            | Sprite 显示图片资源所属的 [Atlas 图集资源](https://docs.cocos.com/creator/manual/zh/asset-workflow/atlas.html)。 |
| Sprite Frame     | 渲染 Sprite 使用的 [SpriteFrame 图片资源](https://docs.cocos.com/creator/manual/zh/asset-workflow/sprite.html)。 |
| Type             | 渲染模式，普通（Simple）、九宫格（Sliced）、平铺（Tiled）、填充（Filled）和网格（Mesh）渲染五种模式 |
| Size Mode        | 指定 Sprite 的尺寸 `Trimmed` 表示会使用原始图片资源裁剪透明像素后的尺寸 `Raw` 表示会使用原始图片未经裁剪的尺寸  `Custom` 表示会使用自定义尺寸。当用户手动修改过 `Size` 属性后，`Size Mode` 会被自动设置为 `Custom`，除非再次指定为前两种尺寸。 |
| Trim             | 勾选后将在渲染时去除原始图像周围的透明像素区域，该项仅在 Type 设置为 Simple 时生效。详情请参考 [图像资源的自动剪裁](https://docs.cocos.com/creator/manual/zh/asset-workflow/trim.html) |
| Src Blend Factor | 当前图像混合模式                                             |
| Dst Blend Factor | 背景图像混合模式，和上面的属性共同作用，可以将前景和背景 Sprite 用不同的方式混合渲染，效果预览可以参考 [glBlendFunc Tool](http://www.andersriggelsen.dk/glblendfunc.php)。 |

## 渲染模式

+ 普通模式:Simple
	根据原始图片资源渲染 Sprite，一般在这个模式下我们不会手动修改节点的尺寸，来保证场景中显示的图像和美术人员生产的图片比例一致
+ `九宫格模式（Sliced）`：图像将被分割成九宫格，并按照一定规则进行缩放以适应可随意设置的尺寸(`size`)

+ `平铺模式（Tiled）`：图像将会根据 Sprite 的尺寸重复平铺显示。如果 SpriteFrame 包含 [九宫格配置](https://docs.cocos.com/creator/manual/zh/ui/sliced-sprite.html)，平铺时将保持九宫格的四周宽度不变，只平铺中心部分
+ `填充模式（Filled）`：根据原点和填充模式的设置，按照一定的方向和比例绘制原始图片的一部分。经常用于进度条的动态展示。

### 填充模式（Filled）

`Type` 属性选择填充模式后，会出现一组新的属性可供配置，让我们依次介绍它们的作用。

| 属性        | 功能说明                                                     |
| ----------- | ------------------------------------------------------------ |
| Fill Type   | 填充类型选择，有 `HORIZONTAL`（横向填充）、`VERTICAL`（纵向填充）和 `RADIAL` （扇形填充）三种。 |
| Fill Start  | 填充起始位置的标准化数值（从 0 ~ 1，表示填充总量的百分比），选择横向填充时，`Fill Start` 设为 0，就会从图像最左边开始填充 |
| Fill Range  | 填充范围的标准化数值（同样从 0 ~ 1），设为 1，就会填充最多整个原始图像的范围。 |
| Fill Center | 填充中心点，只有选择了 `RADIAL` 类型才会出现这个属性。决定了扇形填充时会环绕 Sprite 上的哪个点，所用的坐标系和 [Anchor 锚点](https://docs.cocos.com/creator/manual/zh/content-workflow/transform.html#-anchor-) 是一样的。 |