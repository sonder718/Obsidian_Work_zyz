# 学生课程数据库
![](Attachments/Pasted%20image%2020220528011050.png)
![](Attachments/Pasted%20image%2020220528011107.png)
![](Attachments/Pasted%20image%2020220528011117.png)
![](Attachments/Pasted%20image%2020220528011127.png)
# 注意点
- 空值判断是 **is null**
![](Attachments/Pasted%20image%2020220528175205.png)

# 数据定义
[[SQL数据定义]]
# 数据查询
[[SQL数据查询]]

# 数据更新
[[SQL数据更新]]

# 视图
## 视图的特点
- 虚表,从基本表或视图中导出的表
- 只存放视图的定义,不存放视图对应的数据
- 基表中的数据发生变化,从视图中查询出的数据也随之变化
![](Attachments/Pasted%20image%2020220528175342.png)
## 视图的作用
- 简化用户操作
- 使用户能够以多种角度看待同一数据
- 对重构数据库提供了一定程度的逻辑独立性
- 能够对机密数据进行安全保护

![](Attachments/Pasted%20image%2020220528180821.png)

## 视图的操作
### 创建视图
![](Attachments/Pasted%20image%2020220528181018.png)
![](Attachments/Pasted%20image%2020220528181108.png)
### 删除视图
![](Attachments/Pasted%20image%2020220528181138.png)
### 查询视图
- 视图消解法,转换为等级的对基本表的查询
![](Attachments/Pasted%20image%2020220528181432.png)
![](Attachments/Pasted%20image%2020220528181540.png)
### 更新视图
![](Attachments/Pasted%20image%2020220528181658.png)