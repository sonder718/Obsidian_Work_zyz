##### 什么是B树
- 一棵**m阶B树**(balanced tree of order m)是一棵==平衡==的==m路搜索树==
	- **所有节点平衡因子都为0** #注意 #408x f
	- m阶表示了一个结点最多有多少个孩子结点
		- 🐱当m取2时，就是我们常见的二叉搜索树
- **m阶**
	- 所有节点的**孩子个数的最大值**
- **关键字**/键/Key
	- ![](attachments/%E5%A4%9A%E8%B7%AF%E5%B9%B3%E8%A1%A1%E6%9F%A5%E6%89%BE%E6%A0%91B%E6%A0%91%202022-10-30%2021.13.35.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E5%A4%9A%E8%B7%AF%E5%B9%B3%E8%A1%A1%E6%9F%A5%E6%89%BE%E6%A0%91B%E6%A0%91%202022-10-30%2021.13.35.excalidraw.md), and the [dark exported image](attachments/%E5%A4%9A%E8%B7%AF%E5%B9%B3%E8%A1%A1%E6%9F%A5%E6%89%BE%E6%A0%91B%E6%A0%91%202022-10-30%2021.13.35.excalidraw.dark.svg)%%
- 一棵**m阶的B树**定义如下：
	- **排序方式**
		- 所有节点关键字是按**递增**次序排列 #408x 
		- 遵循**左小右大**原则
	- **子节点数**
		- 非叶节点的子节点数$>1 且\leq m$
			- m>=2，空树除外
			- 🐱m=2则是2叉树,m=3则是3叉
	- **非根节点关键字数**
		- 节点的关键字数量$\geq ceil(m/2)-1$个 #注意 #408x 
			- 🐱 m=5时 >=2
		- 节点的关键字数量$\leq m-1$个
			- 🐱  m=5时 <=4
			- ceil()是个朝**正无穷**方向取整的函数 如ceil(1.1)结果为2
	- **根节点**关键字数
		- 节点的关键字数量$\geq 1$个 #408x 
			- 🐱 m=5时 >=2
		- 节点的关键字数量$\leq m-1$个
			- #注意 根节点只有一个,但关键字有多个,不要搞混
	- **叶子节点**
		- n个关键字对应着==n+1==种查询失败的可能性,即==n+1==个叶子节点 #注意                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
		- 所有叶子节点均在同一层,**并且不带信息**
			- 可以视为**外部节点**
			- 实际上这些节点**并不存在**,指向这些节点的指针为空
	- **终端节点**
		- 最底层,==非叶子节点== #注意
	- n个关键字
		- **最大高度H**
			- $H\leq \log _{\left[ \frac{m}{2} \right]} (\frac{n+1}{2}+1)$
		- **最小高度H**
			- $H\geq \log _{m}(n+1)$
	- ![](attachments/%E5%A4%9A%E8%B7%AF%E5%B9%B3%E8%A1%A1%E6%9F%A5%E6%89%BE%E6%A0%91B%E6%A0%91%202022-10-30%2021.09.40.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E5%A4%9A%E8%B7%AF%E5%B9%B3%E8%A1%A1%E6%9F%A5%E6%89%BE%E6%A0%91B%E6%A0%91%202022-10-30%2021.09.40.excalidraw.md), and the [dark exported image](attachments/%E5%A4%9A%E8%B7%AF%E5%B9%B3%E8%A1%A1%E6%9F%A5%E6%89%BE%E6%A0%91B%E6%A0%91%202022-10-30%2021.09.40.excalidraw.dark.svg)%%  
