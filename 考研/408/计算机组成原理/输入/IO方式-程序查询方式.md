##### 什么是程序查询方式
- 程序查询方式是一种**程序直接控制方式**,这是主机与外设间进行信息交换的**最简单的方式**
- 输入和输出完全是通过==CPU==执行程序来完成的。
	- CPU和 IO==串行==工作
- 计算机从外部设备读取的每个字, **CPU需要对外设状态进行循环检查,直到确定该字已经在I/O控制器的数据寄存器中**。
- #z408 必须在传输完端口大小的数据之前**访问端口**,即查询的间隔时间==小于==设备准备时间
- 在该方式中, CPU之所以要不断地测试1/O设备的状态,就是因为在CPU中未采用中断机构,使**I/O设备无法向CPU报告它已完成了一个字符的输入操作**。 #注意
- ![](attachments/IO%E6%96%B9%E5%BC%8F-%E7%A8%8B%E5%BA%8F%E6%9F%A5%E8%AF%A2%E6%96%B9%E5%BC%8F%202022-11-24%2014.46.24.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/IO%E6%96%B9%E5%BC%8F-%E7%A8%8B%E5%BA%8F%E6%9F%A5%E8%AF%A2%E6%96%B9%E5%BC%8F%202022-11-24%2014.46.24.excalidraw.md), and the [dark exported image](attachments/IO%E6%96%B9%E5%BC%8F-%E7%A8%8B%E5%BA%8F%E6%9F%A5%E8%AF%A2%E6%96%B9%E5%BC%8F%202022-11-24%2014.46.24.excalidraw.dark.svg)%%
##### 程序查询方式的流程
![](attachments/Pasted%20image%2020221121202412.png)