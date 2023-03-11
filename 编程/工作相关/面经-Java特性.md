[单例 - 廖雪峰的官方网站 (liaoxuefeng.com)](https://www.liaoxuefeng.com/wiki/1252599548343744/1281319214514210)
# 基础JAVA语法
## 异常处理
- [try-catch-finally finally一定会执行么？finally和return的执行顺序](try-catch-finally%20finally一定会执行么？finally和return的执行顺序.md)
- [包装类的自动装箱和拆箱](包装类的自动装箱和拆箱.md)
## 语法糖
- [[lambda表达式的用途]]
	- [Java的Stream特性](Java的Stream特性.md)
- [java8（JDK1.8）新特性](java8（JDK1.8）新特性.md)
## 类
- [[Java 反射-反射获取类的3种方式]]
- [[Java中深拷贝与浅拷贝的区别和具体实现]]
	- [Java深拷贝方式-new关键字或实现Cloneable接口](Java深拷贝方式-new关键字或实现Cloneable接口.md)
	- [Java深拷贝方式-实现Serializable接口序列化实现深拷贝](Java深拷贝方式-实现Serializable接口序列化实现深拷贝.md)
- [序列化与反序列化的目的](序列化与反序列化的目的.md)
	- [常见的序列化技术-Json,Protobuf等](常见的序列化技术-Json,Protobuf等.md)
	- [[Gson实现Json序列化]]
- [[不变类和纪录类是什么]]
- [[Class实例比较和instanceof的差别]]
- [[java中重载和重写的区别]]
- [[java中的动态绑定和运行时的多态是指]]

## 基本数据类型
- [[Java int 和Integer的区别]]
	- 美团一面
- [谈谈Integer i = new Integer(xxx)和Integer i =xxx;这两种方式的区别](谈谈Integer%20i%20=%20new%20Integer(xxx)和Integer%20i%20=xxx;这两种方式的区别.md)
## 流处理
- [[Java中的四类IO流]]
	- [[JAVA读取二进制文件指定位置的数据-FileInputStream,RandomAccessFile]]
	-  [[Java读取.txt文件的指定行，并确定该行的字符数]]
## Java集合框架
- [Java集合框架的总体介绍](Java集合框架的总体介绍.md)
### Collection集合
- [[如何使用 Collections 容器]]
- [[Arrays.sort与Collections.sort]]
#### List 接口
- **特点**
	- Collection接口下的子接口
	- 元素按进入先后有序保存，可重复
- **实现类**
	- **LinkedList**
		- 链表， 插入删除， 没有同步， 线程不安全
		- [[ArrayList 与 LinkedList 比较]]
	- **ArrayList**
		-  数组， 随机访问， 没有同步， 线程不安全
	- **Vector**
		- 数组， 同步， 线程安全
		- Stack
			- Vector的一个子类
			- 实现了一个标准的后进先出的栈
#### Set 接口
- **特点**
	- 仅接收一次，不可重复，并做内部排序
- **实现类**
	- **[[HashSet]]**
		- [[HashSet 和 HashMap 的关系]]
		- 使用hash表（数组）存储元素
			- 用于需要一个访问快速的Set
		- LinkedHashSet 
			- HashSet的子类
			- 链表维护元素的插入次序
				- 用于需要记录下插入时的顺序
			- [146-LRU缓存](../Leetcode/146-LRU缓存.md)
	- **TreeSet** 
		- 底层实现为二叉树
			- 用于需要一个排序的Set
### Map集合
- **特点**
	- 由一系列键值对组成的集合，提供了key到Value的映射
	- 保证了key与value之间的一一对应关系
- **实现类**
	- **Hashtable**
		- [[Hashtable,HashMap 与 ConcurrentHashMap 区别与底层实现]]⭐
		- 继承于Dictionary类
		- 同步， 线程安全
			- 大部分类都被synchronized关键字修饰
	- **[[HashMap]]**
		- [[equals 和 hashCode 的关系]] ⭐
		- [[hashmap插入数据的流程与解决hash冲突的方式]]
		- [[HashMap 底层实现]] ⭐⭐⭐
		- [[HashMap 与 TreeMap]]
		- [处理散列函数冲突的方式](../../考研/408/数据结构/处理散列函数冲突的方式.md)
		- 没有同步， 线程不安全
			- [HashMap为什么线程不安全](HashMap为什么线程不安全.md)
		- LinkedHashMap
			- HashMap的子类
			- 双向链表和哈希表实现
			- 解决了 HashMap不能随时保持遍历顺序和插入顺序一致的问题
	- **WeakHashMap**
	- **[[TreeMap]]**
		- [[TreeMap的特性与用法]]
		- [[TreeMap实现有序的方法]]
		- 承自AbstractMap抽象类，并实现了SortedMap接口
		- 红黑树对所有的key进行排序
	- **IdentifyHashMap**
# 线程安全相关
## 线程底层
- [[Java 线程状态]]
	- [[线程之间共享什么资源]]
- [[java中的三种IO模型bio，nio，aio]]
## 创建线程
- **创建线程的四种方法**
	- [创建新线程-继承 Thread 类](创建新线程-继承%20Thread%20类.md)
	- [创建新线程-实现 Runnable 接口](创建新线程-实现%20Runnable%20接口.md)
	- [创建新线程-创建线程池,Runnable 对象提交到线程池](创建新线程-创建线程池,Runnable%20对象提交到线程池.md)
	-  [创建新线程-使用 Callable 和 Future](创建新线程-使用%20Callable%20和%20Future.md)
- [线程池的种类](线程池的种类.md)
- [[线程池执行过程]] ⭐
- [[线程池中的线程会在什么状态]]
- [[线程池队列比较与选择]]
- [[线程池七大参数]]
## 实现线程安全
- [[JAVA中常见的线程安全的类及其实现方式]] ⭐
- [[volatile用法和底层实现-防止指令重排,保证内存可见]] ⭐
- [[volatile 和 synchronized 有什么区别]]
- [[Java中多线程如何解决线程冲突]]
-  [[synchronized 作用与使用方法]]
- [[synchronized 底层是如何实现加锁操作的]]
- [[synchronized 和 lock 有什么区别]]

# 设计模式等的实现
## 常见设计模式
- 1、[[单例模式]]；
- 2、[[工厂模式]]；
- 3、[[建造(Builder)模式]]；
- 4、[[观察者模式]]；
- 5、[[适配器(Adapter)模式]]；
- 6、[代理模式](代理模式.md)；
- 7、[[装饰模式]]
# JVM
- [[是否看过 JDK API]]
- [[什么是JVM]]
- [JVM的组成](编程/工作相关/JVM的组成.md)
	- [[JVM内存结构]]⭐
	- [[JVM垃圾收集器]]⭐
	- [[JVM垃圾回收机制]] ⭐
		- [[垃圾收集为什么要暂停线程]]
		- [[Java 垃圾回收算法（可达性分析算法，标记清除、复制、标记整理）]]
	- [[JVM性能调优（JVM 参数）]]
	- [[ThreadLocal 内存泄漏]]
- [[Java 类加载机制]]
# 框架
- [[用过哪些Java框架]]
- [[是否了解Spring Boot]]
- [[Java 程序分析系统]] ⭐⭐⭐⭐
	- [[有哪些反序列化漏洞以及漏洞检测流程]] ⭐
