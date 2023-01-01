##### 参考文献
- [看一遍就理解：MVCC原理详解 - 掘金 (juejin.cn)](https://juejin.cn/post/7016165148020703246)
##### 什么是MVCC
- 全称Multi-Version Concurrency Control，即`多版本并发控制`，主要是为了提高数据库的`并发性能`。
- 数据库中同时存在**多个版本的数据**
	- 并不是整个数据库的多个版本，而是**某一条记录的多个版本**同时存在
- 在某个事务对其进行操作的时候，需要查看这一条记录的**隐藏列事务版本id**，比对事务id并根据事务隔离级别去判断读取哪个版本的数据。
	- [[数据库事务]]
##### MVCC的实现原理
1.  获取事务自己的版本号，即事务ID
2.  获取Read View
3.  查询得到的数据，然后Read View中的事务版本号进行比较。
4.  如果不符合Read View的可见性规则， 即就需要Undo log中历史快照;
5.  最后返回符合规则的数据

InnoDB 实现MVCC，是通过 `Read View+ Undo Log` 实现的，Undo Log 保存了历史快照，Read View可见性规则帮助判断当前版本的数据是否可见。

##### 读已提交（RC）隔离级别，存在不可重复读问题的分析历程
- 创建core_user表，插入一条初始化数据
	- ![](attachments/Pasted%20image%2020230101212237.png)
- 隔离级别设置为读已提交（RC），事务A和事务B同时对core_user表进行查询和修改操作。
	- ![](attachments/Pasted%20image%2020230101212254.png)
	- ![](attachments/Pasted%20image%2020230101212345.png)
- A开启事务，首先得到一个事务ID为100
- B开启事务，得到事务ID为101
- 事务A生成一个Read View
	- [[MVCC-Read View]]
	- ![](attachments/Pasted%20image%2020230101212503.png)