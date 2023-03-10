# Tips
![](attachments/IPv6%E7%9A%84%E7%89%B9%E7%82%B9%202022-10-14%2016.18.32.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/IPv6%E7%9A%84%E7%89%B9%E7%82%B9%202022-10-14%2016.18.32.excalidraw.md)%%
# 主要特点
- 1)更大的地址空间。IPv6 将地址从 IPv4 的 32 位增大到了 ==128== 位。IPv6 的字节数(==16B==)是Pv4 字节数(4B)的平方。 #注意
- 2) 扩展的地址层次结构。
- 3) 灵活的首部格式。==首部长度固定==
	- 简化了 IP 分组头,它包含8个域(IPv4 是 12 个域)。这一改变使得路由器能够更快地处理分组,从而可以改善吞吐率。
	- #注意 取消了==校验和字段==,
- 4)改进的选项。
	- 更好地支持选项。这一改变对新的分组首部很重要,因为一些从前必要的段现在变成了
- 5)允许协议继续扩充。
- 6) 支持即插即用(即自动配置)。
- 7)支持资源的预分配。
- 8) IPv6 ==只有在包的源结点才能分片==,是端到端的,传输路径中的路由器不能分片,所以从一般意义上说,IPv6 不允许分片(不允许类似 IPv4 的路由分片)。 
- 9)IPv6 首部长度必须是 ==8B== 的整数倍,而 IPv4 首部是 4B 的整数倍。
- 10)增大了安全性。身份验证和保密功能是 IPv6 的关键特征。
	- 支持**Qos**
		- QoS（Quality of Service，服务质量）指一个网络能够利用各种基础技术，为指定的网络通信提供更好的服务能力，是网络的一种安全机制， 是用来解决网络延迟和阻塞等问题的一种技术。
# 三种基本类型地址
- IPv6 数据报的目的地址可以是以下三种基本类型地址之一:
	- 1)**单播**。单播就是传统的点对点通信。
	- 2)**多播**。多播是一点对多点的通信,分组被交付到一组计算机的每台计算机。
	- 3)**任播**。这是 IPv6 增加的一种类型。任播的目的站是一组计算机,但数据报在交付时只交付其中的一台计算机,通常是距离最近的一台计算机。
-  在 IPv6 标准中指定了一种比较紧凑的表示法,即把地址中的每4位用一个十六进制数表示,并用冒号分隔每 16 位,如4BF5:AA12:0216:FEBC:BA5F:039A:BE9A:2170。
	- 通常可以把IPv6地址缩写成更紧凑的形式。当16位域的开头有一些0时,可以采用一种缩写表示法,但在域中**必须至少有一个数字。**
		- 例如,可以把地址4BF5:0000:0000:0000:BA 5F:039A:000A:2176缩写为4BF5:0:0:0:BA5F:39A:A:2176。
	- 当有相继的0值域时,还可以进一步缩写。这些域可以用双冒号缩写(::)。
		- 当然,双冒号表示法在一个地址中仅能出现一次,因为0值域的个数没有编码,需要从指定的总的域的个数来推算。这样一来,前述地址可被更紧凑地书写成4BF5::BA5F:39A:A:2176。
- IPv6 扩展了 IPv4 地址的分级概念,它使用以下3个等级:
	- 第一级(顶级)指明全球都知道的公共拓扑;
	- 第二级(场点级)指明单个场点;
	- 第三级指明单个网络接口。
	- IPv6 地址采用多级体系主要是为了使路由器能够更快地查找路由。