# 论文信息
- [[2108.08771] Learning to Match Features with Seeded Graph Matching Network (arxiv.org)](https://arxiv.org/abs/2108.08771)
- [vdvchen/SGMNet: Implementation of "Learning to Match Features with Seeded Graph Matching Network" ICCV2021 (github.com)](https://github.com/vdvchen/SGMNet?utm_source=catalyzex.com)
# 主要工作
- 非端到端
- 带有注意力机制的种子图神经网络结构
- 引入了“种子机制”，将完全连接图变为稀疏连接图
	- [[SGMNet代码详解]]
# 结构
- ![](attachments/SGMNet-Learning%20to%20match%20features%20with%20seeded%20graph%20matching%20network%202023-01-05%2019.13.49.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/SGMNet-Learning%20to%20match%20features%20with%20seeded%20graph%20matching%20network%202023-01-05%2019.13.49.excalidraw.md), and the [dark exported image](attachments/SGMNet-Learning%20to%20match%20features%20with%20seeded%20graph%20matching%20network%202023-01-05%2019.13.49.excalidraw.dark.svg)%%
# 摘要
- 跨图像匹配局部特征是计算机视觉中的一个基本问题。 针对高精度和高效率，我们提出了种子图匹配网络，这是一种具有稀疏结构的图神经网络，可减少冗余连接并学习紧凑表示。
-  该网络由 
	- 1) 播种模块组成，它通过生成一小组可靠匹配作为种子来初始化匹配。 
	- 2) 种子图神经网络，它利用种子匹配在图像内/跨图像传递消息并预测分配成本。 三个新颖的操作被提议作为消息传递的基本元素：
		- 1）注意力池，它聚合图像中的关键点特征以进行种子匹配。
		-  2）种子过滤，增强种子特征并在图像之间交换消息。 
	- 3) Attentional Unpooling，将种子特征传播回原始关键点。 实验表明，与典型的基于注意力的网络相比，我们的方法显着降低了计算和内存复杂性，同时实现了具有竞争力或更高的性能。
# 特点
- 结果，SuperGlue [36] 中的大多数图边正如其原始论文中所报道的那样，强度往往为零并且在我们的实验中也观察到了。 这种现象表明即使是稀疏图也基本上足够了
- 