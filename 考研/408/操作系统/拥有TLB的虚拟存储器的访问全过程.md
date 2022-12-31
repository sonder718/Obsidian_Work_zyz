
#注意 
设某系统满足以下条件:
- 有一个TLB 与一个 data Cache
- 存储器以字节为编址单位
- 虚拟地址14位.物理地址12位
- 页面大小为64B
- TLB为四路组相联,共有16个条目
- data Cache是物理寻址、直接映射的,行大小为4B,共有16组

**写出访问地址为0x03d4, 0x00fl和0x0229的过程。.**

- **分析地址结构**
	- ![](attachments/Pasted%20image%2020220927233908.png)
- **TLB,页表,cache内容分析**
	- ![](attachments/Pasted%20image%2020220927233921.png)
	- ![](attachments/Pasted%20image%2020220927233948.png)
- **虚拟地址结构**
	- ![](attachments/Pasted%20image%2020220927234021.png)
- **计算物理地址**
	- ![](attachments/Pasted%20image%2020220927234050.png)
- ![](attachments/Pasted%20image%2020220927234209.png)
- ![](attachments/Pasted%20image%2020220927234217.png)