#### Kruskal算法求最小生成树
##### 步骤
- 初始是n个顶点,**无边**的非连通图T
- 将**边的权值**由小到大排序 #408x  #z408 
- 初始化并查集Rank
- 不断选取满足以下条件的边加入T(==遍历所有边==)
	- 当前未选取
	- 权重最小
	- 边的两个顶点在T中**不同连通分量**(==不成环==)
		- `if (Union(edges[i].begin, edges[i].end)) {}`
- 直到所有顶点在**一个连通分量上**
- ![](attachments/%E5%9B%BE%E7%9A%84%E6%9C%80%E5%B0%8F%E7%94%9F%E6%88%90%E6%A0%91%202022-10-23%2020.05.32.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E5%9B%BE%E7%9A%84%E6%9C%80%E5%B0%8F%E7%94%9F%E6%88%90%E6%A0%91%202022-10-23%2020.05.32.excalidraw.md), and the [dark exported image](attachments/%E5%9B%BE%E7%9A%84%E6%9C%80%E5%B0%8F%E7%94%9F%E6%88%90%E6%A0%91%202022-10-23%2020.05.32.excalidraw.dark.svg)%%
##### 复杂度和适用情况
- 存放 **边的集合** 的数据结构
	- ==堆==
		- [堆排序算法](堆排序算法.md)
	- **每次**选择最小权值边的时间复杂度$O(log|E|)$
- **生成树T**的描述方式
	- ==并查集==
	- [[利用并查集的等价类思想判断图的连通性]]
- 总的时间复杂度
	- $O(\mid E\mid \log \mid E\mid)$
	- 适合**边稀疏且顶点较多的图**