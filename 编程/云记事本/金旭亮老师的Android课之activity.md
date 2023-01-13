[[fragment]]
[[jetpack]]

# kotlin
[核心-kotlin](../核心-kotlin.md)
# 编程访问Android控件
## Activity
View:所有控件派生自它
Viewgroup:能包容其他控件
Layout:布局
## 关系
XML中所有元素对应一个对象(JAVA或Kotlin中),每个对象会自动给每个成员编号(根据id),最后都生成存在了R.java中

![](attachments/capture-2022-04-24-00-19-07.jpg)
## 消除findviewbyid(麻烦)
### 视图绑定(view Binding)

### 数据绑定库(MVVM使用)

## 课中所讲一些控件
[UI](UI.md)

# 界面布局基础
不用太多嵌套
控件树
## 盒子模型
Margin(控件间)
padding(控件内)
![](attachments/capture-2022-04-24-01-15-01.jpg)

---

固定
wrap_content:依照显示具体内容,常用按钮与textview
match_parent:同父控件一致

---
## 布局单位
像素单位不合适
设备无关像素dp,指定宽高
文本用sp
颜色选用标准颜色
color.xml设置颜色,xml中调用@color/...


# 万能布局-constraintlayout
外部库的控件(名字长)
### constraint
至少要有两个约束
- 水平
- 垂直
![](attachments/Pasted%20image%2020220424013749.png)
是wrapcontent
![](attachments/Pasted%20image%2020220424013738.png)
# activity与其生命周期
## 回调函数
![](attachments/Pasted%20image%2020220425012458.png)
![](attachments/Pasted%20image%2020220425012539.png)
传一个接口,回调接口的实现重写函数
通过传入不同的回调函数实现在运行一段代码之后,再运行不同的代码

## activity的存亡过程
![](attachments/Pasted%20image%2020220425012726.png)
Oncreate等
![](attachments/Pasted%20image%2020220424203431.png)
![](attachments/Pasted%20image%2020220424204145.png)
显示新界面时,老界面自动onstop
整个退出后 mainactivaty onstop,ondestory
-->关于后台下载
在onstop与onstart

旋转,被认为是配置改变,**销毁再重建activity**
onsaveinstancestate在销毁时会自动调用
Bundle类型负责存储信息
```
private var counter=0
override  fun onsaveinstancestate(outstate:Bundle)
{
super.onsaveinstancestate(outstate:Bundle)
//保存实例数据
outstate.putint("counter",counter)
}

```

数据残留:退出后静态变量短暂保留

# 多activity
注意所有activity需要在清单文件注册
## activity之间的信息交换a-保存传送接收
![](attachments/Pasted%20image%2020220425014955.png)
### 保存
![](attachments/Pasted%20image%2020220425015909.png)
### 传递
![](attachments/Pasted%20image%2020220425015949.png)
### 接收
![](attachments/Pasted%20image%2020220425020059.png) 
## activity之间的信息交换b-请求传递
#### 旧的
A-->B
打开:
请求码:一个activity可能请求打开多个activity
接收:
重写onactivityresult(被废弃)
被打开的activity中setactivity(结果码,data)
注意finish
结果码 :
#### 基于回调的(新)⭐
##### 启动者
![](attachments/capture-2022-04-26-23-51-51.jpg)
启动一个activity时定义launcher对象与相应的回调代码
![](attachments/capture-2022-04-26-23-44-19.jpg)
一个launcher对象对应一个activity-->没有请求码只有结果码
启动器在合适的时间接收一个intent对象,不再start activity
![](attachments/capture-2022-04-26-23-50-28.jpg)


##### 接收者(不变)
![](attachments/capture-2022-04-26-23-55-45.jpg)
##### 自定义协议
自己定义传什么,返回什么

## 回退堆栈(回退键的实现)
看到的是栈顶
同一个activity可能有多个记录
## activity的启动模式
使用清单文件
![](attachments/Pasted%20image%2020220427000815.png)
![](attachments/Pasted%20image%2020220427000534.png)
只有复杂程度很高的使用:
![](attachments/Pasted%20image%2020220427000738.png)
## 多activity管理
### 父子activity
![](attachments/Pasted%20image%2020220427004630.png)
### 调用操作系统
![](attachments/Pasted%20image%2020220427005123.png)
[[../核心-kotlin]]实例对象
### 默认启动activity
![](attachments/Pasted%20image%2020220427005849.png)

# intent
## 概念
![](attachments/Pasted%20image%2020220427001146.png)
![](attachments/Pasted%20image%2020220427001241.png)
![](attachments/Pasted%20image%2020220427003057.png)
![](attachments/Pasted%20image%2020220427003128.png)
启动activity
![](attachments/Pasted%20image%2020220427003218.png)
![](attachments/Pasted%20image%2020220427003226.png)
响应哪些intent
![](attachments/Pasted%20image%2020220427003456.png)
![](attachments/Pasted%20image%2020220427003533.png)
## 选择图片示例
![](attachments/Pasted%20image%2020220427003809.png)

# 关于权限
![](attachments/Pasted%20image%2020220427010125.png)

