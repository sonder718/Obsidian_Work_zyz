# fragment
## tips
- miniactivity
- 必须依托activity
- fragment-->控件树,附加在activity
- 先oncreate,后oncreateview
- 声明式:xml中定义名字,name属性
- 代码式:Fragmentmanager

![](attachments/Pasted%20image%2020220427202034.png)
把页面划分成多个fragment,支持**重定位**-->适应多种设备
![](attachments/Pasted%20image%2020220427202134.png)
## fragment的管理
每个fragment有个tag,能够找到他
![](attachments/Pasted%20image%2020220427203403.png)
- 在fragment控件树中找而不是整个控件树中找
- 可以在构造函数中直接写要传递的变量

![](attachments/Pasted%20image%2020220427203852.png)
管理-->添加activity,一整个事务,或全完成
tobackstack:支持回退
选择添加容器
![](attachments/Pasted%20image%2020220427204126.png)
## 生命周期
重写oncreate等方法
当你访问控件,一定要确定其已经创建
## activity to fragment

![](attachments/Pasted%20image%2020220427211328.png)
### 存取消息
简单时建议
![](attachments/Pasted%20image%2020220427212022.png)
![](attachments/Pasted%20image%2020220427211654.png)
### 工厂方法
统一规范,复杂建议

## fragment to activity
定义回调接口-->传什么信息
接口中定义方法
![](attachments/Pasted%20image%2020220427212609.png)
引用activity
![](attachments/Pasted%20image%2020220427212634.png)
指定接口类型属性,回调
![](attachments/Pasted%20image%2020220427212701.png)

activity必须实现接口
![](attachments/Pasted%20image%2020220427212818.png)
![](attachments/Pasted%20image%2020220427212859.png)
# Tips
## setcontent
