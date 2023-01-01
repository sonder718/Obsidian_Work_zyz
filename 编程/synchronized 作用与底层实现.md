#### synchronized的作用
- 当一个方法或代码块被 `synchronized` 修饰时，它会被加上互斥锁。
- 这意味着，当一个线程执行这个方法或代码块时，**其他线程就无法再执行**这个方法或代码块，直到这个线程执行完毕。
#### 使用方式
- 在多线程环境下，每次只有一个线程能够执行 `increment()` 方法，从而避免了多线程环境下计数器的不正确计数。
```java
class Counter {
  private int count = 0;

  public synchronized void increment() {
    count++;
  }
}
```

- 可以使用 `synchronized` 关键字修饰代码块
	- 这段代码会将当前对象加上互斥锁，从而保证代码块在多线程环境下只能被一个线程执行。
```java
synchronized (this) {
  // 代码块
}
```

#### 底层实现
- [管程-信号量机制难以编写程序的解决措施](../考研/408/操作系统/管程-信号量机制难以编写程序的解决措施.md)
- [关于 Synchronized 的一个点，网上99%的文章都错了 - 文章详情 (itpub.net)](https://z.itpub.net/article/detail/181E1881F3F80BB817BC15BA6C2C8C93#:~:text=synchronized%20%E5%BA%95%E5%B1%82%E6%98%AF%E5%88%A9%E7%94%A8%20monitor%20%E5%AF%B9%E8%B1%A1%EF%BC%8CCAS%20%E5%92%8C,mutex%20%E4%BA%92%E6%96%A5%E9%94%81%E6%9D%A5%E5%AE%9E%E7%8E%B0%E7%9A%84%EF%BC%8C%E5%86%85%E9%83%A8%E4%BC%9A%E6%9C%89%E7%AD%89%E5%BE%85%E9%98%9F%E5%88%97%20%28cxq%20%E5%92%8C%20EntryList%29%E5%92%8C%E6%9D%A1%E4%BB%B6%E7%AD%89%E5%BE%85%E9%98%9F%E5%88%97%20%28waitSet%29%E6%9D%A5%E5%AD%98%E6%94%BE%E7%9B%B8%E5%BA%94%E9%98%BB%E5%A1%9E%E7%9A%84%E7%BA%BF%E7%A8%8B%E3%80%82)
- synchronized  修饰方法和代码块的时候字节码层面有什么区别?
- 