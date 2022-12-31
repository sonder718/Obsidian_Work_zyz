- ![](attachments/DMA%E6%8E%A7%E5%88%B6%E5%99%A8%E7%9A%84%E7%BB%84%E6%88%90%202022-11-22%2022.02.19.excalidraw.svg)%%[🖋 Edit in Excalidraw](attachments/DMA%E6%8E%A7%E5%88%B6%E5%99%A8%E7%9A%84%E7%BB%84%E6%88%90%202022-11-22%2022.02.19.excalidraw.md), and the [dark exported image](attachments/DMA%E6%8E%A7%E5%88%B6%E5%99%A8%E7%9A%84%E7%BB%84%E6%88%90%202022-11-22%2022.02.19.excalidraw.dark.svg)%%
- ![](attachments/DMA%E6%8E%A7%E5%88%B6%E5%99%A8%E7%9A%84%E7%BB%84%E6%88%90%202022-11-23%2016.25.22.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/DMA%E6%8E%A7%E5%88%B6%E5%99%A8%E7%9A%84%E7%BB%84%E6%88%90%202022-11-23%2016.25.22.excalidraw.md), and the [dark exported image](attachments/DMA%E6%8E%A7%E5%88%B6%E5%99%A8%E7%9A%84%E7%BB%84%E6%88%90%202022-11-23%2016.25.22.excalidraw.dark.svg)%%
- **“控制/状态”逻辑**
	- 由控制和时序电路及状态标志组成,用于指定传送方向,修改传送参数,并对DMA请求信号、CPU响应信号进行协调和同步。
- **中断机构**
	- 当一个数据块传送完毕后触发中断机构,向CPU提出中断请求。
- **DMA请求触发器**
	- 每当I/O设备准备好数据后,给出一个控制信号,使DMA请求触发器置位。
- **四类寄存器**
	- **主存地址计数器**/内存地址寄存器**MAR**
		- 输入时,存放数据传送到内存的起始目标==地址==
		- 输出时,存放内存到设备的内存源地址
	- **传送长度计数器**/数据计数器 DC
		- 存放本次传送==数据的长度==(字数/字节数),计数溢出时,数据即传送完毕,自动发中断请求信号。
	- **数据缓冲寄存器**/数据寄存器DR
		- ==暂存==每次传送的==数据==。
	- **命令状态寄存器CR**
		- 接收从CPU传来的IO命令,有关控制信息和设备状态
	
