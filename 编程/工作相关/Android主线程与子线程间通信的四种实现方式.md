- 一般说线程间通信主要是指主线程（也叫**UI线程**）和**子线程**之间的通信
# 通过Handler机制
- 主线程中定义**Handler**,子线程发消息，通知Handler完成UI更新,Handler对象**必须定义在主线程中**，如果是多个类直接互相调用，就不是很方便，需要传递content对象或通过接口调用。 
- 另外Handler机制与Activity生命周期不一致的原因，容易导致内存泄漏，**不推荐使用**。
- ![400](attachments/Pasted%20image%2020230308135210.png)
# runOnUiThread方法
- 用Activity对象的runOnUiThread方法更新，在子线程中通过runOnUiThread()方法更新UI
- ![500](attachments/Pasted%20image%2020230308135917.png)
# AsyncTask机制
- AsyncTask，**异步任务**，也就是说在UI线程运行的时候，可以在后台的执行一些异步的操作
- AsyncTask只能用于**短时间的操作**（最多几秒就应该结束的操作）
- ![](attachments/Pasted%20image%2020230308135748.png)
# View.post(Runnable r)
- ![](attachments/Pasted%20image%2020230308140048.png)
