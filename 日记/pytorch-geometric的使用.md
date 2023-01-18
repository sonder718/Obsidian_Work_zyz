##### 安装
```bash
pip uninstall torch-cluster
pip uninstall torch-scatter
pip uninstall torch-sparse 
pip uninstall torch-spline-conv
pip uninstall torch-geometric

pip install --no-index torch-cluster -f https://pytorch-geometric.com/whl/torch-1.8.1+cu111.html
pip install --no-index torch-scatter -f https://pytorch-geometric.com/whl/torch-1.8.1+cu111.html
pip install --no-index torch-sparse -f https://pytorch-geometric.com/whl/torch-1.8.1+cu111.html
pip install --no-index torch-spline-conv -f https://pytorch-geometric.com/whl/torch-1.8.1+cu111.html
pip install torch-geometric

```
##### 使用
- **图的表示方式**
	- 虽然图形只有两条边，但我们需要定义四个索引元组来==解释一条边的两个方向==
	- ![](attachments/Pasted%20image%2020230115205145.png)
	- ![](attachments/pytorch-geometric%E7%9A%84%E4%BD%BF%E7%94%A8%202023-01-15%2020.52.40.excalidraw.svg)%%[🖋 Edit in Excalidraw](attachments/pytorch-geometric%E7%9A%84%E4%BD%BF%E7%94%A8%202023-01-15%2020.52.40.excalidraw.md), and the [dark exported image](attachments/pytorch-geometric%E7%9A%84%E4%BD%BF%E7%94%A8%202023-01-15%2020.52.40.excalidraw.dark.svg)%%
- **生成K近邻**
	- ![](attachments/Pasted%20image%2020230115212222.png)
	- ![](attachments/Pasted%20image%2020230115212212.png)
	- 
- edge_index 转 邻接矩阵
	- [(57条消息) pyG edge_index矩阵 转 普通邻接矩阵，COO稀疏矩阵，包含同质图和异质图_hmtccss的博客-CSDN博客](https://blog.csdn.net/qq_36604702/article/details/125548349)