##### 论文信息
- [[2103.14167v1] COTR: Correspondence Transformer for Matching Across Images (arxiv.org)](https://arxiv.org/abs/2103.14167v1)
- [ubc-vision/COTR: Code release for "COTR: Correspondence Transformer for Matching Across Images"(ICCV 2021) (github.com)](https://github.com/ubc-vision/COTR)
##### 主要工作
- [[Transformer]]
- 仅查询兴趣点并检索稀疏对应关系
- 局部和全局先验
##### 摘要
- 我们提出了一种新的框架，用于基于深度神经网络在图像中寻找对应关系，给定两个图像和其中一个中的查询点，在另一个中找到它的对应关系。 通过这样做，人们可以选择仅查询兴趣点并检索稀疏对应关系，或者查询图像中的所有点并获得密集映射。
-  重要的是，为了捕获局部和全局先验，并让我们的模型使用所述先验中最相关的图像区域之间的关联，我们使用转换器实现我们的网络。
- 在推理时，我们通过围绕估计递归放大来应用我们的对应网络，从而产生能够提供高精度对应的多尺度管道。 
- 我们的方法在多个数据集和任务的稀疏和密集对应问题上明显优于现有技术，范围从宽基线立体声到光流，无需对特定数据集进行任何再训练。 我们承诺发布数据、代码和所有必要的工具，以从头开始训练并确保可重复性。