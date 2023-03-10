- CPU与DMA分时使用==内存== #注意
- **停止CPU访存**。
	- 当I/O设备有DMA请求时,由DMA控制器向CPU发送一个停止信号,使CPU脱离总线,停止访问主存,直到DMA传送一块数据结束。
	- 数据传送结束后,DMA控制器通知CPU可以使用主存,并把总线控制权交还给CPU。
- **周期挪用**(或周期窃取)。
	- [[采用DMA进行磁盘读写的流程]]
	- 当I/O设备有DMA请求时,会遇到3种情况:
		- ①是此时CPU不在访存(如CPU正在执行乘法指令),因此I/O的访存请求与CPU未发生冲突;
		- ②是CPU正在访存,此时必须待存取周期结束后,CPU再将总线占有权让出: 
		- ③是I/O和CPU同时请求访存,出现访存冲突,此时CPU要**暂时放弃总线占有权**。
	- #注意 ==I/O访存优先级高于CPU访存==
		- 因为I/O不立即访存就可能丢失数据,此时由I/O设备**挪用一个或几个存取周期**,传送完一个数据后==立即释放总线==,是一种==单字传送方式==。  #z408
			- 假设一个DMA数据块是512字节,响应的IO接口中有一个32位的**数据缓冲寄存器**,每准备好==32位==数据,就发动一次**总线请求** #z408
				- 因此整个数据块的传输过程中,CPU==可以==访问主存
- **DMA 与CPU交替访存**。
	- 这种方式适用于==CPU的工作周期比主存存取周期长==的情况。例如,若CPU的工作周期是1.2ps,主存的存取周期小于0.6us,则可将一个CPU周期分为C,和C2两个周期,其中C,专供DMA访存, C2专供CPU访存。这种方式不需要总线使用权的申请、建立和归还过程,总线使用权是通过C,和C2分时控制的