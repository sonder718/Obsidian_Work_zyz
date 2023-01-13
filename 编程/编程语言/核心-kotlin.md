[Kotlin Docs | Kotlin (kotlinlang.org)](https://kotlinlang.org/docs/home.html)
# val与var
val:只读属性
var:可写属性
在Kotlin的类中只要使用val/var定义的字段，它就是类的属性，然后会自带getter和setter方法(val属性相当于Java的final变量，是没有set方法的)
# lateinit与by lazy
```
private lateinit var mTextView: TextView
```

```kotlin
val a2:String by lazy{
    println("开始初始化")
    // 初始化的值
    "sss"
}
```

by lazy在kotlin中使用是很常见的，用于实现懒加载某个数据。而这两个单词不是一体的，其中by是kotlin中的关键字，用于实现委托；lazy是一个方法，他的返回值是委托的具体对象。

-   延迟属性（lazy properties）: 其值只在首次访问时计算；
-   可观察属性（observable properties）: 监听器会收到有关此属性变更的通知；
-   把多个属性储存在一个映射（map）中，而不是每个存在单独的字段中。

**{}中的最后一行代码，需要返回初始化的结果**，上述代码中，"sss"即为最后初始化的值。下面是lazy的一些注意点：

-   lazy只能对常量val使用，不能修饰变量var
-   lazy的加载时机为第一次调用常量的时候，且只会加载一次（毕竟是个常量，只能赋值一次）

# 输出日志信息
可以写个小函数
```
log.d("Mainactivaty","messgae")//标签,信息
```
![](attachments/Pasted%20image%2020220424003840.png)
![](attachments/Pasted%20image%2020220424003824.png)
# Any
使用any作为任意类型传参
?代表可能为空
# It
只有一个参数时可以用it代替

# 全局变量

```
companion object
{
var globalcount:Int=0
}

```

![](attachments/Pasted%20image%2020220427005605.png)

# data class
`data class`就是一个类中只包含一些数据字段，类似于`vo`,`pojo`,`java bean`。一般而言，我们在`Java`中定义了这个数据类之后要重写一下`toString，equals`等方法。要生成`get,set`方法。

# @serializable
android {
    ...
    androidExtensions {
        experimental = true
    }
}

kotlin 的官方序列化库，通过自动生成代码来避免反射。只需要在 kotlin 类上标记 `@serializable`注解就可以，内置标准集合的序列化方法。 支持 JSON，CBOR， Protobuf格式

-   `@Serializable` 注解 用于标记kotlin的类，为类生成序列化`serializer`方法。
-   `@Optional`注解 用于标记属性参数，被标记的属性需要提供默认数据。可选参数，如果序列化数据中有就使用数据提供的，没用就使用默认的
-   `@Serialname`注解 用于标记属性参数，重新定义序列化时的参数名
-   `@Transient`注解 用于标记属性参数， 被标记的参数不参与序列化

  
  
作者：谈小龙  
链接：https://www.jianshu.com/p/69a67f8f47cd  
来源：简书  
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。