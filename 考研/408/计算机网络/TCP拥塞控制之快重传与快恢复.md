##### TCP拥塞控制之快重传与快恢复
- ![](attachments/TCP%E6%8B%A5%E5%A1%9E%E6%8E%A7%E5%88%B6%202022-11-11%2019.57.32.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/TCP%E6%8B%A5%E5%A1%9E%E6%8E%A7%E5%88%B6%202022-11-11%2019.57.32.excalidraw.md), and the [dark exported image](attachments/TCP%E6%8B%A5%E5%A1%9E%E6%8E%A7%E5%88%B6%202022-11-11%2019.57.32.excalidraw.dark.svg)%%
- 
- **快重传**
	- 冗余ACK技术
		- [TCP可靠传输之冗余ACK重传(快速重传)](考研/408/计算机网络/TCP可靠传输之冗余ACK重传(快速重传).md)
	- 当发送方连续收到**三个**==冗余的==ACK报文时,==直接重传==对方尚未收到的报文段,而不必等待那个报文段设置的重传计时器超时。
		- #注意 （其实是收到4个同样的ACK，第一个是正常的，后三个才是冗余的）
		- ![](attachments/TCP%E6%8B%A5%E5%A1%9E%E6%8E%A7%E5%88%B6%E4%B9%8B%E5%BF%AB%E9%87%8D%E4%BC%A0%E4%B8%8E%E5%BF%AB%E6%81%A2%E5%A4%8D%202022-11-20%2017.11.50.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/TCP%E6%8B%A5%E5%A1%9E%E6%8E%A7%E5%88%B6%E4%B9%8B%E5%BF%AB%E9%87%8D%E4%BC%A0%E4%B8%8E%E5%BF%AB%E6%81%A2%E5%A4%8D%202022-11-20%2017.11.50.excalidraw.md), and the [dark exported image](attachments/TCP%E6%8B%A5%E5%A1%9E%E6%8E%A7%E5%88%B6%E4%B9%8B%E5%BF%AB%E9%87%8D%E4%BC%A0%E4%B8%8E%E5%BF%AB%E6%81%A2%E5%A4%8D%202022-11-20%2017.11.50.excalidraw.dark.svg)%%
- **快恢复**
	- 执行时机
		- 当发送方**连续收到三个冗余ACK(即重复确认)时**
	- 执行操作
		- 执行“乘法减小”算法,把**慢开始门限ssthresh设置为此时发送方cwnd的一半。**
		- 把cwnd值设置为慢开始门限==ssthresh改变后的数值==,然后开始执行==拥塞避免算法==(“加法增大”) 
			- ==跳过了慢开始==过程,所以被称为快恢复
	- 这是为了预防网络发生拥塞。但发送方现在认为网络很可能**没有发生(严重)拥塞**,否则就不会有几个报文段连续到达接收方,也不会连续收到重复确认
		- **超时事件发生时依旧执行拥塞处理操作**