# Broadcast Receiver实现进程通信
- 在**接收广播**的应用程序中
	- 创建一个**BroadcastReceiver子类**，并实现onReceive()方法，该方法会在接收到广播时执行
		- ![500](attachments/Pasted%20image%2020230228165711.png)
		- ![500](attachments/Pasted%20image%2020230228165755.png)
	- 使用registerReceiver()方法注册**BroadcastReceiver**
		- ![400](attachments/Pasted%20image%2020230228165815.png)
- 在**发送广播**的应用程序中
	- 使用**Intent**将数据传递给接收应用程序
	- ![500](attachments/Pasted%20image%2020230228165655.png)