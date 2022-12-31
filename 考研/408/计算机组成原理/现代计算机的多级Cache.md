## 现代计算机的多级Cache
- 指令预取等技术的发展,需要将指令cache与数据cache分开
- 分离指令与数据cache可以充分利用指令和数据的不同局部性来优化性能,并**减少了指令流水线的冲突**
	- [[流水线的冒险与处理流水线冲突]]
- ![](attachments/Pasted%20image%2020221130213654.png)
- 离CPU最近的是L1 Cache
- 通常情况下，**L1 Cache**会被划分成**指令Cache**和**数据Cache**，分别用于存储指令和数据，而L2 Cache、L3 Cahce等则是指令和数据混合存储
- 两个Cache系统的示例
![](%E9%AB%98%E9%80%9F%E7%BC%93%E5%86%B2%E5%AD%98%E5%82%A8%E5%99%A8%202022-09-12%2015.54.14.excalidraw.svg)
%%[🖋 Edit in Excalidraw](%E9%AB%98%E9%80%9F%E7%BC%93%E5%86%B2%E5%AD%98%E5%82%A8%E5%99%A8%202022-09-12%2015.54.14.excalidraw.md)%%
- L2cache的速度远大于主存,避免因频繁写造成的写缓存饱和溢出