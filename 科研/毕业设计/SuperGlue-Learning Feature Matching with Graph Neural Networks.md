##### 论文信息
- 论文地址
	- [[1911.11763] SuperGlue: Learning Feature Matching with Graph Neural Networks (arxiv.org)](https://arxiv.org/abs/1911.11763)
- 代码
	- [magicleap/SuperGluePretrainedNetwork: SuperGlue: Learning Feature Matching with Graph Neural Networks (CVPR 2020, Oral) (github.com)](https://github.com/magicleap/SuperGluePretrainedNetwork)
	- [SuperGlue代码解析](SuperGlue代码解析.canvas)
	- [pytorch](pytorch.md)
	- [(57条消息) superGlue学习_ScaredPan的博客-CSDN博客_superglue](https://blog.csdn.net/u010949023/article/details/112846084)
		- 对代码的注释
- 分析
	- [SuperGlue一种基于图卷积神经网络的特征匹配算法 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/146389956)
	- [📝笔记：SuperGlue:Learning Feature Matching with Graph Neural Networks论文阅读 | RealCat (vincentqin.tech)](https://vincentqin.tech/posts/superglue/)
	- [强力胶CVPR 2020 (psarlin.com)](https://psarlin.com/superglue/)

##### 主要工作
- 非端到端
- SuperPoint 关键点和描述符之上运行 SuperGlue 匹配网络
- 使用了图卷积神经网络进行特征匹配
- self-attention和cross-attention交替进行
##### 摘要
- 本文介绍了 SuperGlue，一种通过联合寻找对应点并拒绝不可匹配点来匹配两组局部特征的神经网络。 分配是通过解决可区分的最优运输问题来估计的，其成本由图神经网络预测。 
- 我们引入了一种基于注意力的灵活上下文聚合机制，使 SuperGlue 能够联合推理底层 3D 场景和特征分配。 与传统的、手工设计的启发式方法相比，我们的技术通过图像对的端到端训练来学习 3D 世界的几何变换和规律性的先验知识。 

##### 结构
- ![](attachments/SuperGlue-Learning%20Feature%20Matching%20with%20Graph%20Neural%20Networks%202023-01-05%2018.34.07.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/SuperGlue-Learning%20Feature%20Matching%20with%20Graph%20Neural%20Networks%202023-01-05%2018.34.07.excalidraw.md), and the [dark exported image](attachments/SuperGlue-Learning%20Feature%20Matching%20with%20Graph%20Neural%20Networks%202023-01-05%2018.34.07.excalidraw.dark.svg)%%
##### SuperGlue中的Self-Attention
- [self-Attention机制](self-Attention机制.md)
- 注意力权重$a_{ij}$
	- ![](attachments/Pasted%20image%2020230109174156.png)
- query即$q_{i}$
	- 对应于待查询图像上某个特征点i的一种表示（self-attention映射）

