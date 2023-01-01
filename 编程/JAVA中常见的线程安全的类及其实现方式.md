##### 什么是线程安全
- 就是当多线程访问时，采用了**加锁**的机制；
- 即当一个线程访问该类的某个数据时，会对这个数据进行保护，其他线程不能对其访问，**直到该线程读取完之后，其他线程才可以使用**。防止出现数据不一致或者数据被污染的情况。
##### java中线程安全的实现方式
- 1.  通过`synchronized` 关键字给方法加上内置锁来实现[线程安全](https://so.csdn.net/so/search?q=%E7%BA%BF%E7%A8%8B%E5%AE%89%E5%85%A8&spm=1001.2101.3001.7020)   
    **`Timer`，`TimerTask`，`Vector`，`Stack`，`HashTable`，`StringBuffer`**
	- [[synchronized 底层实现]]