- **刚体变换与仿射变换**
	- 相比刚体变换（旋转和平移），仿射变换除了改变目标位置，还改变目标的形状
	- 但是会保持物体的平直性（如图形中平行的两条线变换后依然平行）
	- ![](attachments/%E5%8D%95%E5%BA%94%E5%8F%98%E6%8D%A2%E7%9F%A9%E9%98%B5H%202023-01-04%2016.07.46.excalidraw.svg)%%[🖋 Edit in Excalidraw](attachments/%E5%8D%95%E5%BA%94%E5%8F%98%E6%8D%A2%E7%9F%A9%E9%98%B5H%202023-01-04%2016.07.46.excalidraw.md), and the [dark exported image](attachments/%E5%8D%95%E5%BA%94%E5%8F%98%E6%8D%A2%E7%9F%A9%E9%98%B5H%202023-01-04%2016.07.46.excalidraw.dark.svg)%%
- **单应性变换**/投影变换
	- 彻底改变目标的形状
	- ![](attachments/%E5%8D%95%E5%BA%94%E5%8F%98%E6%8D%A2%E7%9F%A9%E9%98%B5H%202023-01-04%2016.10.39.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E5%8D%95%E5%BA%94%E5%8F%98%E6%8D%A2%E7%9F%A9%E9%98%B5H%202023-01-04%2016.10.39.excalidraw.md), and the [dark exported image](attachments/%E5%8D%95%E5%BA%94%E5%8F%98%E6%8D%A2%E7%9F%A9%E9%98%B5H%202023-01-04%2016.10.39.excalidraw.dark.svg)%%
- **单应变换矩阵目的**
	- 将一张图像中的点
	- 映射到另一张图像
- **本质**
	- 任意两张==图像==中，==像素==之间的映射关系
	- 只有当匹配点都在==特定的世界平面==中，才可以使用单应来恢复帧间的运动
	- ![](attachments/Pasted%20image%2020230104161312.png)
	- ![](attachments/Pasted%20image%2020230104160338.png)
- **8点法可以估计H矩阵**
	- **假设**
		- 描述的是两幅图像之间的平面单应性
	- **H矩阵的特征**
		- 9个未知数，但只有8个自由度
		- ![](attachments/Pasted%20image%2020230104161415.png)
	- **一对匹配点可以得到什么**
		- 可以获得两组方程
		- ![](attachments/%E5%8D%95%E5%BA%94%E5%8F%98%E6%8D%A2%E7%9F%A9%E9%98%B5H%202023-01-04%2016.15.48.excalidraw.svg)%%[🖋 Edit in Excalidraw](attachments/%E5%8D%95%E5%BA%94%E5%8F%98%E6%8D%A2%E7%9F%A9%E9%98%B5H%202023-01-04%2016.15.48.excalidraw.md), and the [dark exported image](attachments/%E5%8D%95%E5%BA%94%E5%8F%98%E6%8D%A2%E7%9F%A9%E9%98%B5H%202023-01-04%2016.15.48.excalidraw.dark.svg)%%
	- **四对点可以求解H矩阵系数**
		- 单应性Homograph估计：从传统算法到深度学习 - 白裳的文章 - 知乎 https://zhuanlan.zhihu.com/p/74597564
		- ![](attachments/%E5%8D%95%E5%BA%94%E5%8F%98%E6%8D%A2%E7%9F%A9%E9%98%B5H%202023-01-04%2016.18.37.excalidraw.svg)%%[🖋 Edit in Excalidraw](attachments/%E5%8D%95%E5%BA%94%E5%8F%98%E6%8D%A2%E7%9F%A9%E9%98%B5H%202023-01-04%2016.18.37.excalidraw.md), and the [dark exported image](attachments/%E5%8D%95%E5%BA%94%E5%8F%98%E6%8D%A2%E7%9F%A9%E9%98%B5H%202023-01-04%2016.18.37.excalidraw.dark.svg)%%
- **特征点匹配+RANSAC剔除**求解
	- ![](attachments/Pasted%20image%2020230104162046.png)
	- ![](attachments/Pasted%20image%2020230104162107.png)
