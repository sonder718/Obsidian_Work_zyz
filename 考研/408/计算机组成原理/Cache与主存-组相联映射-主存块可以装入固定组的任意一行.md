## Cache与主存-组相联映射-主存块可以装入固定组的任意一行
### 映射关系
- Cache分为Q个组,每个主存块可以装入**固定组**的**任意一行**
	- - #注意 组号通常从0开始
- **组间直接映射**
	- Q=Cache行数时即有Cache行数个组,直接主存块号求模映射到cache中
	- 🐱即根据块号一一对应
- **组内全相联**:
	- Q=1时即只有一个组,相当于全相联
	- **r路组相联**
		- **每组**有r个cache行 #注意 不是有r个cache组
	- **Cache组号=主存块号 mod Cache组数**
	- 🐱即特定组内按内容寻址,因此==没有==组内地址一说
![](%E9%AB%98%E9%80%9F%E7%BC%93%E5%86%B2%E5%AD%98%E5%82%A8%E5%99%A8%202022-09-11%2017.40.48.excalidraw.svg)
%%[🖋 Edit in Excalidraw](%E9%AB%98%E9%80%9F%E7%BC%93%E5%86%B2%E5%AD%98%E5%82%A8%E5%99%A8%202022-09-11%2017.40.48.excalidraw.md)%%
### 访存过程
- 根据中间c位cache组号,找到cache第X组
- **对比**cache第X组中**每一行**的标记位和主存高t位**标记**
	- **相等,且有效位为1**:命中,根据块内地址(`主存地址的低位)在对应cache行存取信息
	- **不相等/有效位为0**:不命中,从主存读到cache对应行,有效位置1,更新标记地址,地址中内容送CPU