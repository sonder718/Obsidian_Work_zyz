- Router ID是一个32位的值，它**唯一标识了一个自治系统内的路由器**，可以为每台运行OSPF的路由器上可以**手动配置**一个Router ID，或者指定一个IP地址作为Router ID。
	- 1、如果设备存在多个逻辑接口地址，则路由器使用**逻辑接口中最大的IP地址**作为Router ID；
	- 2、如果没有配置逻辑接口，则路由器使用**物理接口的最大IP地址**作为Router ID。
- **直连网络**
	- **直连网络**是指不用经过其他路由器就可以直接到达的**网**
		- [子网划分](../计算机网络/子网划分.md)
	- 在路由器上配置静态或动态路由之前，路由器只知道与自己直连的网络。这些网络是在配置静态或动态路由之前唯一显示在路由表中的网络。
	- 直连网络对于路由决定起着重要作用。如果路由器没有直连网络，也就不会有静态和动态路由的存在。如果**路由器接口未启用 IP 地址和子网掩码，路由器就不能从该接口将数据包发送出去**，正如在以太网接口未配置 IP 地址和子网掩码的情况下，PC 也不能将 IP 数据包从该接口发送出去。
- ![](attachments/%E9%82%BB%E6%8E%A5%E5%A4%9A%E9%87%8D%E8%A1%A8%E5%AD%98%E5%82%A8%E5%9B%BE%E7%9A%84%E5%AE%9E%E4%BE%8B--%E4%BF%9D%E5%AD%98OSPF%E5%8D%8F%E8%AE%AE%E7%9A%84%E8%B7%AF%E7%94%B1%E8%A1%A8%202022-10-25%2017.21.48.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E9%82%BB%E6%8E%A5%E5%A4%9A%E9%87%8D%E8%A1%A8%E5%AD%98%E5%82%A8%E5%9B%BE%E7%9A%84%E5%AE%9E%E4%BE%8B--%E4%BF%9D%E5%AD%98OSPF%E5%8D%8F%E8%AE%AE%E7%9A%84%E8%B7%AF%E7%94%B1%E8%A1%A8%202022-10-25%2017.21.48.excalidraw.md), and the [dark exported image](attachments/%E9%82%BB%E6%8E%A5%E5%A4%9A%E9%87%8D%E8%A1%A8%E5%AD%98%E5%82%A8%E5%9B%BE%E7%9A%84%E5%AE%9E%E4%BE%8B--%E4%BF%9D%E5%AD%98OSPF%E5%8D%8F%E8%AE%AE%E7%9A%84%E8%B7%AF%E7%94%B1%E8%A1%A8%202022-10-25%2017.21.48.excalidraw.dark.svg)%%-