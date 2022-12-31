
#### AVL树插入节点并平衡
- 首先插入节点待插入节点A
- #疑问 原集合中的重复节点,AVL树如何处理
- **插入节点方式1**
	- ![](attachments/%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91AVL%E6%A0%91%202022-10-30%2015.37.48.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91AVL%E6%A0%91%202022-10-30%2015.37.48.excalidraw.md), and the [dark exported image](attachments/%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91AVL%E6%A0%91%202022-10-30%2015.37.48.excalidraw.dark.svg)%%
- **插入节点方式2**
	- ![](attachments/AVL%E6%A0%91%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9%E5%B9%B6%E5%B9%B3%E8%A1%A1%202022-10-30%2015.59.44.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/AVL%E6%A0%91%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9%E5%B9%B6%E5%B9%B3%E8%A1%A1%202022-10-30%2015.59.44.excalidraw.md), and the [dark exported image](attachments/AVL%E6%A0%91%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9%E5%B9%B6%E5%B9%B3%E8%A1%A1%202022-10-30%2015.59.44.excalidraw.dark.svg)%%
#### 四种平衡方式
- #注意 在==最小不平衡树==上旋转
- LL旋转是**右**单旋转 #注意 L和右实际是**相反的**
- LR是先**左**旋后**右**旋 #注意 不是先右旋后左旋
##### 左单旋转
- 当我们在==最小不平衡树上的==**右子树插入右孩子导致AVL失衡**时，我们需要进行**单左旋**调整。旋转围绕最小失衡子树的==根节点==进行。
	- 原根节点作为新根节点的左子树
	- 新根节点的**原左子树**作为原根节点的**新右子树** #z408 
- ![](attachments/AVL%E6%A0%91%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9%E5%B9%B6%E5%B9%B3%E8%A1%A1%202022-10-30%2016.21.43.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/AVL%E6%A0%91%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9%E5%B9%B6%E5%B9%B3%E8%A1%A1%202022-10-30%2016.21.43.excalidraw.md), and the [dark exported image](attachments/AVL%E6%A0%91%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9%E5%B9%B6%E5%B9%B3%E8%A1%A1%202022-10-30%2016.21.43.excalidraw.dark.svg)%%
- ![](attachments/AVL%E6%A0%91%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9%E5%B9%B6%E5%B9%B3%E8%A1%A1%202022-11-17%2021.00.15.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/AVL%E6%A0%91%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9%E5%B9%B6%E5%B9%B3%E8%A1%A1%202022-11-17%2021.00.15.excalidraw.md), and the [dark exported image](attachments/AVL%E6%A0%91%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9%E5%B9%B6%E5%B9%B3%E8%A1%A1%202022-11-17%2021.00.15.excalidraw.dark.svg)%%
- ![](attachments/AVL%E6%A0%91%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9%E5%B9%B6%E5%B9%B3%E8%A1%A1%202022-11-17%2021.03.07.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/AVL%E6%A0%91%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9%E5%B9%B6%E5%B9%B3%E8%A1%A1%202022-11-17%2021.03.07.excalidraw.md), and the [dark exported image](attachments/AVL%E6%A0%91%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9%E5%B9%B6%E5%B9%B3%E8%A1%A1%202022-11-17%2021.03.07.excalidraw.dark.svg)%%
##### 右单旋转
- 此时的插入情况是==最小不平衡树上的==“**左子树上插入左孩子导致AVL树失衡**”，我们需要进行**单右旋**调整。
- ![](attachments/AVL%E6%A0%91%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9%E5%B9%B6%E5%B9%B3%E8%A1%A1%202022-10-30%2016.24.16.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/AVL%E6%A0%91%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9%E5%B9%B6%E5%B9%B3%E8%A1%A1%202022-10-30%2016.24.16.excalidraw.md), and the [dark exported image](attachments/AVL%E6%A0%91%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9%E5%B9%B6%E5%B9%B3%E8%A1%A1%202022-10-30%2016.24.16.excalidraw.dark.svg)%%
##### 先右子树右旋后整个不平衡树左旋
- 如第一次旋转后，AVL树仍旧处于不平衡的状态,第二次旋转再次进行调整。
- 在最小不平衡树的**右孩子的左子树**插入导致AVL树失衡
	- 对==最小不平衡树==的==右子树==右旋 #z408 
	- 对整个==最小不平衡树==左旋 #z408 
- ![](attachments/AVL%E6%A0%91%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9%E5%B9%B6%E5%B9%B3%E8%A1%A1%202022-10-30%2016.34.35.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/AVL%E6%A0%91%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9%E5%B9%B6%E5%B9%B3%E8%A1%A1%202022-10-30%2016.34.35.excalidraw.md), and the [dark exported image](attachments/AVL%E6%A0%91%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9%E5%B9%B6%E5%B9%B3%E8%A1%A1%202022-10-30%2016.34.35.excalidraw.dark.svg)%%
- ![](attachments/AVL%E6%A0%91%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9%E5%B9%B6%E5%B9%B3%E8%A1%A1%202022-11-17%2018.09.29.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/AVL%E6%A0%91%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9%E5%B9%B6%E5%B9%B3%E8%A1%A1%202022-11-17%2018.09.29.excalidraw.md), and the [dark exported image](attachments/AVL%E6%A0%91%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9%E5%B9%B6%E5%B9%B3%E8%A1%A1%202022-11-17%2018.09.29.excalidraw.dark.svg)%%
- 
##### 先左旋后右旋
- 在最小不平衡树的**左孩子的右子树**插入导致AVL树失衡
	- 对==最小不平衡树==的==左子树==左旋
	- 对整个==最小不平衡树==右旋
- ![](attachments/AVL%E6%A0%91%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9%E5%B9%B6%E5%B9%B3%E8%A1%A1%202022-10-30%2016.37.48.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/AVL%E6%A0%91%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9%E5%B9%B6%E5%B9%B3%E8%A1%A1%202022-10-30%2016.37.48.excalidraw.md), and the [dark exported image](attachments/AVL%E6%A0%91%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9%E5%B9%B6%E5%B9%B3%E8%A1%A1%202022-10-30%2016.37.48.excalidraw.dark.svg)%%