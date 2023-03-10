##### Tips
- ❌只有客户端能主动释放连接
- ![TCP报文段](考研/408/计算机网络/TCP报文段.md#^xi21ce)
	- 因此在第1次和第3次挥手时释放连接
- ![](attachments/TCP%E8%BF%9E%E6%8E%A5%E7%9A%84%E9%87%8A%E6%94%BE-%E5%9B%9B%E6%AC%A1%E6%8C%A5%E6%89%8B%202022-11-09%2015.58.03.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/TCP%E8%BF%9E%E6%8E%A5%E7%9A%84%E9%87%8A%E6%94%BE-%E5%9B%9B%E6%AC%A1%E6%8C%A5%E6%89%8B%202022-11-09%2015.58.03.excalidraw.md), and the [dark exported image](attachments/TCP%E8%BF%9E%E6%8E%A5%E7%9A%84%E9%87%8A%E6%94%BE-%E5%9B%9B%E6%AC%A1%E6%8C%A5%E6%89%8B%202022-11-09%2015.58.03.excalidraw.dark.svg)%%
##### 第一次挥手
- **客户机**打算关闭连接时,向其TCP发送连接释放报文段,并停止发送数据,主动**关闭TCP连接**.
	- TCP是全双工的,即可以想象为一条TCP连接上有两条数据通路,**发送FIN的一端不能再发送数据**,即关闭了其中一条数据通路,但**对方还可以发送数据**
- 该报文段的终止位==FIN置1==,序号seq=u
	- 它等于**前面已传送过的数据的最后一个字节的序号加1**, FIN报文段即使不携带数据,也==消耗掉一个序号==。
- 这时,TCP客户进程进入==FINWAIT-1 (终止等待1)==状态。
##### 第二次挥手
- **服务器**收到连接释放报文段后即发出确认 **ACK=1**
	- 确认号ack=u+1
	- 序号seq=v
		- 等于它前面已传送过的数据的**最后一个字节的序号加1**。
- 然后服务器进入CLOSE-WAIT(关闭等待)状态。
- 客户机收到后进入进程进入==FINWAIT-2 (终止等待1)==状态。
- 此时,从客户机到服务器这个方向的连接就释放了,TCP连接处于半关闭状态。但**服务器若发送数据,客户机仍要接收**,即从服务器到客户机这个方向的连接==并未关闭==。 #注意 
##### 第三次挥手
- 若**服务器**已经**没有要向客户机发送的数据**,就通知TCP释放连接,此时,其发出==FIN=1==的连接释放报文段。
- 设该报文段的序号seq=w
	- (在半关闭状态服务器可能又发送了一些数据)
	- 还须**重复**上次已发送的确认号ack=u+1
		- 因为并没有收到对方的新报文,期望收到的报文没变
- 这时服务器进入**LAST-ACK(最后确认)** 状态。
	- 收到客户端发来的确认报文后才进入closed状态
		- 如果收不到对FIN-ACK的确认报文。服务器会**超时重传**这个FIN-ACK
##### 第四次挥手
- **客户机**收到连接释放报文段后,必须发出**确认**。
	- 把确认报文段中的确认位==ACK置1==,确认号ack=w+1,序号seq=u+1。
- 此时TCP连接==还未释放==,进入==TIME-WAIT==状态 #z408 
	- 必须经过时间等待计时器设置的时间==2MSL(最长报文段寿命)== 后,客户机才进入**CLOSED (连接关闭)** 状态。 #注意 
		- 为了保证**客户端发送的最后一个ACK报文段能够到达服务器**。
			- 因为这个ACK有可能丢失，从而导致处在LAST-ACK状态的服务器收不到对FIN-ACK的确认报文。
			- 服务器会**超时重传这个FIN-ACK**，接着客户端再重传一次确认，重新启动时间等待计时器。
		- **MSL要大于TTL**