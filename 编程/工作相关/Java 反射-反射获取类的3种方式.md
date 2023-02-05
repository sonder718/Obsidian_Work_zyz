# 什么是正射和反射
- **正射**-直接初始化
	- ```javaApple apple = new Apple(); //直接初始化，「正射」```
- **反射**-在**运行时**才知道要操作的类是什么，并且可以在运行时获取类的完整构造，并调用对应的方法。
	- 使用 JDK 提供的==反射 API== 进行反射调用
```java
//获取类的 Class 对象实例
Class clz = Class.forName("com.chenshuyi.api.Apple");
//获取clz类的setPrice方法
Method setPriceMethod = clz.getMethod("setPrice", int.class);
//根据 Class 对象实例获取 Constructor 对象
Constructor appleConstructor = clz.getConstructor();
//使用 Constructor 对象的 newInstance 方法获取反射类对象
Object appleObj = appleConstructor.newInstance();
//向setPrice方法中传入反射类对象
setPriceMethod.invoke(appleObj, 14);
//获取clz类的getPrice方法
Method getPriceMethod = clz.getMethod("getPrice");
System.out.println("Apple Price:" + getPriceMethod.invoke(appleObj));
```

# 反射获取类的3种方式
![](attachments/Pasted%20image%2020230204190229.png)