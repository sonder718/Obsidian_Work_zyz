# Arrays.sort与Collections.sort的区别
- Arrays.sort() 采用了2种排序算法
	- 基本类型数据使用==快速排序法==
		- String[] fruits = {"Orange", "Grape", "Apple", "Lemon", "Banana"};
	- 对象数组使用==归并排序==
		-   Employee[] newEmployees = new Employee[4];
	- 用于==数组==,是Arrays类的静态方法
- Collections.sort
	- 用于==List==
		- `ArrayList<String> al = new ArrayList<String>();`
# 源码分析
## Arrays.sort
![](attachments/Pasted%20image%2020230206220943.png)
## Collections.sort
![](attachments/Pasted%20image%2020230206221002.png)