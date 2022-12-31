 # 总体MVVM架构
 ![](attachments/Pasted%20image%2020220508160958.png)
 ![](attachments/Pasted%20image%2020220508163144.png)
 ![](attachments/Pasted%20image%2020220508163215.png)
 ![](attachments/Pasted%20image%2020220508163344.png)

## 架构
界面呈现的数据放在ViewModel中,数据变成一个livedata,暴露公有方法
![](attachments/Pasted%20image%2020220508162832.png)
绑定ViewModel对象
![](attachments/Pasted%20image%2020220508163003.png)
控件绑定livedata对象
![](attachments/Pasted%20image%2020220508163019.png)
设置生命周期感知对象
![](attachments/Pasted%20image%2020220508163059.png)

# 生命周期组件
避免大量重写组件生命周期方法-->原来要重写大量oncreate,onstop且分散
-->
集中到lifecycle组件

## tips
尽量写界面无关代码


# LiveData
- Activity可**观察**的数据容器
- 能自动感知外部activity是否可见
- 允许外界改的mutablelivedata,建议设为私有,用访问器访问
- 跨线程要用postvalue
![](attachments/Pasted%20image%2020220508152033.png)
- 转换函数:接收类型A转为类型B,e.g.整数转为日期返回textview
- livedata示例
- 汇聚多个livedata
![](attachments/Pasted%20image%2020220508151905.png)
# ViewModel⭐
[[ViewModel]]
# ViewBinding
[[ViewBinding]]

# 导航
![](attachments/Pasted%20image%2020220508153343.png)
![](attachments/Pasted%20image%2020220508153450.png)
## tips
- 子导航图
![](attachments/Pasted%20image%2020220508152150.png)![](attachments/Pasted%20image%2020220508152323.png)
![](attachments/Pasted%20image%2020220508152447.png)
得到控制器(Mainactivity)
![](attachments/Pasted%20image%2020220508152709.png)
fragment
![](attachments/Pasted%20image%2020220511004925.png)
## 目的地id导航/导航线action id
![](attachments/Pasted%20image%2020220508152734.png)

## 传输参数
fragment中
![](attachments/Pasted%20image%2020220508153726.png)
接收
![](attachments/Pasted%20image%2020220508153807.png)

## 回退管理
![](attachments/Pasted%20image%2020220508154031.png)
## toolbar
![](attachments/Pasted%20image%2020220508154355.png)
![](attachments/Pasted%20image%2020220508154420.png)
![](attachments/Pasted%20image%2020220508154430.png)
## 底部导航栏
![](attachments/Pasted%20image%2020220508154657.png)


# viewpage2
## tips
- 左右滑动显示(常用起始引导页)
- 适配器,每个界面用一个fragment呈现
![](attachments/Pasted%20image%2020220508155245.png)
![](attachments/Pasted%20image%2020220508155152.png)
- 另一种显示动态数量图片,较为麻烦

# 选项卡式布局
- 上面是tablayout
- 下面是viewpage2
![](attachments/Pasted%20image%2020220508155545.png)
# 视图绑定
## activity使用
![](attachments/Pasted%20image%2020220508155701.png)
![](attachments/Pasted%20image%2020220508155842.png)
![](attachments/Pasted%20image%2020220508155926.png)
进行简化,省去binding对象的写
![](attachments/Pasted%20image%2020220508155946.png)

## fragment使用
![](attachments/Pasted%20image%2020220508160132.png)

# 数据绑定data binding
![](attachments/Pasted%20image%2020220508160753.png)
## 过去
![](attachments/Pasted%20image%2020220508160449.png)
## 步骤
![](attachments/Pasted%20image%2020220508160512.png)
![](attachments/Pasted%20image%2020220508160519.png)
最顶层需要是layout

![](attachments/Pasted%20image%2020220508160535.png)
定义数据源
![](attachments/Pasted%20image%2020220508160603.png)
![](attachments/Pasted%20image%2020220508160617.png)
![](attachments/Pasted%20image%2020220508160637.png)
## 数据绑定表达式
几乎不用
![](attachments/Pasted%20image%2020220508161149.png)
![](attachments/Pasted%20image%2020220508161201.png)
![](attachments/Pasted%20image%2020220508161316.png)

## 适配器adapter
职责:一种类型转化为另一种类型对象
### string变bitmap
![](attachments/Pasted%20image%2020220508161745.png)
![](attachments/Pasted%20image%2020220508161705.png)
![](attachments/Pasted%20image%2020220508161551.png)
![](attachments/Pasted%20image%2020220508161611.png)
![](attachments/Pasted%20image%2020220508161632.png)
## 双向绑定
![](attachments/Pasted%20image%2020220508162424.png)
### (旧)重新绑定
不重新绑定的话不会自动修改
![](attachments/Pasted%20image%2020220508161936.png)
## 自动更新(较为复杂的情况)
设计数据类,派生
![](attachments/Pasted%20image%2020220508162154.png)

### 双向绑定
=即允许修改
![](attachments/Pasted%20image%2020220508162555.png)

# recyclerview
[Recyclerview  |  Android 开发者  |  Android Developers (google.cn)](https://developer.android.google.cn/jetpack/androidx/releases/recyclerview?hl=zh-cn)
- 取代listview
![](attachments/Pasted%20image%2020220508164105.png)
- 每一行提供行模板(每行要显示的信息)
![](attachments/Pasted%20image%2020220508164241.png)
- Viewholder关联数据对象与行模板,数据对象的相关属性赋值给控件,所有事件绑定信息都在viewhold中完成
![](attachments/Pasted%20image%2020220508165848.png)
![](attachments/Pasted%20image%2020220508165904.png)
![](attachments/Pasted%20image%2020220508165935.png)

---
![](attachments/Pasted%20image%2020220508164329.png)
自定义响应接口,注入对象,通常作为单例对象
![](attachments/Pasted%20image%2020220508164817.png)
![](attachments/Pasted%20image%2020220508164828.png)
- Adapter,封装数据对象与recycleview,传入data,派生,重写方法 
- ![](attachments/Pasted%20image%2020220508170117.png)
![](attachments/Pasted%20image%2020220508164457.png)
-  activity使用
![](attachments/Pasted%20image%2020220508163924.png)
