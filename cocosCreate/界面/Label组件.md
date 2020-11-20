# Label 组件参考

Label 组件用来显示一段文字，文字可以是系统字体、TrueType 字体、BMFont 字体或艺术数字。另外，Label 还具有排版功能。

点击 **属性检查器** 下面的 **添加组件** 按钮，然后从 **渲染组件** 中选择 **Label**，即可添加 Label 组件到节点上。

## Label 属性

| 属性             | 功能说明                                                     |
| ---------------- | ------------------------------------------------------------ |
| String           | 文本内容字符串。                                             |
| Horizontal Align | 文本的水平对齐方式。可选值有 LEFT，CENTER 和 RIGHT。         |
| Vertical Align   | 文本的垂直对齐方式。可选值有 TOP，CENTER 和 BOTTOM。         |
| Font Size        | 文本字体大小。                                               |
| Line Height      | 文本的行高。                                                 |
| SpacingX         | 文本字符之间的间距。（使用 BMFont 位图字体时生效）           |
| Overflow         | 文本的排版方式，目前支持 CLAMP，SHRINK 和 RESIZE_HEIGHT。详情见下方的 [Label 排版](https://docs.cocos.com/creator/manual/zh/components/label.html#label-排版)。 |
| Enable Wrap Text | 是否开启文本换行。（在排版方式设为 CLAMP、SHRINK 时生效）    |
| Font             | 指定文本渲染需要的字体文件，如果使用系统字体，则此属性可以为空。 |
| Font Family      | 文字字体名字。(使用系统字体时生效)                           |
| Enable Bold      | 是否启用黑体。(使用系统字体或 TTF 字体时生效)                |
| Enable Italic    | 是否启用斜体。(使用系统字体或 TTF 字体时生效)                |
| Enable Underline | 是否启用下划线。(使用系统字体或 TTF 字体时生效)              |
| Underline Height | 下划线的高度                                                 |
| Cache Mode       | 文本缓存类型包括 **NONE**、**BITMAP**、**CHAR** 三种。仅对系统字体或 TTF 字体有效，BMFont 字体无需进行这个优化 |
| Use System Font  | 是否使用系统字体                                             |
| Src Blend Factor | 混合文本图片时，源图片的取值模式上                           |
| Dst Blend Factor | 混合显示两张图片时，目标图片的取值模式                       |
| Materials        | 材质资源，详情请参考文档 [Material](https://docs.cocos.com/creator/manual/zh/render/material.html)。 |