- 后退N帧协议**数据传输率的计算**
	- #注意  **每一帧**的数据传输率,而不是整个信道一段时间的数据传输率
	- #注意 Mb/s和MB/s的差异
	- 如果不考虑传输延迟,仅考虑传播时延,每个数据帧的数据传输率是否等于信道带宽
		- **不等于!**
	- #注意 ![](attachments/%E6%B5%81%E9%87%8F%E6%8E%A7%E5%88%B6,%E5%8F%AF%E9%9D%A0%E4%BC%A0%E8%BE%93%E4%B8%8E%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%202022-10-07%2017.22.27.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E6%B5%81%E9%87%8F%E6%8E%A7%E5%88%B6,%E5%8F%AF%E9%9D%A0%E4%BC%A0%E8%BE%93%E4%B8%8E%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%202022-10-07%2017.22.27.excalidraw.md)%%
- #注意 对于GBN协议,可以让发送方一个数据帧的发送周期内一直发送数据,甚至使得**信道利用率为1** #注意
	- 一个数据帧的发送周期内发送s帧
	- 发送窗口大小W>=s恒成立
	- ![](attachments/%E6%B5%81%E9%87%8F%E6%8E%A7%E5%88%B6,%E5%8F%AF%E9%9D%A0%E4%BC%A0%E8%BE%93%E4%B8%8E%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%202022-10-08%2015.34.21.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E6%B5%81%E9%87%8F%E6%8E%A7%E5%88%B6,%E5%8F%AF%E9%9D%A0%E4%BC%A0%E8%BE%93%E4%B8%8E%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%202022-10-08%2015.34.21.excalidraw.md)%%