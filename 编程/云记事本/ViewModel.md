# ViewModel方法

- 类似寄存器
- 创建派生自ViewModel的类,内部封装大量livedata
- 创建时引用延迟初始化引用,ViewModelProvider
- activity的销毁不影响他,独立activity生命周期
- 一定不要引用activity及其组件
- 如果重新创建了该 Activity，它接收的 `MyViewModel` 实例与第一个 Activity 创建的实例相同。当所有者 Activity 完成时，框架会调用 [`ViewModel`](https://developer.android.google.cn/reference/androidx/lifecycle/ViewModel) 对象的 [`onCleared()`](https://developer.android.google.cn/reference/androidx/lifecycle/ViewModel#onCleared()) 方法，以便它可以清理资源。
- 创建ViewModel
val testViewModel = ViewModelProvider(this).get(MainViewModel::class.java)

ViewModel 要保存数据（数据共享）**不能使用 ViewModel 直接创建对象**的方式，通过 ViewModelProvider 提供 ViewModel 实例，已达到此目的。

- ## 在 Fragment 之间共享数据
Activity 中的两个或更多 Fragment 需要相互通信是一种很常见的现象。想象一下拆分视图 (`list-detail`) Fragment 的常见情况，假设您有一个 Fragment，在该 Fragment 中，用户从列表中选择一项，还有另一个 Fragment，用于显示选定项的内容。这种情况不太容易处理，因为这两个 Fragment 都需要定义某种接口描述，并且所有者 Activity 必须将两者绑定在一起。此外，这两个 Fragment 都必须处理另一个 Fragment 尚未创建或不可见的情况。

可以使用 [`ViewModel`](https://developer.android.google.cn/reference/androidx/lifecycle/ViewModel) 对象解决这一常见的难点。这两个 fragment 可以使用其 activity 范围共享 [`ViewModel`](https://developer.android.google.cn/reference/androidx/lifecycle/ViewModel) 来处理此类通信，如以下示例代码所示：
```kotlin
class SharedViewModel : ViewModel() {    val selected = MutableLiveData<Item>()    fun select(item: Item) {        selected.value = item    }  
}
```

## 注意
![](attachments/Pasted%20image%2020220508151622.png)

## 建立ViewModel类
![](attachments/Pasted%20image%2020220622231554.png)
