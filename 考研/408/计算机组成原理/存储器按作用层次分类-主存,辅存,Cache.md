##### 存储器按作用层次分类-主存,辅存,Cache
- **主存储器**(主存,内存)
	- CPU可以**直接**随机地进行访问
- **辅助存储器**(辅存,外存)
	- 内容调入主存才能被CPU访问
- **高速缓冲存储器**(cache)
	- 用来存放当前CPU经常使用的指令和数据
	- 速度可以CPU速度相匹配
	- 通常制作在==CPU==中

##### 多级层次的存储系统
- **Cache-主存层**
	- 解决CPU与主存速度不匹配
	- 数据调动==硬件==自动完成,对==所有==程序员透明 #注意
- **主存-辅存层**
	- 解决存储系统的容量问题
	- 数据调动硬件和==操作系统==完成,对**应用**程序员透明 #注意
	- **虚拟存储系统**
![](attachments/%E5%AD%98%E5%82%A8%E5%99%A8%E6%8C%89%E4%BD%9C%E7%94%A8%E5%B1%82%E6%AC%A1%E5%88%86%E7%B1%BB-%E4%B8%BB%E5%AD%98,%E8%BE%85%E5%AD%98,Cache%202022-11-30%2020.19.27.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E5%AD%98%E5%82%A8%E5%99%A8%E6%8C%89%E4%BD%9C%E7%94%A8%E5%B1%82%E6%AC%A1%E5%88%86%E7%B1%BB-%E4%B8%BB%E5%AD%98,%E8%BE%85%E5%AD%98,Cache%202022-11-30%2020.19.27.excalidraw.md), and the [dark exported image](attachments/%E5%AD%98%E5%82%A8%E5%99%A8%E6%8C%89%E4%BD%9C%E7%94%A8%E5%B1%82%E6%AC%A1%E5%88%86%E7%B1%BB-%E4%B8%BB%E5%AD%98,%E8%BE%85%E5%AD%98,Cache%202022-11-30%2020.19.27.excalidraw.dark.svg)%%
