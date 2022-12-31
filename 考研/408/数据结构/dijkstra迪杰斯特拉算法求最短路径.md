### Tips
- #注意 当边上有==负权值==，不适用
	- ![](attachments/Pasted%20image%2020221024195823.png)
		- {0} Distance[1]=7,Distance[2]=5
		- {0,1} Distance[1]=7,Distance[2]=-2
- **时间复杂度**
	- 源点到==特定顶点==的时间复杂度和到==所有顶点==的时间复杂度相同
	- $O(|V|^{2})$
### 输入
- 图G
	- n个节点
- 起点v0
### 设置数据结构
- **集合S**
	- 记录所有==已求得==最短路径的顶点
- **Distance[]**
	- 记录==从源点v0==到==其他各顶点==的当前最短路径
	- 大小为n
	- ![](attachments/dijkstra%E8%BF%AA%E6%9D%B0%E6%96%AF%E7%89%B9%E6%8B%89%E7%AE%97%E6%B3%95%E6%B1%82%E6%9C%80%E7%9F%AD%E8%B7%AF%E5%BE%84%202022-10-24%2017.03.47.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/dijkstra%E8%BF%AA%E6%9D%B0%E6%96%AF%E7%89%B9%E6%8B%89%E7%AE%97%E6%B3%95%E6%B1%82%E6%9C%80%E7%9F%AD%E8%B7%AF%E5%BE%84%202022-10-24%2017.03.47.excalidraw.md), and the [dark exported image](attachments/dijkstra%E8%BF%AA%E6%9D%B0%E6%96%AF%E7%89%B9%E6%8B%89%E7%AE%97%E6%B3%95%E6%B1%82%E6%9C%80%E7%9F%AD%E8%B7%AF%E5%BE%84%202022-10-24%2017.03.47.excalidraw.dark.svg)%%
- **Path[]**
	- 记录==从源点v0==到==其他各顶点==的当前最短路径的==前驱节点==
	- **Path[i]** 即v0到vi的最短路径上,vi的前驱节点
		- 🐱 已知Distance[c]=10,Path[c]=b,Distance[b]=5,Path[b]=a
			- 则可以利用path反向求得最短路径
			- a->c的最短路径的前驱是b
			- a->b的最短路径的前驱是a
			- 求得a->c的最短路径是cba
	- 大小为n
### 算法过程
- #注意 选节点的顺序与最短路径的节点顺序无关
![](attachments/dijkstra%E8%BF%AA%E6%9D%B0%E6%96%AF%E7%89%B9%E6%8B%89%E7%AE%97%E6%B3%95%E6%B1%82%E6%9C%80%E7%9F%AD%E8%B7%AF%E5%BE%84%202022-10-24%2019.49.13.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/dijkstra%E8%BF%AA%E6%9D%B0%E6%96%AF%E7%89%B9%E6%8B%89%E7%AE%97%E6%B3%95%E6%B1%82%E6%9C%80%E7%9F%AD%E8%B7%AF%E5%BE%84%202022-10-24%2019.49.13.excalidraw.md), and the [dark exported image](attachments/dijkstra%E8%BF%AA%E6%9D%B0%E6%96%AF%E7%89%B9%E6%8B%89%E7%AE%97%E6%B3%95%E6%B1%82%E6%9C%80%E7%9F%AD%E8%B7%AF%E5%BE%84%202022-10-24%2019.49.13.excalidraw.dark.svg)%%