# Java为什么需要lambda表达式？
- 能够提升代码简洁性、提高代码可读性。
- Lambda表达式的本质：作为函数式接口的实例.因此可以用于**取代（某些）匿名内部类**,同时也常用于Stream特性.
	- 如果一个接口中，只声明了**一个抽象方法**，则此接口就称为**函数式接口**
	- [[Java的Stream特性]]
	- ![](attachments/Pasted%20image%2020230206224826.png)
	- ![](attachments/Pasted%20image%2020230206223733.png)
# 底层实现
- 