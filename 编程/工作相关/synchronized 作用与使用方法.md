#### synchronized的作用
- 当一个方法或代码块被 `synchronized` 修饰时，它会被加上互斥锁。
- 这意味着，当一个线程执行这个方法或代码块时，**其他线程就无法再执行**这个方法或代码块，直到这个线程执行完毕。
#### 特点
1.同步代码块中的锁对象，可以使用任意的对象  
2.必须保证**多个线程使用的锁对象是同一个**  
3.锁对象作用：把同步代码块锁住，**只让一个线程在同步代码块中执行**  
缺点：程序频繁的判断，获取，释放锁，代码的效率会降低
#### 使用方式
##### 修饰实例方法
- 在多线程环境下，每次只有一个线程能够执行 `increment()` 方法，从而避免了多线程环境下计数器的不正确计数。
```java
class Counter {
  private int count = 0;

  public synchronized void increment() {
    count++;
  }
}
```

##### 修饰静态方法
- 如果一个线程 A 调用一个实例对象的非静态 `synchronized` 方法，而线程 B 需要调用这个实例对象所属类的静态 `synchronized` 方法，是允许的，**不会发生互斥现象**
	- 因为访问静态 `synchronized` 方法占用的锁是当前类的锁
	- 而访问非静态 `synchronized` 方法占用的锁是当前实例对象锁
```java
synchronized void staic method() { //业务代码 }
```
##### 修饰代码块
- `synchronized(this|object)` 表示进入同步代码库前要获得**给定对象的锁**。
```java
synchronized (this) {
  // 代码块
}
```
- `synchronized(类.class)` 表示进入同步代码前要获得 **当前 class 的锁**

#### 底层实现
- [管程-信号量机制难以编写程序的解决措施](../../考研/408/操作系统/管程-信号量机制难以编写程序的解决措施.md)
- [关于 Synchronized 的一个点，网上99%的文章都错了 - 文章详情 (itpub.net)](https://z.itpub.net/article/detail/181E1881F3F80BB817BC15BA6C2C8C93#:~:text=synchronized%20%E5%BA%95%E5%B1%82%E6%98%AF%E5%88%A9%E7%94%A8%20monitor%20%E5%AF%B9%E8%B1%A1%EF%BC%8CCAS%20%E5%92%8C,mutex%20%E4%BA%92%E6%96%A5%E9%94%81%E6%9D%A5%E5%AE%9E%E7%8E%B0%E7%9A%84%EF%BC%8C%E5%86%85%E9%83%A8%E4%BC%9A%E6%9C%89%E7%AD%89%E5%BE%85%E9%98%9F%E5%88%97%20%28cxq%20%E5%92%8C%20EntryList%29%E5%92%8C%E6%9D%A1%E4%BB%B6%E7%AD%89%E5%BE%85%E9%98%9F%E5%88%97%20%28waitSet%29%E6%9D%A5%E5%AD%98%E6%94%BE%E7%9B%B8%E5%BA%94%E9%98%BB%E5%A1%9E%E7%9A%84%E7%BA%BF%E7%A8%8B%E3%80%82)
- synchronized  修饰方法和代码块的时候字节码层面有什么区别?
- [深入理解synchronized底层原理，一篇文章就够了！ - 腾讯云开发者社区-腾讯云 (tencent.com)](https://cloud.tencent.com/developer/article/1465413)