- 删除节点也可能导致AVL树的失衡，实际上删除节点和插入节点是一种==互逆的操作==：
1. 删除**非叶子节点**,该节点的值替换为该节点的前驱节点（或者后继节点），然后删除前驱节点
2.  删除**右子树的节点**导致AVL树失衡时，相当于在左子树插入节点导致AVL树失衡，即情况情况二或情况四。
3.  删除**左子树的节点**导致AVL树失衡时，相当于==在右子树插入节点==导致AVL树失衡，即情况情况一或情况三。
	1. ![](attachments/AVL%E6%A0%91%E7%9A%84%E5%88%A0%E9%99%A4%E8%8A%82%E7%82%B9%202022-10-30%2016.42.37.excalidraw.svg)
	2. ![](attachments/AVL%E6%A0%91%E7%9A%84%E5%88%A0%E9%99%A4%E8%8A%82%E7%82%B9%202022-11-17%2021.03.58.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/AVL%E6%A0%91%E7%9A%84%E5%88%A0%E9%99%A4%E8%8A%82%E7%82%B9%202022-11-17%2021.03.58.excalidraw.md), and the [dark exported image](attachments/AVL%E6%A0%91%E7%9A%84%E5%88%A0%E9%99%A4%E8%8A%82%E7%82%B9%202022-11-17%2021.03.58.excalidraw.dark.svg)%%
	3. ![AVL树插入节点并平衡](AVL树插入节点并平衡.md)
%%[🖋 Edit in Excalidraw](attachments/AVL%E6%A0%91%E7%9A%84%E5%88%A0%E9%99%A4%E8%8A%82%E7%82%B9%202022-10-30%2016.42.37.excalidraw.md), and the [dark exported image](attachments/AVL%E6%A0%91%E7%9A%84%E5%88%A0%E9%99%A4%E8%8A%82%E7%82%B9%202022-10-30%2016.42.37.excalidraw.dark.svg)%%