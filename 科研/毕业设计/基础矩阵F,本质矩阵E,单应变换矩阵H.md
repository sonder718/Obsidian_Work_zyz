##### 面临的问题-双视图几何问题
- **前提**
	- 相机或空间物体在运动
- **已有信息**
	- 对于一个空间物体拍摄的两张不同角度的图像
		- ![](attachments/%E5%9F%BA%E7%A1%80%E7%9F%A9%E9%98%B5F,%E6%9C%AC%E8%B4%A8%E7%9F%A9%E9%98%B5E,%E5%8D%95%E5%BA%94%E5%8F%98%E6%8D%A2%E7%9F%A9%E9%98%B5H%202023-01-04%2014.38.30.excalidraw.svg)%%[🖋 Edit in Excalidraw](attachments/%E5%9F%BA%E7%A1%80%E7%9F%A9%E9%98%B5F,%E6%9C%AC%E8%B4%A8%E7%9F%A9%E9%98%B5E,%E5%8D%95%E5%BA%94%E5%8F%98%E6%8D%A2%E7%9F%A9%E9%98%B5H%202023-01-04%2014.38.30.excalidraw.md), and the [dark exported image](attachments/%E5%9F%BA%E7%A1%80%E7%9F%A9%E9%98%B5F,%E6%9C%AC%E8%B4%A8%E7%9F%A9%E9%98%B5E,%E5%8D%95%E5%BA%94%E5%8F%98%E6%8D%A2%E7%9F%A9%E9%98%B5H%202023-01-04%2014.38.30.excalidraw.dark.svg)%%
- **目的**
	- 得到一个空间点X 在两个不同的图像帧中的位置x1，x2之间的数学关系
		- 这两个帧可以是由两个不同的相机获得的
##### 基础矩阵F描述什么
- **F反应的关系**
	- 反映【空间一点P的像素点】
	- 在【不同视角摄像机】下
	- 【**图像坐标系**】中的表示之间的关系。
- **F被确定的方式**
	- 两个相机的相对位置关系
	- ==相机内参==
- ![](attachments/%E5%9F%BA%E7%A1%80%E7%9F%A9%E9%98%B5F,%E6%9C%AC%E8%B4%A8%E7%9F%A9%E9%98%B5E,%E5%8D%95%E5%BA%94%E5%8F%98%E6%8D%A2%E7%9F%A9%E9%98%B5H%202023-01-04%2014.46.19.excalidraw.svg)%%[🖋 Edit in Excalidraw](attachments/%E5%9F%BA%E7%A1%80%E7%9F%A9%E9%98%B5F,%E6%9C%AC%E8%B4%A8%E7%9F%A9%E9%98%B5E,%E5%8D%95%E5%BA%94%E5%8F%98%E6%8D%A2%E7%9F%A9%E9%98%B5H%202023-01-04%2014.46.19.excalidraw.md), and the [dark exported image](attachments/%E5%9F%BA%E7%A1%80%E7%9F%A9%E9%98%B5F,%E6%9C%AC%E8%B4%A8%E7%9F%A9%E9%98%B5E,%E5%8D%95%E5%BA%94%E5%8F%98%E6%8D%A2%E7%9F%A9%E9%98%B5H%202023-01-04%2014.46.19.excalidraw.dark.svg)%%
##### 本质矩阵E描述什么
- **E反应的关系**
	- 反映【空间一点P的像点】
	- 在【不同视角摄像机】下
	- 【**摄像机坐标系**】中的表示之间的关系
- **E被确定的方式**
	- 给定两个==已标定相机==的相对位置关系
- ![](attachments/%E5%9F%BA%E7%A1%80%E7%9F%A9%E9%98%B5F,%E6%9C%AC%E8%B4%A8%E7%9F%A9%E9%98%B5E,%E5%8D%95%E5%BA%94%E5%8F%98%E6%8D%A2%E7%9F%A9%E9%98%B5H%202023-01-04%2014.46.36.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E5%9F%BA%E7%A1%80%E7%9F%A9%E9%98%B5F,%E6%9C%AC%E8%B4%A8%E7%9F%A9%E9%98%B5E,%E5%8D%95%E5%BA%94%E5%8F%98%E6%8D%A2%E7%9F%A9%E9%98%B5H%202023-01-04%2014.46.36.excalidraw.md), and the [dark exported image](attachments/%E5%9F%BA%E7%A1%80%E7%9F%A9%E9%98%B5F,%E6%9C%AC%E8%B4%A8%E7%9F%A9%E9%98%B5E,%E5%8D%95%E5%BA%94%E5%8F%98%E6%8D%A2%E7%9F%A9%E9%98%B5H%202023-01-04%2014.46.36.excalidraw.dark.svg)%%
##### E和F的关系
- 利用本质矩阵E和相机内参数矩阵相乘可以得到基础矩阵F