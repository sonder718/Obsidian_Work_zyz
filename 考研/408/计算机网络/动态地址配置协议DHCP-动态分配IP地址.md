[静态IP](考研/408/计算机网络/静态IP.md)

# 什么是DHCP
- **动态主机配置协议**(Dynamic Host Configuration Protocol, DHCP)常用于给主机**动态地分配IP地址**,它提供了即插即用的联网机制,这种机制允许一台计算机加入新的网络和获取IP地址而不用手工参与。
- DHCP是==局域网==的网络协议
- DHCP是==应用层==协议,它是基于==UDP==的。 #注意  #z408 
	- TCP需要建立连接,如果连对方的IP地址都不知道,那么更不可能通过双方的套接字建立连接。
	- DHCP是应用层协议,因为它是通过==客户/服务器==模式工作的,DHCP客户端向DHCP服务器请求服务,而**其他层次的协议是没有这两种工作方式的**。 #注意
- **DHCP服务器**
	- DHCP用一台或一组DHCP服务器来管理网络参数的分配，这种方案具有容错性。即使在一个仅拥有少量机器的网络中，DHCP仍然是有用的，因为一台机器可以几乎不造成任何影响地被增加到本地网络中。
	- 安装 DHCP 服务并启动后，必须创建一个**作用域**。 作用域是**一系列有效的 IP 地址**，可用于租用到网络上的 DHCP 客户端计算机。 
# DHCP的工作原理
- 使用**客户/服务器**模式。
- DHCP的客户端和服务器端需要通过==广播==方式来进行交互 #注意 #z408 
	- 原因是在DHCP执行初期,客户端不知道服务器端的IP地址,而在执行中间,**客户端并未被分配IP地址**,从而导致两者之间的通信必须采用广播的方式。
- 需要IP地址的主机在**启动时**就向DHCP服务器==广播发送==发现报文,这时该主机就成为DHCP客户。 #注意
	- 本地网络上所有主机都能收到此广播报文,但**只有DHCP服务器才回答此广播报文**。
- DHCP服务器先在其数据库中查找该计算机的配置信息。
	- 若找到,则返回找到的信息。 
	- 若找不到,则从==服务器的IP地址池==中取一个地址**分配**给该计算机。
		- DHCP服务器的回答报文称为**提供报文**。
		- DHCP 允许网络上配置多台DHCP服务器,当DHCP客户机发出“DHCP发现”消息时,有可能收到多个应答消息。这时,DHCP客户机只会挑选其中的一个,通常挑选最先到达的。
# DHCP的工作过程
- 1) DHCP客户机**广播**"**DHCP发现**”消息,试图找到网络中的DHCP服务器,以便从DHCP服务器获得一个IP地址。源地址为0.0.0.0,目的地址为255.255.255.255。
- 2) DHCP服务器收到“**DHCP发现**”消息后,**广播**"DHCP提供”消息,其中包括提供给DHCP客户机的IP地址。源地址为DHCP服务器地址,目的地址为255.255.255.255。
- 3) DHCP客户机收到“**DHCP提供**”消息,如果接受该IP地址,那么就**广播**“DHCP请求”消息向DHCP服务器请求提供IP地址。源地址为0.0.0.0,目的地址为255.255.255.255。
- 4) DHCP服务器**广播**"**DHCP确认**”消息,将IP地址分配给DHCP客户机。源地址为DHCP服务器地址,目的地址为255.255.255.255。

# 分配的IP地址能用多久?
- DHCP服务器分配给DHCP客户的IP地址是临时的,因此DHCP客户只能在一段有限的时间内使用这个分配到的IP地址。DHCP称这段时间为**租用期**。
- 租用期的数值应由DHCP服务器自己决定,DHCP客户也可在自己发送的报文中提出对租用期的要求。
