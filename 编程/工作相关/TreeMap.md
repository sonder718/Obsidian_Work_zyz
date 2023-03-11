# 为什么需要
- `HashMap`是一种以空间换时间的映射表，它的实现原理决定了内部的Key是无序的，即遍历`HashMap`的Key时，其顺序是不可预测
- `SortedMap`是接口，它的实现类是`TreeMap`,**在内部会对Key进行排序**![200](attachments/Pasted%20image%2020230220205109.png)
# 使用方式
- 放入的Key必须实现`Comparable`接口
	- `String`、`Integer`这些类已经实现了`Comparable`接口，因此可以直接作为Key使用。作为Value的对象则没有任何要求
		- `TreeMap`在比较两个Key是否相等时，依赖Key的`compareTo()`方法或者`Comparator.compare()`方法。**在两个Key相等时，必须返回`0`**
		- ![](attachments/Pasted%20image%2020230220205054.png)