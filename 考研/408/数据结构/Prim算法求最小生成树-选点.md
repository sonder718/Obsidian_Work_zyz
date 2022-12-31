#### Prim算法求最小生成树
##### 步骤
- 任选**一个顶点A**作为起点加入树T
	- 可以用图的存储方式存最小生成树
- 选距离==树T的顶点集合==最近的顶点B(==B不在树中==),边(A,B)加入树
- ...
- ![](attachments/%E5%9B%BE%E7%9A%84%E6%9C%80%E5%B0%8F%E7%94%9F%E6%88%90%E6%A0%91%202022-10-23%2019.51.40.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E5%9B%BE%E7%9A%84%E6%9C%80%E5%B0%8F%E7%94%9F%E6%88%90%E6%A0%91%202022-10-23%2019.51.40.excalidraw.md), and the [dark exported image](attachments/%E5%9B%BE%E7%9A%84%E6%9C%80%E5%B0%8F%E7%94%9F%E6%88%90%E6%A0%91%202022-10-23%2019.51.40.excalidraw.dark.svg)%%
##### 复杂度和适用情况
- 时间复杂度 $O(|V|^2)$
	- ==不依赖于|E|==
- 适用于求解==边稠密==的图