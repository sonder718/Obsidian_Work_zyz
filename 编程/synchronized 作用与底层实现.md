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
- synchronized  修饰方法和代码块的时候字节码层面有什么区别