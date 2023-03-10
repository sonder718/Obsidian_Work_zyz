
##### 什么是程序中断
- 程序中断是指在计算机执行实现程序的过程中，出现某些急需处理的异常情况或特殊请求，CPU暂时中止现行程序，而转去这些异常情况或特殊请求进行处理，在处理完毕后CPU又自动返回到现行程序的断点处，继续执行原程序。
- ![](attachments/Pasted%20image%2020221121203458.png)
##### 程序中断的功能
- （1）CPU与I/O设备==并行工作==   #注意
	- 允许I/O设备**主动打断**CPU的运行并请求服务,从而“解放”CPU,使得其向I/O控制器发**送读命令后可以继续做其他有用的工作**。
		- #注意 数据必须经过CPU中的寄存器
	- ![](attachments/IO%E6%96%B9%E5%BC%8F-%E7%A8%8B%E5%BA%8F%E4%B8%AD%E6%96%AD%E6%96%B9%E5%BC%8F%202022-11-24%2014.50.15.excalidraw.svg)%%[🖋 Edit in Excalidraw](attachments/IO%E6%96%B9%E5%BC%8F-%E7%A8%8B%E5%BA%8F%E4%B8%AD%E6%96%AD%E6%96%B9%E5%BC%8F%202022-11-24%2014.50.15.excalidraw.md), and the [dark exported image](attachments/IO%E6%96%B9%E5%BC%8F-%E7%A8%8B%E5%BA%8F%E4%B8%AD%E6%96%AD%E6%96%B9%E5%BC%8F%202022-11-24%2014.50.15.excalidraw.dark.svg)%%
- （2）硬件故障处理  
- （3）实现人机联系：在计算机工作过程中，如果用户要干预机器，如查看计算的中间结果，了解机器的工作状态，给机器下达临时性的命令等。在没有中断系统的计算机里这些功能几乎是无法实现的。  
- （4）实现多道程序和分时操作  
- （5）实现实时处理  
- （6）实现应用程序和操作系统的联系  
- （7）多处理机系统各处理机间的联系
##### 程序中断的工作流程
- CPU在程序中安排好**在某个时机启动某台外设**,然后CPU==继续执行当前的程序==,不需要像查询方式那样一直等待外设准备就绪。
	- 🐱打印机打印每个字需要2.5毫秒,每个字符的中断处理时间为50微秒,则其余47.5毫秒CPU可以做其他事情
- 一旦外设==完成数据传送的准备工作==,就主动向CPU**发出中断请求**,请求CPU为自己服务。
- 在可以响应中断的条件下, CPU暂时中止正在执行的程序,转去**执行中断服务程序**为外设服务,在==中断服务程序==中完成一次**主机与外设之间的数据传送**,传送完成后,CPU返回原来的程序,如图7.3所示。
- [程序中断的总体流程](程序中断的总体流程.md)
- ![](attachments/IO%E6%96%B9%E5%BC%8F-%E7%A8%8B%E5%BA%8F%E4%B8%AD%E6%96%AD%E6%96%B9%E5%BC%8F%202022-11-21%2020.38.41.excalidraw.svg)
- #z408 中断响应和中断服务的时间应小于设置准备数据的时间
%%[🖋 Edit in Excalidraw](attachments/IO%E6%96%B9%E5%BC%8F-%E7%A8%8B%E5%BA%8F%E4%B8%AD%E6%96%AD%E6%96%B9%E5%BC%8F%202022-11-21%2020.38.41.excalidraw.md), and the [dark exported image](attachments/IO%E6%96%B9%E5%BC%8F-%E7%A8%8B%E5%BA%8F%E4%B8%AD%E6%96%AD%E6%96%B9%E5%BC%8F%202022-11-21%2020.38.41.excalidraw.dark.svg)%%
