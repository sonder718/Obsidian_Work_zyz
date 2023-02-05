- [dair-ai/GNNs-Recipe：🟠了解图神经网络（GNN）的学习指南 (github.com)](https://github.com/dair-ai/GNNs-Recipe)
- [一文读懂图卷积GCN - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/89503068)
- [图卷积和消息传递理论的可视化详解 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/462642687)
- [浅析图卷积神经网络 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/37091549)
- [Understanding Convolutions on Graphs (distill.pub)](https://distill.pub/2021/understanding-gnns/?continueFlag=8eef312d0acc7809a18878124b7cff86)
# 相关
- [图注意力网络GAT](图注意力网络GAT.md)
# GCN的本质
- **消息传递**聚合邻居节点信息
- 不同的**聚合方式**
	- [零基础多图详解图神经网络（GNN/GCN）【论文精读】_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1iT4y1d7zP/?spm_id_from=333.880.top_right_bar_window_custom_collection.content.click&vd_source=a035df14d498cc5a51f3299bc26b3e65)
		- ![400](attachments/Pasted%20image%2020230129153243.png)
# 消息传递
## 最朴素的思想-不进行消息传递
- 分别进行MLP,N层后放入输出层分类
- ![](attachments/Pasted%20image%2020230129153556.png)
## 简单的消息传递方式-自身+邻居信息
- **聚合**:自身+邻居信息
- **更新**:放入MLP
- N层之后将汇聚一个很大的图的信息
	- ![](attachments/Pasted%20image%2020230129160201.png)
- ![600](attachments/Pasted%20image%2020230129153925.png)34分钟

- **Graph Embedding**
	- ![](attachments/Pasted%20image%2020230105170905.png)
- **图卷积与卷积**
	- 乘以 $A^n$ 会导致特征从 n 跳距离节点传播，所以可以通过将乘法添加到邻接矩阵的更高次方来扩展“感受野
	- ![](attachments/%E5%9B%BE%E5%8D%B7%E7%A7%AFGCN%202023-01-05%2017.16.14.excalidraw.svg)%%[🖋 Edit in Excalidraw](attachments/%E5%9B%BE%E5%8D%B7%E7%A7%AFGCN%202023-01-05%2017.16.14.excalidraw.md), and the [dark exported image](attachments/%E5%9B%BE%E5%8D%B7%E7%A7%AFGCN%202023-01-05%2017.16.14.excalidraw.dark.svg)%%
	- ![](attachments/%E5%9B%BE%E5%8D%B7%E7%A7%AFGCN%202023-01-05%2017.10.00.excalidraw.svg)%%[🖋 Edit in Excalidraw](attachments/%E5%9B%BE%E5%8D%B7%E7%A7%AFGCN%202023-01-05%2017.10.00.excalidraw.md), and the [dark exported image](attachments/%E5%9B%BE%E5%8D%B7%E7%A7%AFGCN%202023-01-05%2017.10.00.excalidraw.dark.svg)%%