##### 论文信息
- [[1712.07629] SuperPoint: Self-Supervised Interest Point Detection and Description (arxiv.org)](https://arxiv.org/abs/1712.07629)
- [magicleap/SuperPointPretrainedNetwork: PyTorch pre-trained model for real-time interest point detection, description, and sparse tracking (https://arxiv.org/abs/1712.07629) (github.com)](https://github.com/magicleap/SuperPointPretrainedNetwork?utm_source=catalyzex.com)
##### 主要工作
- 一种比SIFT强的图像特征提取算法
##### 摘要
- 本文提出了一种自监督框架，用于训练适用于计算机视觉中大量多视图几何问题的兴趣点检测器和描述符。
- 与基于补丁的神经网络相反，我们的全卷积模型在全尺寸图像上运行，并在一次前向传递中联合计算像素级兴趣点位置和相关描述符。 
- 我们介绍了 Homographic Adaptation，这是一种多尺度、多单应性方法，用于提高兴趣点检测的可重复性和执行跨域适应（例如，从合成到真实）。 我们的模型在使用 Homographic Adaptation 在 MS-COCO 通用图像数据集上进行训练时，能够重复检测比初始预适应深度模型和任何其他传统角点检测器更丰富的兴趣点集。 
- 与 LIFT、SIFT 和 ORB 相比，最终系统在 HPatches 上产生了最先进的单应性估计结果。