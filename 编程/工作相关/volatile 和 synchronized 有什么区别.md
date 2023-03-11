volatile 和 synchronized 的区别有以下几点：
-   volatile 不需要加锁，比 synchronized 更轻量级，不会阻塞线程；
-   volatile 只能保证可见性，无法保证原子性，而 synchronized 既能保证可见性，又能保证原子性；
-   volatile 不能修饰代码块和方法，**只能修饰变量**，而 synchronized 可以修饰**代码块和方法**；
	- [单例模式](单例模式.md)
-   volatile 解决的是变量在多个线程之间的可见性问题，而 synchronized 解决的是多个线程之间访问资源的同步问题。
	- [volatile用法和底层实现-防止指令重排,保证内存可见](volatile用法和底层实现-防止指令重排,保证内存可见.md)
	- [synchronized 作用与使用方法](synchronized%20作用与使用方法.md)