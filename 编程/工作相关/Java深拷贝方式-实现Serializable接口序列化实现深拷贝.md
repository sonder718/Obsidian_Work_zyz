- [序列化与反序列化的目的](序列化与反序列化的目的.md)
- [[常见的序列化技术-Json,Protobuf等]]

# 参考文献
- [面试官：Java序列化为什么要实现Serializable接口？我懵了 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/340258358)
- [java序列化，看这篇就够了 - 9龙 - 博客园 (cnblogs.com)](https://www.cnblogs.com/9dragon/p/10901448.html)
# Serializable接口
- Serializable接口是一个**标记接口**，**不用实现任何方法**。一旦实现了此接口，该类的对象就是可序列化的。
# 如果有一个成员变量不想被转换，应该用什么修饰
- ! **Transient关键字**
作用是控制变量的序列化，在变量声明前加上该关键字，可以阻止该变量被序列化到文件中，在被反序列化后，transient变量的值设为初始值，如int型的是0.

# 同一对象序列化多次，会将这个对象序列化多次吗？
- 答案是**否定**的。
- 所有保存到磁盘的对象都有一个**序列化编码号**
- 当程序试图序列化一个对象时，会先检查此对象**是否已经序列化过**，只有此对象从未（在此虚拟机）被序列化过，才会将此对象序列化为字节序列输出。
- 如果此对象已经序列化过，则直接输出编号即可。
# Java序列化步骤
- 实现Serializable接口,表明可以序列化
	- ![700](attachments/Pasted%20image%2020230226002446.png)
- **创建一个ObjectOutputStream输出流；**
- **调用ObjectOutputStream对象的writeObject输出可序列化对象。**
	- ![](attachments/Pasted%20image%2020230226002414.png)
# Java反序列化步骤
- -**创建一个ObjectInputStream输入流；**
-   **调用ObjectInputStream对象的readObject()得到序列化的对象。**
```java
public class Person implements Serializable {
  private String name;
  private int age;
  //我不提供无参构造器
  public Person(String name, int age) {
      System.out.println("反序列化，你调用我了吗？");
      this.name = name;
      this.age = age;
  }

  @Override
  public String toString() {
      return "Person{" +
              "name='" + name + '\'' +
              ", age=" + age +
              '}';
  }
}

public class ReadObject {
  public static void main(String[] args) {
      try (//创建一个ObjectInputStream输入流
           ObjectInputStream ois = new ObjectInputStream(new FileInputStream("person.txt"))) {
          Person brady = (Person) ois.readObject();
          System.out.println(brady);
      } catch (Exception e) {
          e.printStackTrace();
      }
  }
}
//输出结果
//Person{name='9龙', age=23}

```