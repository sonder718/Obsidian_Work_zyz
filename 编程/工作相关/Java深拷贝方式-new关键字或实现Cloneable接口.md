- Cloneable是一个空接口， 也叫做**标记接口**，如果一个类实现了这个接口，那么就标记这个类，意味着它可以进行克隆
- Object默认的clone方法实际是对域的简单拷贝，**对于简单数据类型，是值的拷贝**；对于复杂类型的字段，则是**指针地址的拷贝**，clone后的对象和原对象指向的还是一个地址空间。
	- 即默认的clone方法是**浅克隆**
# 方式
- 对每一个**复杂类型对象**实现cloneable接口
	- **重写Object的clone方法**
	- ![400](attachments/Pasted%20image%2020230225234750.png)
	- ![](attachments/Pasted%20image%2020230225234820.png)