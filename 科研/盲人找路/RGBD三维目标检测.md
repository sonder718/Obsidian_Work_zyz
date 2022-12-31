感觉这些都是立体版本的识别猫狗

# 2014年：Learning Rich Features from RGB-D Images for Object Detection and Segmentation（ECCV'14）

https://mp.weixin.qq.com/s/61JWlwvscTpqSPDPE8wikw

作者的方法是在2D目标检测框架R-CNN的基础上，增加对Depth Map进行利用的module，总体结构如下：

![image-20220517174034175](RGBD%E9%9A%9C%E7%A2%8D%E7%89%A9%E6%A3%80%E6%B5%8B.assets/image-20220517174034175.png)

（1）基于RGB图像和Depth Map，检测图像中的轮廓，并生成2.5D的proposals（从overview上可以看到，所谓的2.5D实则包括目标每个像素的视差、高度、倾斜角）



（2）利用CNN进行特征提取，这里的网络包括两个：Depth CNN学习深度图上的特征，RGB CNN学习2D图像上的特征，最后利用SVM进行分类。



在对Depth Map的利用上，论文所述方法**并没有直接利用CNN**对其进行学习，而是encode the depth image with three channels at each pixel: horizontal disparity（水平视差）, height above ground（高度）, and the angle the pixel’s local surface normal makes with the inferred gravity direction（相对于重力的倾斜角）.

# **2015年：3D Object Proposals for Accurate Object Class Detection**

[3D Object Proposals for Accurate Object Class Detection (neurips.cc)](https://proceedings.neurips.cc/paper/2015/file/6da37dd3139aa4d9aa55b8d237ec5d4a-Paper.pdf)

本文的目标是在自动驾驶环境下生成高质量的三维物体方案。我们的方法利用立体图像以3D边框的形式放置建议。我们将问题表述为最小化一个能量函数编码对象大小先验，地面平面以及几个深度被告知的特征，原因是自由空间，点云密度和地面距离。我们的实验表明，与现有的性能相比，性能有了显著提高

在本文中，我们提出了一种新的对象提议方法，该方法利用立体信息以及特定于自动驾驶领域的上下文模型。我们的方法在3D中进行推理，并以**3D边界框的形式放置建议。我们利用了物体大小、地平面，以及自由空间、盒子内的点密度、可见性和到地面的距离等深度信息**。我们的实验表明，在所有重叠阈值和对象遮挡水平下，与最新技术相比，可实现的回忆有了显著的改善，表明我们的方法产生了高度准确的对象建议。特别是，与最先进的RGB-D方法MCG-D[14]相比，我们对2K提案的召回率高出25%。结合CNN评分，我们的方法在KITTI[11]上对汽车、自行车和行人的目标检测方面优于所有已发表的结果。我们的代码和数据在线：http:\/\/www.cs。多伦多教育\/~3dop。

我们直接利用立体图像和3D推理。我们将问题描述为马尔可夫随机场中的推理，该随机场编码对象大小先验、地平面和各种深度信息特征

文章面向自动驾驶场景，提出了一种新的object proposal方法。对于每一个3D bounding box（记为**y**），将其用一个元组来表示(x, y, z, θ, c, t)，(x, y, z) 表示 3D box的中心，θ 表示其方位角，c代表object是哪一类，t代表相应的3d box模板集合。



# 2016 **Deep Sliding Shapes for Amodal 3D Object Detection in RGB-D Images**

目前关于3D目标检测任务的方法，有采用**2D方法来结合深度图**的，也有在**3D空间内进行检测**的。这不禁让作者发问：**which representation is better for 3D amodal object detection, 2D or 3D？**接着他指出，目前2D方法表现更优异的原因，可能是因为其CNN模型更为powerful（well-designed&pre-trained with ImageNet），而不是由于其2D表达。



# Deep Optics for Monocular Depth Estimation and 3D Object Detection

**重点搞得是单一图像深度估计，用处不大**

[Deep Optics for Monocular Depth Estimation and 3D Object Detection (thecvf.com)](https://openaccess.thecvf.com/content_ICCV_2019/papers/Chang_Deep_Optics_for_Monocular_Depth_Estimation_and_3D_Object_Detection_ICCV_2019_paper.pdf)

深度估计和3D目标检测对于场景理解至关重要，但由于在图像捕获过程中会丢失3D信息，使用单一图像进行检测仍然具有挑战性。近年来，深度神经网络模型提高了单目深度估计性能，但在绝对深度预测和在标准数据集以外推广方面仍存在困难。在这里，我们介绍了深度光学的范式，即光学和图像处理的端到端设计，以单眼深度估计问题，使用编码离焦模糊作为额外的深度线索，由神经网络解码。我们评估了几种光学编码策略以及一个端到端优化方案，用于三个数据集的深度估计，包括NYU depth v2和KITTI。我们发现优化的自由曲面透镜设计产生了最好的结果，但单线透镜的色差也提供了显著改善的性能。我们构建了一个物理原型，并验证了色差改善了对真实结果的深度估计。此外，我们在KITTI数据集上训练目标检测网络，并表明经过深度估计优化的镜头也提高了3D目标检测性能



# Objects are Different: Flexible Monocular 3D Object Detection:star:

这篇看上去很相关，用了depth信息，不过他是用算法估计的，你是用相机直接得到的

现有的大多数三维目标检测方法都需要LiDAR传感器[22,33,35,40,41,49]进行精确的深度测量或立体相机**[8,24,37,45]**进行立体深度估计，这大大增加了实际系统的实现成本

将预测的3D中心与图像的关系分为“inside”和“outside”，然后将**内部对象精确地表示为投影中心**，**外部对象精确地表示为边缘点**，这样两组对象分别由特征映射的内部区域和边缘区域处理。针对卷积难以处理空间变化预测的问题，进一步提出了**边缘融合模块**，将外部目标的**特征学习和预测解耦**。

如图1所示，用最先进的方法很难检测到**严重截断的对象**[3,13]，但这些对象对自动驾驶汽车的安全很重要。（2） 我们实证发现，这些硬样本会增加学习负担，并影响对一般对象的预测。因此，统一的方法可能无法找到每个对象，也无法预测精确的三维位置。为此，我们提出了一种灵活的检测器，它可以考虑物体之间的差异，并以自适应的方式估计物体的三维位置。由于对物体三维位置的估计通常分解为寻找投影的三维中心和物体深度[10,28,36,52]，因此我们也从这两个方面考虑了灵活性

不关心其估计深度的部分

[Objects Are Different: Flexible Monocular 3D Object Detection (thecvf.com)](https://openaccess.thecvf.com/content/CVPR2021/papers/Zhang_Objects_Are_Different_Flexible_Monocular_3D_Object_Detection_CVPR_2021_paper.pdf)

对象是不同的:灵活的单目三维对象检测

![img](https://img-blog.csdnimg.cn/20210518200100313.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzMyMDk3NTc3,size_16,color_FFFFFF,t_70#pic_center)

在没有深度信息的情况下，从单个图像中精确定位三维物体是一个极具挑战性的问题。大多数现有方法对所有对象采用相同的方法，而不考虑其不同的分布，这导致截断对象的性能有限。在本文中，我们提出了一个灵活的单目三维目标检测框架，它明确地解耦了被截断的目标，并自适应地结合了多种目标深度估计方法。具体来说，我们对特征映射的边缘进行解耦，以预测长尾截断对象，从而不影响正常对象的优化。此外，我们制定目标深度估计作为一个不确定性指导集成直接回归的目标深度和解决深度从不同的关键点组。实验表明，在KITTI基准测试集中，我们的方法在保持实时效率的同时，在中等水平和硬水平上比最先进的方法的性能分别高出27%和30%。



将预测的3D中心与图像的关系分为“inside”和“outside”，然后将**内部对象精确地表示为投影中心**，**外部对象精确地表示为边缘点**，这样两组对象分别由特征映射的内部区域和边缘区域处理。针对卷积难以处理空间变化预测的问题，进一步提出了**边缘融合模块**，将外部目标的**特征学习和预测解耦**。

简单地从不同关键点计算平均可能对截断和遮挡对象的关键点比较敏感。本文将关键点分为M组，每组恰好可以足以求解深度。为了将基于M关键点的估计和直接回归相结合，我们对它们的不确定性进行建模，并将最终估计表示为不确定性加权平均。所提出的组合允许模型灵活地选择更适合的估计器进行稳健和准确的预测。

版权声明：本文为CSDN博主「潜沉10」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_32097577/article/details/116989698



# [Depth-Conditioned Dynamic Message Propagation for Monocular 3D Object Detection (thecvf.com)](https://openaccess.thecvf.com/content/CVPR2021/papers/Wang_Depth-Conditioned_Dynamic_Message_Propagation_for_Monocular_3D_Object_Detection_CVPR_2021_paper.pdf):star:



本文的目的是学习背景和深度感知特征表示，以解决单目三维目标检测问题。本文的主要贡献如下:(1)提出了一种深度条件动态消息传播(DDMP)网络，有效地将多尺度深度信息与图像上下文相结合，而不是采用复杂的伪激光雷达方法;(ii)这是通过首先自适应采样图像上下文感知节点，然后动态预测混合深度依赖滤波器权重和亲和矩阵传播信息来实现的;(iii)通过增加一个中心感知深度编码(CDE)任务，我们的方法成功地缓解了不准确的深度先验;(iv)我们彻底展示了我们提出的方法的有效性，并在KITTI基准数据集上展示了基于单目方法的最新结果。尤其值得一提的是，在提交日(2020年11月16日)，我们在竞争激烈的KITTI单眼3D物体检测轨道中排名第一。代码和模型发布在https://github。com/fudan-zvg/DDMP



![image-20220518004756767](RGBD%E9%9A%9C%E7%A2%8D%E7%89%A9%E6%A3%80%E6%B5%8B.assets/image-20220518004756767.png)

我们提议的DDMP-3D示意图。涉及到两个分支:3D检测分支(蓝色)和深度特征提取分支(绿色)。黄色的DDMP模块显示了基于深度条件的动态消息传播。它动态采样上层图像分支中的上下文感知节点，并基于来自底层分支的多尺度深度特征预测混合滤波器的权值和亲和性，用于消息传播。CDE是联合优化训练的辅助任务，在推理过程中被丢弃。



# Stereo R-CNN based 3D Object Detection for Autonomous Driving:star:

3D边界框

将三维物体定位作为一个学习辅助几何问题，我们的方法利用了物体的**语义特性和密集约束**

Formulating the 3D object localization as a learning-aided geometry problem, our approach takes the advantage of both **semantic properties** and **dense constraints of objects**

其似乎是输入左右图像的2D边界框生成3D边界框，

这是一种salient object detection并非我们想要的通用目标检测

[Stereo R-CNN Based 3D Object Detection for Autonomous Driving (thecvf.com)](https://openaccess.thecvf.com/content_CVPR_2019/papers/Li_Stereo_R-CNN_Based_3D_Object_Detection_for_Autonomous_Driving_CVPR_2019_paper.pdf)

1.提出 Stereo R-CNN网络架构，在关联双目图像的同时进行目标检测。
2.提出一种 3D 边界框估计器，根据关键点和双目 2D 边界框得到 3D 边界框。
3.提出 Dense Alignment，一种基于密集区域的双目匹配对齐方法，使得目标在三维空间中的定位更加精确。

4. 在 KITTI 数据集上，与其他基于图像的方法相比，表现最好。甚至能与基于激光雷达的方法相媲美。
------------------------------------------------
版权声明：本文为CSDN博主「DWjan」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/Justdiit/article/details/109459085

通过充分利用立体图像中的稀疏和密集、语义和几何信息，提出了一种用于自动驾驶的三维目标检测方法。我们的方法称为立体声R-CNN，它扩展了用于立体声输入的更快的R-CNN，以同时检测和关联左右图像中的对象。我们在立体区域建议网络（RPN）之后添加额外的分支来预测稀疏的关键点、视点和对象维度，并将其与二维左右框相结合来**计算粗略**的三维对象边界框。然后，我们通过使用左右ROI的**基于区域的光度对齐**来恢复**精确的3D边界框**。然而，我们的方法不需要深度输入和三维位置监控，优于所有现有的基于全监督图像的方法

在具有挑战性的KITTI数据集上的实验表明，我们的方法在3D检测和3D定位任务上都比最先进的基于立体的方法高出约30%的AP。代码将公开

![image-20220518003557770](RGBD%E9%9A%9C%E7%A2%8D%E7%89%A9%E6%A3%80%E6%B5%8B.assets/image-20220518003557770.png)

**与激光雷达相比，立体相机的成本较低，但对于具有非微小差异的物体，其深度精度相当**

网络架构如图1所示，可分为三个主要部分。第一个是立体声RPN模块（第3.1节），它输出相应的左右RoI建议。在分别对左特征图和右特征图应用RoIAlign[8]后，我们将左-右RoI特征连接起来，以分类对象类别，并在立体回归（第3.2节）分支中回归精确的二维立体框、视点和尺寸。关键点（第3.2节）分支用于仅使用左侧RoI特征预测对象关键点。这些输出形成了3D框估计（第4节）的稀疏约束（2D框、关键点），我们在3D框角与2D左右框和关键点之间建立了投影关系

确保3D定位性能的关键组件是密集3D盒对齐（第5节）。我们认为三维物体定位是一个学习辅助的几何问题，而不是一个端到端的回归问题。我们不是直接使用深度输入[4,27]，它没有明确利用对象属性，而是将对象RoI视为一个整体，而不是独立的像素

对于规则形状的对象，可以根据粗略的三维边界框推断每个像素与三维中心之间的深度关系。我们根据左侧RoI中的密集像素与3D对象中心的深度关系，将其扭曲到右侧图像，以找到使整个光度误差最小化的最佳中心深度。因此，稠密的RoI对整个3D对象形成深度约束



我们将我们的主要贡献总结如下：•一种**立体R-CNN方法**，可以同时检测和关联立体图像中的对象

•利用**关键点和立体声盒约束的3D盒估计器**

•基于密集区域的光度校准方法，确保我们的3D对象定位精度



基于立体的三维物体检测。令人惊讶的是，利用立体视觉进行三维物体检测的作品屈指可数。**3DOP[4]专注于通过将对象大小先验、地平面先验和深度信息（例如自由空间、点云密度）编码为能量函数来生成3D提案。然后使用3D提案，使用R-CNN方法回归对象姿势和2D框。[**17] 将结构从运动（SfM）方法扩展到动态对象情况，并通过融合空间和时间信息连续跟踪3D对象和自我相机姿势。然而，上述方法都没有利用原始立体图像中的密集对象约束

![image-20220518004343582](RGBD%E9%9A%9C%E7%A2%8D%E7%89%A9%E6%A3%80%E6%B5%8B.assets/image-20220518004343582.png)

# Triangulation learning network from monocular to stereo 3d object detection

[Your title here: Maybe add some pictures and/or school logo on the left and right authors and affiliation (jingluw.github.io)](https://jingluw.github.io/projects/TLNet/files/cvpr19_poster.pdf#:~:text=Triangulation Learning Network. The stereo 3D detection is,TLNet focuses on object-level triangulation rather than pixel-level.)

一种性能与最先进的立体探测器相当的实心单目基线3D探测器

•一个三角测量学习网络，利用**立体图像的几何相关性**来定位目标3D对象，大大优于基线模型

•一种功能重新加权策略，可增强视图特定RoI功能的信息通道，通过将网络注意力偏向对象的关键部分，有利于三角测量学习。

![image-20220518010920886](RGBD%E9%9A%9C%E7%A2%8D%E7%89%A9%E6%A3%80%E6%B5%8B.assets/image-20220518010920886.png)其关键思想是使用3D锚盒在一对立体图像上显式构造其两个投影的对象级几何对应，网络从中学习在锚附近对目标对象进行三角化。

![image-20220518010949668](RGBD%E9%9A%9C%E7%A2%8D%E7%89%A9%E6%A3%80%E6%B5%8B.assets/image-20220518010949668.png)

# Pseudo-LiDAR from Visual Depth Estimation: Bridging the Gap in 3D Object Detection for Autonomous Driving

视觉深度估计的伪激光雷达：填补自动驾驶3D目标检测的空白

三维目标检测是自动驾驶中的一项重要任务。如果3D输入数据来自精确但昂贵的激光雷达技术，则最新技术的检测率非常高。到目前为止，基于廉价单目或立体图像数据的方法导致精度大幅降低——这一差距通常归因于基于图像的深度估计较差。然而，在本文中，我们认为，**造成差异的主要原因不是数据的质量，而是数据的表示**。考虑到卷积神经网络的内部工作原理，我们建议将**基于图像的深度图转换为伪激光雷达表示**——本质上模仿激光雷达信号。通过这种表示，我们可以应用不同的现有基于LIDARBASE的检测算法。在流行的KITTI基准上，我们的方法在基于图像的性能方面取得了令人印象深刻的改进，将30米范围内物体的检测精度从以前的22%提高到了前所未有的74%。在提交时，我们的算法在KITTI 3D物体检测排行榜上占据了基于立体图像的方法的最高排名。

![image-20220518011257596](RGBD%E9%9A%9C%E7%A2%8D%E7%89%A9%E6%A3%80%E6%B5%8B.assets/image-20220518011257596.png)

![image-20220518011316417](RGBD%E9%9A%9C%E7%A2%8D%E7%89%A9%E6%A3%80%E6%B5%8B.assets/image-20220518011316417.png)



# Deeply Exploit Depth Information for Object Detection

[Deeply Exploit Depth Information for Object Detection (thecvf.com)](https://openaccess.thecvf.com/content_cvpr_2016_workshops/w24/papers/Hou_Deeply_Exploit_Depth_CVPR_2016_paper.pdf)

**对于基于CNN的RGB-D目标检测，关键是如何在特征学习中巧妙地将RGB与深度信息协调起来。**

根据深度处理的策略，我们大致可以将其分为两大类。第一种方法是直接将深度图与RGB一起添加到CNN，作为第四个频道[3]。也就是说，深度的处理方式与RGB相同，它们一起被卷积19是理所当然的。然而，直接合并深度和颜色贴图在语义上没有意义，因为它们包含不同的信息。第二种方法是分别对颜色和深度进行处理，并在输入最终分类器之前进行组合，在分类器中提取的特征是联合的



为了提高RGB-D目标检测的性能，本文讨论了如何更有效地将深度与RGB进行协调的问题。特别是，我们研究了CNN模型下的两个主要思想：属性派生和属性融合。首先，我们提出深度不仅可以作为RGB之外的一种额外信息，还可以获得更多的视觉特性来全面描述感兴趣的对象

因此，本文构建了一个**由属性派生和融合组成**的两阶段学习框架。在这里，属性可以从提供的颜色\深度或其对（例如本文中采用的几何轮廓）导出

其次，我们探讨了特征学习中不同属性的融合方法，即在CNN模型下，从哪一层将属性融合在一起。分析表明，在进入最终分类器之前，不同的语义属性应该分别学习并组合。实际上，这种检测方式符合大脑初级神经皮层（V1）的机制。我们在具有挑战性的数据集上对所提出的方法进行了实验评估，并取得了最先进的性能

![image-20220518012447076](RGBD%E9%9A%9C%E7%A2%8D%E7%89%A9%E6%A3%80%E6%B5%8B.assets/image-20220518012447076.png)

然而，如何有效地利用RGB-D RGB视差高度角轮廓颜色轮廓视差高度角派生融合特征深度派生图1提供的深度信息。学习RGB-D对象检测的丰富功能的图示。导出了各种属性映射，以从不同角度描述对象。这些地图的特征被独立学习，然后融合为最终分类

具体来说，导出的地图包括来自颜色/深度对的几何轮廓，以及来自深度数据的水平视差、离地高度、与重力的角度。这些地图以及RGB图像被发送到不同的CNN中进行特征学习





论文总结：

1.[Deeply Exploit Depth Information for Object Detection (thecvf.com)](https://openaccess.thecvf.com/content_cvpr_2016_workshops/w24/papers/Hou_Deeply_Exploit_Depth_CVPR_2016_paper.pdf)讨论如何在特征学习中巧妙地将RGB与深度信息协调起来，导出的map包括来自颜色/深度对的几何轮廓，以及来自深度数据的水平视差、离地高度、与重力的角度。这些地图以及RGB图像被发送到不同的CNN中进行特征学习

2.[Pseudo-LiDAR From Visual Depth Estimation: Bridging the Gap in 3D Object Detection for Autonomous Driving (thecvf.com)](https://openaccess.thecvf.com/content_CVPR_2019/papers/Wang_Pseudo-LiDAR_From_Visual_Depth_Estimation_Bridging_the_Gap_in_3D_CVPR_2019_paper.pdf)其认为**造成差异的主要原因不是数据的质量，而是数据的表示**。考虑到卷积神经网络的内部工作原理，我们建议将**基于图像的深度图转换为伪激光雷达表示**——本质上模仿激光雷达信号。

3.[Your title here: Maybe add some pictures and/or school logo on the left and right authors and affiliation (jingluw.github.io)](https://jingluw.github.io/projects/TLNet/files/cvpr19_poster.pdf#:~:text=Triangulation Learning Network. The stereo 3D detection is,TLNet focuses on object-level triangulation rather than pixel-level.)一个三角测量学习网络，利用**立体图像的几何相关性**来定位目标3D对象

[Stereo R-CNN Based 3D Object Detection for Autonomous Driving (thecvf.com)](https://openaccess.thecvf.com/content_CVPR_2019/papers/Li_Stereo_R-CNN_Based_3D_Object_Detection_for_Autonomous_Driving_CVPR_2019_paper.pdf)利用了物体的**语义特性和密集约束**，**关联双目图像的同时进行目标检测**。根据关键点和双目 2D 边界框得到 3D 边界框

[Objects Are Different: Flexible Monocular 3D Object Detection (thecvf.com)](https://openaccess.thecvf.com/content/CVPR2021/papers/Zhang_Objects_Are_Different_Flexible_Monocular_3D_Object_Detection_CVPR_2021_paper.pdf)关注物体截断问题，将**内部对象精确地表示为投影中心**，**外部对象精确地表示为边缘点**，这样两组对象分别由特征映射的内部区域和边缘区域处理。针对卷积难以处理空间变化预测的问题，进一步提出了**边缘融合模块**，将外部目标的**特征学习和预测解耦**。

[Depth-Conditioned Dynamic Message Propagation for Monocular 3D Object Detection (thecvf.com)](https://openaccess.thecvf.com/content/CVPR2021/papers/Wang_Depth-Conditioned_Dynamic_Message_Propagation_for_Monocular_3D_Object_Detection_CVPR_2021_paper.pdf)提出了一种深度条件动态消息传播(DDMP)网络，有效地将多尺度深度信息与图像上下文相结合，而不是采用复杂的伪激光雷达方法，**动态的选取最相关图节点**，实现高效的获取物体上下文语义信息

4.上述方法似乎只支持在交通道路上预先定义的一些正常障碍物,如人或车辆等的三维框，那对于其他意外的无分类的小障碍物似乎不同适用。

RGBD障碍物检测[Small Obstacle Avoidance Based on RGB-D Semantic Segmentation (thecvf.com)](https://openaccess.thecvf.com/content_ICCVW_2019/papers/CVRSUAD/Hua_Small_Obstacle_Avoidance_Based_on_RGB-D_Semantic_Segmentation_ICCVW_2019_paper.pdf):star:小障碍物检测，提出了一种用于**障碍物分割的两级RGB-D编解码网络**，该网络首先对图像进行分割，得到道路掩模，然后从提取的道路区域中得到更准确的障碍物区域，甚至是较小的障碍物区域。2） 为了保持分割网络的时间一致性，提出了相邻帧之间的**光流监控**，这对于摄像机移动时稳定的障碍物检测至关重要

RFNet：基于RGB-D数据的语义分割和意外障碍物检测的实时融合网络[2002.10570.pdf (arxiv.org)](https://arxiv.org/pdf/2002.10570.pdf)利用了互补的深度信息，大大提高了基于RGB的方法的精度。通过提出的多源训练策略，RFNet可以检测到意外的小障碍。