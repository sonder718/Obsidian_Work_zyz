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
	- 对于InnoDB存储引擎，每一行记录都有两个隐藏列**trx_id**、**roll_pointer**，如果表中没有主键和非NULL唯一键时，则还会有第三个隐藏的主键列**row_id**。
	- ![](attachments/Pasted%20image%2020230101213732.png)
- 隔离级别设置为读已提交（RC），事务A和事务B同时对core_user表进行查询和修改操作。
	- ![](attachments/Pasted%20image%2020230101212254.png)
	- ![](attachments/Pasted%20image%2020230101212345.png)
- A开启事务，首先得到一个事务ID为100
- B开启事务，得到事务ID为101
- 事务A生成一个Read View
	- [[MVCC-Read View]]
	- ![](attachments/Pasted%20image%2020230101212503.png)
- 然后回到版本链：开始从版本链中挑选可见的记录
	- read view可见性规则校验
	- ![](attachments/Pasted%20image%2020230101213002.png)
	- 由此可得，trx_id=100的这个记录，当前事务是可见的。所以查到是name为`孙权`的记录。
- 事务B进行修改操作，把名字改为曹操。
	- 把原数据拷贝到undo log,然后对数据进行修改，标记事务ID和上一个数据版本在undo log的地址
	- ![](attachments/Pasted%20image%2020230101213047.png)
- 提交事务B
- 事务A再次执行查询操作，**新生成一个Read View**，Read View对应的值如下
	- ![](attachments/Pasted%20image%2020230101213113.png)
- 再次回到版本链：从版本链中挑选可见的记录
	- ![](attachments/Pasted%20image%2020230101213233.png)
- 在**读已提交（RC）隔离级别**下，同一个事务里，两个相同的查询，读取同一条记录（id=1），却返回了不同的数据（**第一次查出来是孙权，第二次查出来是曹操那条记录**），因此RC隔离级别，存在**不可重复读**并发问题。
##### 可重复读（RR）隔离级别，解决不可重复读问题的分析
- 在读已提交（RC）隔离级别下，同一个事务里面，**每一次查询都会产生一个新的Read View副本**
- 在可重复读（RR）隔离级别下，**一个事务里只会获取一次read view**，都是副本共用的，从而保证每次查询的数据都是一样的。
- ![](attachments/Pasted%20image%2020230101213521.png)
- 再次回到版本链：从版本链中挑选可见的记录
- ![](attachments/Pasted%20image%2020230101213641.png)
- ![](attachments/Pasted%20image%2020230101213548.png)