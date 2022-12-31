##### Tips
- 删除节点v,再添加节点v
	- 如v是**叶节点**,则排序树==可能不相同==
	- 如v是**非叶节点**,则排序树==可能不相同==
	- ![](attachments/%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91AVL%E6%A0%91%202022-11-17%2021.29.56.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91AVL%E6%A0%91%202022-11-17%2021.29.56.excalidraw.md), and the [dark exported image](attachments/%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91AVL%E6%A0%91%202022-11-17%2021.29.56.excalidraw.dark.svg)%%
##### 平衡二叉树
- 树上**任一节点**的左右子树深度之差<=1
	- #注意 不能缺少==任意节点==字样
##### 什么是AVL树 
- **AVL树**是最先发明的==自平衡二叉查找树==。
- 在AVL树中任何节点的==两个子树的高度最大差别为1==，所以它也被称为**高度平衡树**。
- **平衡因子**
	- 定义结点**左子树与右子树的高度差**为该结点的平衡因子
		- #注意 左子树高-右子树高
	- 平衡二叉树结点的平衡因子的值只可能是-1、0或1。
- 增加和删除可能需要通过==一次或多次树旋转==来重新平衡这个树。
- AVL树得名于它的发明者G. M. Adelson-Velsky和E. M. Landis
- ![](attachments/Pasted%20image%2020221030151739.png)
##### 如何使一棵AVL树保持平衡
- 构建AVL树的核心
	- 在插入和删除节点时使二叉排序树保证平衡
- 二叉排序树保证平衡的**基本思想**
	- 每当在二叉排序树中插入(或删除)一个结点时
	- 首先检查其插入路径上的结点**是否因为此次操作而导致了不平衡**。
	- 若导致了不平衡,则先找到插入路径上的需满足以下条件结点A
		- ==离插入结点尽可能近==
		- **平衡因子的绝对值大于1**
	- 对以A为根的子树,在保持二叉排序树特性的前提下,调整各结点的位置关系,使达到平衡
		- 即调整==最小不平衡子树== #注意
	- ![](attachments/%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91AVL%E6%A0%91%202022-10-30%2015.25.41.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91AVL%E6%A0%91%202022-10-30%2015.25.41.excalidraw.md), and the [dark exported image](attachments/%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91AVL%E6%A0%91%202022-10-30%2015.25.41.excalidraw.dark.svg)%%
##### 构建一棵平衡二叉树
###### 创建一棵空的AVL树
- 引入高度属性,方便计算平衡因子
- ![](attachments/%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91AVL%E6%A0%91%202022-10-30%2015.34.30.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91AVL%E6%A0%91%202022-10-30%2015.34.30.excalidraw.md), and the [dark exported image](attachments/%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91AVL%E6%A0%91%202022-10-30%2015.34.30.excalidraw.dark.svg)%%
###### 插入节点
[[AVL树插入节点并平衡]]
###### 删除节点
[[AVL树的删除节点]]
###### 查找
[[AVL树的查找]]

##### 特殊的AVL树
- #注意 平衡二叉树不一定是满二叉树
- #注意 平衡二叉树**最少需要**节点数的递推公式$n_{h}=1+n_{h-1}+n_{h-2}$
	- $n_{1}=1,n_{2}=2.n_{3}=4,n_{4}=7,n_{5}=12,n_{6}=20$
	- 🐱含有20个节点的平衡二叉树的最大深度为6
	- 🐱具有5层节点的AVL树至少有12个节点
		- ![](attachments/%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91AVL%E6%A0%91%202022-11-17%2017.42.13.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91AVL%E6%A0%91%202022-11-17%2017.42.13.excalidraw.md), and the [dark exported image](attachments/%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91AVL%E6%A0%91%202022-11-17%2017.42.13.excalidraw.dark.svg)%%
	- 🐱具有4层节点的AVL树至少有7个节点
		- ![](attachments/%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91AVL%E6%A0%91%202022-11-17%2017.25.22.excalidraw.svg)%%[🖋 Edit in Excalidraw](attachments/%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91AVL%E6%A0%91%202022-11-17%2017.25.22.excalidraw.md), and the [dark exported image](attachments/%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91AVL%E6%A0%91%202022-11-17%2017.25.22.excalidraw.dark.svg)%%
