##### 什么是无连接服务
- 两个实体之间的通信==不需要预先建立连接==,需要通信时直接发送信息,尽力而为的服务
##### UDP的无连接服务
- UDP是一个无连接的非可靠传输服务
	- **不需要**使用套接字
	- [[UDP数据报]]
	- 可靠性工作由==应用层==承担
- 在IP之上提供的附加功能
	- **多路复用**
	- **对数据的差错检查**
		- 出错后丢弃该报文，并由ICMP发送“端口不可达”差错报文给发送方
		- [[UDP校验]]
- 特点
	- 远程主机的传输层收到UDP报文后,==不需要给出任何确认==
	- 无需重传和处理确认
	- 执行快,实时性好
- 适用场合
	- 小文件传输协议TFTP
	- DNS
	- SNMP
	- 实时传输协议