# 进入加锁代码块的流程
- 1、在进入加锁代码块时增加一个**monitor enter指令**，然后针对**锁对象**关联的**monitor**累加**加锁计数器count**，同时标志这个线程加了锁。
	- synchronized是可重入锁，就是可以多次加锁，每加一次，monitor里加锁计数器都加1。
- 2、在离开加锁代码块是增加一个**monitor exit指令**，然后递减monitor里的**加锁计数器**，如果加锁计数器递减为0，就标志当前线程不持有锁，也就是释放了锁。
- 3、然后wait和notify关键字的实现也是依托于monitor实现的，有线程执行wait之后，自己会加入一个waitset中等待唤醒获取锁，notifyall操作会从monitor的waitset中唤醒所有的线程，让他们竞争获取锁。
# 底层实现
- [[JVM中的对象存在形式]]
- 每一个锁都对应一个**monitor对象**
	- 