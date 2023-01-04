##### 论文信息
- [[2104.00680] LoFTR: Detector-Free Local Feature Matching with Transformers (arxiv.org)](https://arxiv.org/abs/2104.00680)
- [LoFTR: Detector-Free Local Feature Matching with Transformers (zju3dv.github.io)](https://zju3dv.github.io/loftr/?utm_source=catalyzex.com)
##### 主要工作
- 使用Transformer
- 不是按顺序执行图像特征检测、描述和匹配
- 多尺度:粗略级别+精细级别
##### 摘要
我们提出了一种用于局部图像特征匹配的新方法。 我们建议首先在粗略级别建立像素级密集匹配，然后在精细级别细化良好匹配，而不是按顺序执行图像特征检测、描述和匹配。 与使用成本量来搜索对应关系的密集方法相比，我们在 Transformer 中使用自注意力层和交叉注意力层来获得以两个图像为条件的特征描述符。 Transformer 提供的全局感受野使我们的方法能够在低纹理区域产生密集匹配，而特征检测器通常难以产生可重复的兴趣点。 室内和室外数据集的实验表明，LoFTR 的性能大大优于最先进的方法。 在已发布的方法中，LoFTR 在视觉定位的两个公共基准测试中也排名第一。