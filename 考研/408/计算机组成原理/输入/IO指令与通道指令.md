##### IO指令
- I/O指令是计算机指令系统的一部分，由CPU执行。
	- 但是格式与通用指令==不同==
- 在采用通道的计算机中，I/O指令不直接控制I/O数据的传送，它只负责**启动、停止I/O**的过程、**查询**通道和I/O设备的**状态**以及控制通道进行某些操作。
- X86指令系统中的I/O指令是IN/OUT两种指令。
	- IN指令的功能是从==I/O端口==输入（读）数据到微处理器的==累加器==中 #注意 #z408 
		- 微处理器即CPU
	- OUT指令的功能是将微处理器的==累加器==中的数据输出（写）到==I/O端口==中。
- 程序员进行系统调用访问设备用的==逻辑地址== #注意
##### 通道指令
- [关于通道技术](../关于通道技术.md)
- [[字符编码]]
- 通道指令是通道本身的指令,用来**执行**I/O操作,如读、写、磁带走带和磁盘找道等操作。