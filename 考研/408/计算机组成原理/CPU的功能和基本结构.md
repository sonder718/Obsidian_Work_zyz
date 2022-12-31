
##### 一些注意点
- **CPU的位数**
	- CPU能一次处理的数据的位数
	- 和数据总线的位数相同
- **指令译码**
- [CPU内部寄存器的类别-用户可见用户不可见](考研/408/计算机组成原理/CPU内部寄存器的类别-用户可见用户不可见.md)
- [CPU的功能](考研/408/计算机组成原理/CPU的功能.md)
- [[单周期CPU与多周期CPU]]

##### CPU的基本结构
[运算器](考研/408/计算机组成原理/运算器.md)+[控制器](考研/408/计算机组成原理/控制器.md)
![](attachments/CPU%E7%9A%84%E5%8A%9F%E8%83%BD%E5%92%8C%E5%9F%BA%E6%9C%AC%E7%BB%93%E6%9E%84%202022-10-26%2020.47.49.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/CPU%E7%9A%84%E5%8A%9F%E8%83%BD%E5%92%8C%E5%9F%BA%E6%9C%AC%E7%BB%93%E6%9E%84%202022-10-26%2020.47.49.excalidraw.md), and the [dark exported image](attachments/CPU%E7%9A%84%E5%8A%9F%E8%83%BD%E5%92%8C%E5%9F%BA%E6%9C%AC%E7%BB%93%E6%9E%84%202022-10-26%2020.47.49.excalidraw.dark.svg)%%

##### 计算机的工作过程
- #注意 MDR中会有指令或数据
- **间址周期**:取操作数的有效地址
	- #疑问 间址周期结束后MDR中是操作数地址
![](attachments/CPU%E7%9A%84%E5%8A%9F%E8%83%BD%E5%92%8C%E5%9F%BA%E6%9C%AC%E7%BB%93%E6%9E%84%202022-09-16%2020.32.38.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/CPU%E7%9A%84%E5%8A%9F%E8%83%BD%E5%92%8C%E5%9F%BA%E6%9C%AC%E7%BB%93%E6%9E%84%202022-09-16%2020.32.38.excalidraw.md)%%