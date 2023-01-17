#### 总体框架图
- java 集合框架位于 java.util 包
![](attachments/Java%E9%9B%86%E5%90%88%E6%A1%86%E6%9E%B6%202023-01-17%2017.13.43.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/Java%E9%9B%86%E5%90%88%E6%A1%86%E6%9E%B6%202023-01-17%2017.13.43.excalidraw.md), and the [dark exported image](attachments/Java%E9%9B%86%E5%90%88%E6%A1%86%E6%9E%B6%202023-01-17%2017.13.43.excalidraw.dark.svg)%%
#### Collection集合
##### List 接口
- **特点**
	- Collection接口下的子接口
	- 元素按进入先后有序保存，可重复
- **实现类**
	- LinkedList
		- 链表， 插入删除， 没有同步， 线程不安全
	- ArrayList
		-  数组， 随机访问， 没有同步， 线程不安全
	- Vector
		- 数组， 同步， 线程安全
		- Stack
			- Vector的一个子类
			- 实现了一个标准的后进先出的栈
##### Set 接口
- **特点**
	- 仅接收一次，不可重复，并做内部排序
- **实现类**
	- HashSet
		- 使用hash表（数组）存储元素
			- 用于需要一个访问快速的Set
		- LinkedHashSet 
			- HashSet的子类
			- 链表维护元素的插入次序
				- 用于需要记录下插入时的顺序
			- [146-LRU缓存](../Leetcode/146-LRU缓存.md)
	- TreeSet 
		- 底层实现为二叉树
			- 用于需要一个排序的Set

#### Map集合
- **特点**
	- 由一系列键值对组成的集合，提供了key到Value的映射
	- 保证了key与value之间的一一对应关系
- **实现类**
- Hashtable
	- 继承于Dictionary类
	- 同步， 线程安全
		- 大部分类都被synchronized关键字修饰
- HashMap 
	- 没有同步， 线程不安全
	- LinkedHashMap
		- HashMap的子类
		- 双向链表和哈希表实现
		- 解决了 HashMap不能随时保持遍历顺序和插入顺序一致的问题
- WeakHashMap
- TreeMap
	- 承自AbstractMap抽象类，并实现了SortedMap接口
	- 红黑树对所有的key进行排序
- IdentifyHashMap
#### 参考文献
- [Java集合框架大汇总 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/39179165)

