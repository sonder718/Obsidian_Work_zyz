#### Tips
- 删除节点v,再添加节点v
	- 如v是**叶节点**,则排序树不变
	- 如v是**非叶节点**,则排序树变化
		- ![](attachments/%E4%BA%8C%E5%8F%89%E6%8E%92%E5%BA%8F%E6%A0%91BST%E6%A0%91%202022-11-17%2021.26.41.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E4%BA%8C%E5%8F%89%E6%8E%92%E5%BA%8F%E6%A0%91BST%E6%A0%91%202022-11-17%2021.26.41.excalidraw.md), and the [dark exported image](attachments/%E4%BA%8C%E5%8F%89%E6%8E%92%E5%BA%8F%E6%A0%91BST%E6%A0%91%202022-11-17%2021.26.41.excalidraw.dark.svg)%%
#### BST树是什么
- ==二叉==查找树（**Binary** Search Tree），简写BST
- 任何一个节点的**左**子树上的点，都必须**小于**当前节点。
	-  左子树所有节点的关键字小于根节点的关键字
	- 因此最左下的叶子节点是**最小节点**
- 任何一个节点的**右**子树上的点，都必须**大于**当前节点。
	- 右子树所有节点的关键字大于根节点的关键字
	- 最右下的叶子节点是**最大节点**
- 任何一棵子树，也都满足上面两个条件。
	- 左子树和右子树也是二叉排序树
- 二叉查找树中，是==不存在重复节点==的。 #注意 
- ![](attachments/%E4%BA%8C%E5%8F%89%E6%8E%92%E5%BA%8F%E6%A0%91BST%E6%A0%91%202022-10-26%2019.34.44.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E4%BA%8C%E5%8F%89%E6%8E%92%E5%BA%8F%E6%A0%91BST%E6%A0%91%202022-10-26%2019.34.44.excalidraw.md), and the [dark exported image](attachments/%E4%BA%8C%E5%8F%89%E6%8E%92%E5%BA%8F%E6%A0%91BST%E6%A0%91%202022-10-26%2019.34.44.excalidraw.dark.svg)%%
#### 如何利用BST树进行查找
- **给定**待查找序列{50,30,20,40,70,60,80}
- 根据待查找序列**构建一棵BST树**
	- 不断插入节点,动态构建BST树
		- **插入数据的顺序影响很大**
	- #注意 ==无需==移动节点,复杂度$O(\log_{2}n)$,适合动态查找表
	- [[二叉排序树BST树-插入元素]]
	- ![](attachments/%E4%BA%8C%E5%8F%89%E6%8E%92%E5%BA%8F%E6%A0%91BST%E6%A0%91%202022-10-26%2019.41.47.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E4%BA%8C%E5%8F%89%E6%8E%92%E5%BA%8F%E6%A0%91BST%E6%A0%91%202022-10-26%2019.41.47.excalidraw.md), and the [dark exported image](attachments/%E4%BA%8C%E5%8F%89%E6%8E%92%E5%BA%8F%E6%A0%91BST%E6%A0%91%202022-10-26%2019.41.47.excalidraw.dark.svg)%%
- 查找元素时,在构造的BST树中进行**查找**
	- [[二叉排序树BST树-查找元素]]
	- ==中序遍历==得到有序数列
	- 如果是**平衡二叉树**(左右子树高度差的绝对值<=1)
		- $O(log_{2}n)$
		- ![](attachments/Pasted%20image%2020221026200354.png)
		- ASL=$\frac{1+2*2+3*4+4*3}{10}=2.9$
	- 如果是单支树
		- $O(n)$
- 删除元素时,构造的BST树中**删除**相应元素
	- [[二叉排序树BST树-删除元素]]
