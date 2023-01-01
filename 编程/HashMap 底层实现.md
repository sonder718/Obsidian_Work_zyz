#### HashMap和Hashtable的区别
- HashMap和Hashtable都实现了**Map接口**。主要的区别有
- 对Null key 和Null value的支持
	- HashMap可以接受为null的键值(key)和值(value)
	- Hashtable不能接受null值，会产生空指针异常。
- 线程是否安全
	-  HashMap是非synchronized，而Hashtable是synchronized
	- 这意味着Hashtable是线程安全的，多个线程可以共享一个Hashtable；
	- 而如果没有正确的同步的话，多个线程是不能共享HashMap的
效率： 由于Hashtable是线程安全的，所以在单线程环境下比HashMap要慢。如果你不需要同步，只需要单一线程，那么使用HashMap性能要好过Hashtable。
初始容量大小和每次扩充容量大小的不同：HashMap初始大小为16，扩容为2的幂次方；HashTable初始为11，扩容为2n+1
底层结构：HashMap会将链表长度大于阈值是转化为红黑树（会先判断当前数组的长度是否小于 64，是则扩容，而不转化），将链表转化为红黑树，以减少搜索时间。Hashtable 没有这样的机制。
