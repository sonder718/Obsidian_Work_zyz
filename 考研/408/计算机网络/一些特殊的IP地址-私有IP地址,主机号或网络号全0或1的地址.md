## 私有IP地址网段  
- #注意 注意网络号的位置与位数
- A类:10.
- ![](attachments/Pasted%20image%2020221013225158.png)
- #疑问 采用了CIDR技术后呢
	- 只用于LAN,无影响
##### 主机号/网络号全0/1
![](attachments/Pasted%20image%2020221014020914.png)
- **主机号全为0**
	- 表示**本网络**本身,如202.98.174.0。
- **主机号全为1**
	- 表示**本网络的广播地址**,又称直接广播地址,如202.98.174.255。
	- 只能作为目的IP地址,==不能作为源IP地址== #注意
- **网络号字段为全0**的IP地址是一个保留地址，表示**本网络**的意思
	- 0.
	- 128.0
	- 192.0.0
	- 只能作为源IP地址,==不能作为目的IP地址== #注意
- **网络号字段为全1**的IP地址,保留为**环回自检**(Loopback Test)地址 #z408 
	- **127.x.x.x**是
		- **191.255.x.x**,**223.255.255.x** 不是
	- 此地址表示**任意主机本身**
	- 目的地址为环回地址的IP数据报**永远不会出现在任何网络上。** #注意
- **32位全为0**,即0.0.0.0表示**本网络上的本主机**。
- **32位全为1**,即255.255.255.255表示**整个TCP/IP网络的广播地址**,又称受限广播地址。
	- 实际使用时,由于路由器对广播域的隔离,==255.255.255.255==**等效为本网络的广播地址**。 #注意 
- 注意地址的正确性
