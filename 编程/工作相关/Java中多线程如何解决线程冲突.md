# 使用同步代码块
```java
synchronized (锁对象){  
可能出现线程安全问题的代码（访问了共享数据的代码）  
}
```
![600](attachments/Pasted%20image%2020230221012738.png)
# 使用同步方法
- 同步方法也会把方法内部的代码锁住只会让一个线程执行  
- 同步方法的锁对象 new synchronized 也就是this
```java
修饰符 synchronized 返回值类型 方法名(参数列表){  
可能出现线程安全问题的代码（访问了共享数据的代码）  
}

```
![600](attachments/Pasted%20image%2020230221012705.png)
# 使用Lock锁
1.在成员位置创建一个ReentrantLock对象  
2.在可能会出现安全问题的代码前调用Lock接口中的方法获取锁  
3.在可能会出现安全问题的代码后调用Lock接口中的方法释放锁
```java
import java.util.concurrent.locks.Lock; 
import java.util.concurrent.locks.ReentrantLock;
```
![600](attachments/Pasted%20image%2020230221012640.png)