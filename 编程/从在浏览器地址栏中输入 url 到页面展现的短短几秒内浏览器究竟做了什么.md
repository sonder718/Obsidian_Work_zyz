##### 浏览器的多进程架构
- 一个进程还可以要求操作系统生成另一个进程来执行不同的任务，系统会为新的进程分配独立的内存，两个进程之间可以使用[[ IPC （Inter Process Communication）进程间通信]]进行通信。
- Chrome 采用**多进程架构**，其顶层存在一个 Browser process 用以协调浏览器的其它进程。
	- ![](attachments/Pasted%20image%2020230101144706.png)
	- ![](attachments/%E4%BB%8E%E5%9C%A8%E6%B5%8F%E8%A7%88%E5%99%A8%E5%9C%B0%E5%9D%80%E6%A0%8F%E4%B8%AD%E8%BE%93%E5%85%A5%20url%20%E5%88%B0%E9%A1%B5%E9%9D%A2%E5%B1%95%E7%8E%B0%E7%9A%84%E7%9F%AD%E7%9F%AD%E5%87%A0%E7%A7%92%E5%86%85%E6%B5%8F%E8%A7%88%E5%99%A8%E7%A9%B6%E7%AB%9F%E5%81%9A%E4%BA%86%E4%BB%80%E4%B9%88%202023-01-01%2014.48.11.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E4%BB%8E%E5%9C%A8%E6%B5%8F%E8%A7%88%E5%99%A8%E5%9C%B0%E5%9D%80%E6%A0%8F%E4%B8%AD%E8%BE%93%E5%85%A5%20url%20%E5%88%B0%E9%A1%B5%E9%9D%A2%E5%B1%95%E7%8E%B0%E7%9A%84%E7%9F%AD%E7%9F%AD%E5%87%A0%E7%A7%92%E5%86%85%E6%B5%8F%E8%A7%88%E5%99%A8%E7%A9%B6%E7%AB%9F%E5%81%9A%E4%BA%86%E4%BB%80%E4%B9%88%202023-01-01%2014.48.11.excalidraw.md), and the [dark exported image](attachments/%E4%BB%8E%E5%9C%A8%E6%B5%8F%E8%A7%88%E5%99%A8%E5%9C%B0%E5%9D%80%E6%A0%8F%E4%B8%AD%E8%BE%93%E5%85%A5%20url%20%E5%88%B0%E9%A1%B5%E9%9D%A2%E5%B1%95%E7%8E%B0%E7%9A%84%E7%9F%AD%E7%9F%AD%E5%87%A0%E7%A7%92%E5%86%85%E6%B5%8F%E8%A7%88%E5%99%A8%E7%A9%B6%E7%AB%9F%E5%81%9A%E4%BA%86%E4%BB%80%E4%B9%88%202023-01-01%2014.48.11.excalidraw.dark.svg)%%
##### 导航过程
- ![](attachments/Pasted%20image%2020230101145037.png)
- **处理输入**
	- UI thread 需要判断用户输入的是 URL 还是 query；
- **开始导航**
	- network thread 会执行 DNS 查询
		- [DNS域名解析过程](../考研/408/计算机网络/DNS域名解析过程.md)
	- 随后为请求建立 TLS 连接
		- [[TLS协议与SSL协议]]