##### 论文信息
- 论文地址
	- [[1911.11763] SuperGlue: Learning Feature Matching with Graph Neural Networks (arxiv.org)](https://arxiv.org/abs/1911.11763)
- 代码
	- [magicleap/SuperGluePretrainedNetwork: SuperGlue: Learning Feature Matching with Graph Neural Networks (CVPR 2020, Oral) (github.com)](https://github.com/magicleap/SuperGluePretrainedNetwork)

##### 主要工作
- 训练代码未开源
- SuperPoint 关键点和描述符之上运行 SuperGlue 匹配网络
- 使用了图卷积神经网络进行特征匹配
##### 摘要
- 本文介绍了 SuperGlue，一种通过联合寻找对应点并拒绝不可匹配点来匹配两组局部特征的神经网络。 分配是通过解决可区分的最优运输问题来估计的，其成本由图神经网络预测。 
- 我们引入了一种基于注意力的灵活上下文聚合机制，使 SuperGlue 能够联合推理底层 3D 场景和特征分配。 与传统的、手工设计的启发式方法相比，我们的技术通过图像对的端到端训练来学习 3D 世界的几何变换和规律性的先验知识。 
- SuperGlue 优于其他学习方法，并在具有挑战性的真实室内和室外环境中的姿势估计任务上取得了最先进的结果。 所提出的方法在现代 GPU 上实时执行匹配，并且可以很容易地集成到现代 SfM 或 SLAM 系统中。 代码和经过训练的权重可在此 https URL 上公开获得。
- SuperGlue 是 Magic Leap 完成的 CVPR 2020 研究项目。 SuperGlue 网络是一个结合了优化匹配层的图形神经网络，该层经过训练可以对两组稀疏图像特征进行匹配。 此 repo 包括 PyTorch 代码和预训练权重，用于在 SuperPoint 关键点和描述符之上运行 SuperGlue 匹配网络。 给定一对图像，您可以使用此存储库来提取图像对中的匹配特征。