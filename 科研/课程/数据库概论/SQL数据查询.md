# 数据查询语句格式
![](Attachments/Pasted%20image%2020220528012458.png)
![](Attachments/Pasted%20image%2020220528012506.png)
# 特定子句
## Group by
- 通常在用聚集函数（count(),sum(),avg(),max(),min())时使用
- 该属性列**值相等**的元组为一个组,每组**作用聚集函数**
- 当使用聚集函数就要考虑是否使用group by
- 🐱

## Where 与 Having
-   having子句用于**分组后筛选组**
![](Attachments/Pasted%20image%2020220528120311.png)
- where子句用于**行**条件筛选**元组**
![](Attachments/Pasted%20image%2020220528120335.png)
-   having一般都是配合group by 和聚合函数一起出现
🐱一个SQL同时含有where、group by、having子句
```sql
select city ,count(*) as num 
from staff  
where age> 19 
group by city 
having num >= 3;
```
执行顺序:
1. where语句查询age> 19 的员工的**元组**
2. group by语句对员工数据，根据城市分组,对group by子句形成的城市组，运行聚集函数计算**每一组的员工数量值**
3. having子句选出员工数量大于等于3的城市**组**。

## Order by
- ASC :升序(缺省)
- DESC:降序
- ![](Attachments/Pasted%20image%2020220528120523.png)

```sql
select sno,grade
from SC
where cno=3
order by grade DESC
```


![](Attachments/Pasted%20image%2020220528120440.png)
# 单表查询
## 查询通过计算的值
![](Attachments/Pasted%20image%2020220528121047.png)
出生年份？
小写字母
```sql
select sname,2021-sage,Lower(sdept)
from student
```
![](Attachments/Pasted%20image%2020220528121307.png)
## 别名
改变查询结果的列标题
```sql
select sname name from student
```
![](Attachments/Pasted%20image%2020220528121435.png)
## 消除重复行(distinct)
- select 的 缺省为 all
select sno from sc
![](Attachments/Pasted%20image%2020220528121720.png)
- distinct关键字去除重复行
select distinct sno from sc
![](Attachments/Pasted%20image%2020220528121739.png)
## 查询满足条件的元组
![](Attachments/Pasted%20image%2020220528121835.png)

```sql
select ... from ...
where sno<20 //比较
where sage not between 20 and 30 //范围
where sdept not in ('CS','MA')//集合
where sname not like '刘%'//字符匹配 %代表任意长度,_代表单个字符
where sname like '欧阳_'
where grade is null //不能用=

```

## 聚集函数
- 可以有distinct
![](Attachments/Pasted%20image%2020220528123350.png)
- ![](Attachments/Pasted%20image%2020220528123319.png)
# 连接查询
原理:嵌套循环(A找一个,B找对应),排序合并(排序,中断点)
## 等值连接
![](Attachments/Pasted%20image%2020220528123939.png)
![](Attachments/Pasted%20image%2020220528123946.png)
## 自然连接
![](Attachments/Pasted%20image%2020220528124247.png)
## 自身连接
- 一个表自己与自己连接
- 需要起别名
![](Attachments/Pasted%20image%2020220528145115.png)
我的写法:总体上时正确的,即cpno的先修课
```sql
select c2.cpno
from course c1 ,course c2
where c1.cpno=c2.cno
```
![](Attachments/Pasted%20image%2020220528145627.png)
## 外连接
- 左/右外连接会列出左/右的所有元组,无论另一个表中是否存在空值
![](Attachments/Pasted%20image%2020220528150046.png)
![](Attachments/Pasted%20image%2020220528145900.png)
![](Attachments/Pasted%20image%2020220528145917.png)
![](Attachments/Pasted%20image%2020220528145925.png)
## 连接查询实例
![](Attachments/Pasted%20image%2020220528144406.png)
我写的sql语句 ✖==没有带表名==
```sql
select sno,sname from sc,student
where student.sno=sc.sno and cno=2 and grade>60
```
修改后
```sql
select student.sno,sname from sc,student
where student.sno=sc.sno and sc.cno=2 and sc.grade>60


```

# 嵌套查询
## 概述
- 外层是父查询,内层是子查询
- **子查询不能使用order by**
- 不相关子查询:子查询不依赖于父查询,自里向外逐步求解
- 相关子查询:子查询的查询条件依赖于父查询,外->内->外->内
![](Attachments/Pasted%20image%2020220528153907.png)
![SQL数据查询](SQL数据查询.md#带有比较运算符的子查询)
![](Attachments/Pasted%20image%2020220528150358.png) ^txm075
## 带有in谓词的子查询
### 例1
![](Attachments/Pasted%20image%2020220528151552.png)
1.查询刘晨的系sdept1
2.查询与sdept1相同的元组
```sql
select sno,sname from student 
where sdept in 
(
select sdept 
from student
where sname='刘晨'
)
```
![](Attachments/Pasted%20image%2020220528152018.png)
自身连接同样可以完成
![](Attachments/Pasted%20image%2020220528152133.png)
### 例2
1. 信息系统的课程号
2. 选信息系统号的学号
![](Attachments/Pasted%20image%2020220528152217.png)
```sql
select sname in student 
where sno in(
select sno from sc
where  cno in (
select cno from course
where cnaeme='信息系统'))
```
![](Attachments/Pasted%20image%2020220528152525.png)
![](Attachments/Pasted%20image%2020220528152603.png)
## 带有比较运算符的子查询
![](Attachments/Pasted%20image%2020220528152709.png)
![](Attachments/Pasted%20image%2020220528152729.png)
✖错误示例,应利用相关子查询
```sql
select cno from sc 
where grade>=
(
select avg(grade) from sc
group by sno)
```
✔
```sql
select sno,cno
from sc x
where grade>=
(
select avg(grade) from sc y
where x.sno=y.sno
)
```
执行过程如下:
![](Attachments/Pasted%20image%2020220528153706.png)
![](Attachments/Pasted%20image%2020220528153750.png)
![](Attachments/Pasted%20image%2020220528153818.png)

## 带有any或some或all的子查询
- any表示有任何一个满足就返回true，all表示全部都满足才返回true
- 可以与聚集函数的max与min进行转换

![](Attachments/Pasted%20image%2020220528154922.png)
![](Attachments/Pasted%20image%2020220528155010.png)
### 例1
![](Attachments/Pasted%20image%2020220528155020.png)
✖任意一个应该是any
```sql
select sname,sno from student
where sdept=!'cs' and sage<all( 
select sage from student
where sdept='cs')
```
![](Attachments/Pasted%20image%2020220528155345.png)
![](Attachments/Pasted%20image%2020220528155724.png)
![](Attachments/Pasted%20image%2020220528155747.png)
## 带有exists的子查询⭐
- 子查询只返回true/false,**exists**即内层查询为空时返回false,查询到了返回true
- in可以用exist等价代换
- ⭐常利用exists与not exists实现**全称量词与逻辑蕴含**
- 子查询的目标列通常用*
- 请尽量不要使用not in(它会调用子查询)，而尽量使用not exists（它会调用关联子查询）![SQL数据查询](SQL数据查询.md#^txm075)
![](Attachments/Pasted%20image%2020220528155859.png)
![](Attachments/Pasted%20image%2020220528155934.png)
### 例1
![](Attachments/Pasted%20image%2020220528161225.png)
```sql
select sname from student
where sno in (select ...)

```
```sql
select sname from student s
where exists (
select * from sc
where s.sno=sc.sno and cno='1'
)

```
![](Attachments/Pasted%20image%2020220528161930.png)
### 实现全称量词(任意)
通过存在表达任意
![](Attachments/Pasted%20image%2020220528163306.png)
![](Attachments/Pasted%20image%2020220528163426.png)
```sql
select sname from student s1
where exists(
select * from student s2
where s1.sdept=s2.sdept and s2.sname='刘晨'//s1传过来一个元组,其sdept与s2.sname='刘晨'的元组的sdept比对
)
```
![](Attachments/Pasted%20image%2020220528163649.png)
![](Attachments/Pasted%20image%2020220528164117.png)
选修了全部课程=没有一门课程是他不选修的
✖
```sql
select sno from sc sc1
where not exists
(
select * from sc sc2
where not exists
(
select * from course cou2
where sc2.cno!=cou2.cno
)
)
```
✔
![](Attachments/Pasted%20image%2020220528164916.png)
![](Attachments/Pasted%20image%2020220528165320.png)
```sql
select sname from student st1
//遍历每一个学生
where not exists (//该学生 不存在 有一门课不选修
//遍历每门课
select * from course cour1
where not exists(//不存在这门课没选修
select * from sc sc1
where st1.sno=sc1.sno and cour1.cno=sc2.cno
				 //例如找到(sno=201215121,cno=1)时返回false
)
)
```
### 实现逻辑蕴含
![](Attachments/Pasted%20image%2020220528171111.png)
![](Attachments/Pasted%20image%2020220528171124.png)
查询学号为x的学生,对于任意课程y
如果P: 201215122选修了课程y
那么q: x选修了课程y
**转换为**
不存在这样的课程y,201215122选修了,但学生x没有选
✖
```sql
//遍历所有学生

//遍历所有课程
not exists 
(
select * from sc sc2
where sc2.sno=201215122 and sc1.cno 
)
```
✔
```sql
//遍历所有sc表学生
select sno from sc sc1
where not exists//返回201215121是否选修了所有201215122选修了的课程
(//遍历所有201215122选修了的课程
select * from sc sc2
 where sc2.sno=201215122 and not exists//返回201215121是否选择201215122选修的课程a
 (
 select * from sc sc3
 where sc3.cno=sc2.cno and sc3.sno=sc1.sno//201215121选择了201215122选修的课程a,返回真
 )
)


```
![](Attachments/Pasted%20image%2020220528171143.png)
![](Attachments/Pasted%20image%2020220528171425.png)
![](Attachments/Pasted%20image%2020220528172043.png)
![](Attachments/Pasted%20image%2020220528172127.png)

# 集合查询
union
intersect
except
![](Attachments/Pasted%20image%2020220528173827.png)
```sql
select sno from sc
where cno=1
intersect
select sno from sc
where cno=2
```
![](Attachments/Pasted%20image%2020220528173849.png)
![](Attachments/Pasted%20image%2020220528173907.png)

# 基于派生表的查询
![](Attachments/Pasted%20image%2020220528174138.png)