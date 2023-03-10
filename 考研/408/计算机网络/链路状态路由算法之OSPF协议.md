
## 什么是链路状态路由算法（LS算法）
- 链路状态算法以图论作为理论基础，用图来表示网络拓扑结构，并利用**图论中的最短路径算法**来计算网络间的最佳路由 #注意
- 因此链路状态算法又被称作**最短路径优先算法SPF**
- [链路状态路由算法（LS算法）的特点](链路状态路由算法（LS算法）的特点.md)
## 什么是OSPF协议
- **开放式最短路径优先OSPF**（Open Shortest Path First）是IETF组织开发的一个基于链路状态的内部网关协议（Interior Gateway Protocol）。  
## 为什么需要OSPF协议
- 在OSPF出现前，网络上广泛使用RIP（Routing Information Protocol）作为内部网关协议。
	- [OSPF与RIP的区别-发什么,发给谁](OSPF与RIP的区别-发什么,发给谁.md)
- OSPF采用**组播**形式收发报文，这样可以减少对其它不运行OSPF路由器的影响。
	- [OSPF的工作原理-生成并存储全网拓扑结构图-区域的划分](OSPF的工作原理-生成并存储全网拓扑结构图-区域的划分.md)
	- [OSPF的分组类型-问候,请求与更新链路状态](OSPF的分组类型-问候,请求与更新链路状态.md)
- OSPF支持无类型域间选路（CIDR）。
- OSPF支持对等价路由进行负载分担。
- OSPF支持报文加密。



