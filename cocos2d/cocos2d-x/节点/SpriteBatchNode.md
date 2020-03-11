# SpriteBatchNode

SpriteBatchNode类似于一个批处理节点:如果它包含子节点，它将在一个单独的OpenGL调用中绘制它们(通常称为“批处理绘制”)。

SpriteBatchNode只能引用一个纹理(一个图像文件，一个纹理图集)。只有包含在纹理中的精灵才能添加到SpriteBatchNode中。所有添加到SpriteBatchNode的精灵都是在一个OpenGL ES draw调用中绘制的。如果SpriteBatchNode中没有添加sprite，那么每个SpriteBatchNode都需要一个OpenGL ES draw调用，这样效率会降低。

限制:

唯一被接受为子对象(或孙子辈、孙子辈等等)的对象是Sprite或Sprite的任何子类。粒子、标签和图层不能添加到SpriteBatchNode中。

它的所有子元素不是别名就是反别名。不可能是混合的。这是因为“alias”是纹理的属性，所有精灵共享相同的纹理。

v0.7.1

