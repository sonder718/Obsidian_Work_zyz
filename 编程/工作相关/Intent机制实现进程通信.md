# intent的作用
- Intent 由一个**动作**（Action）和一个**数据**（Data）组成。
	- 其中动作描述了要**执行的操作**，数据描述了要操作的数据。
- 通过 Intent，可以启动活动（Activity）、服务（Service）和广播接收器（Broadcast Receiver）,在 Bundle 中附加要传递的数据通过 Intent 发送出去
- Activity，Service，Receiver 都支持在 Intent 中**传递 Bundle 数据**，而 Bundle 实现了 Parcelable 接口，可以在不同的进程间进行传输。

# Intent机制实现进程通信
- Android应用程序可以使用**Intent**来请求操作，比如启动另一个应用程序或启动另一个Activity组件。**通过定义Intent的Action和Category属性，来指定要请求的操作和操作类型**。其他应用程序可以通过定义相同的Intent过滤器来响应这些请求，从而实现应用程序之间的通信。
- **启动Activity并通过intent中的bundle传递数据**
	- ![](attachments/Pasted%20image%2020230228173224.png)
-   在**被启动Activity**中获取传递过来的数据
	- ![](attachments/Pasted%20image%2020230228173309.png)
-   在当前Activity中**重写onActivityResult()** 方法
	- ![](attachments/Pasted%20image%2020230228173355.png)




# Intent支持哪些类型的动作（Action）
-   `ACTION_VIEW`：用于查看指定的数据，例如网页、图片、视频等。可以使用 `setData()` 方法设置要查看的数据，例如：
- `ACTION_SEND`：用于发送数据给其他应用程序，例如文本、图像等。可以使用 `putExtra()` 方法设置要发送的数据，例如：
-   `ACTION_PICK`：用于从指定的数据集中选择一个条目，例如联系人、图片等。可以使用 `setData()` 方法设置要选择的数据集，例如：
-   `ACTION_CALL`：用于拨打电话。可以使用 `setData()` 方法设置要拨打的电话号码，例如：
	- ![](attachments/Pasted%20image%2020230228174054.png)