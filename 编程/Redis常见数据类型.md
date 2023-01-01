- Redis支持五种数据类型：string（字符串），hash（哈希），list（列表），set（集合）及zset(sorted set：有序集合)。
##### String（字符串）
- string 是 redis 最基本的类型,一个 key 对应一个 value
- string 类型是二进制安全的。意思是 redis 的 string 可以包含任何数据。比如jpg图片或者序列化的对象。
- string 类型是 Redis 最基本的数据类型，string 类型的值最大能存储 512MB。
- ![](attachments/Pasted%20image%2020230101215540.png)
##### hash
- Redis hash 是一个 string 类型的 field 和 value 的映射表，hash 特别适合用于存储对象。
- ![](attachments/Pasted%20image%2020230101215616.png)
##### List（列表）
- Redis 列表是简单的字符串列表，按照插入顺序排序。你可以添加一个元素到列表的头部（左边）或者尾部（右边）
- ![](attachments/Pasted%20image%2020230101215642.png)
##### Set（集合）
- Redis 的 Set 是 string 类型的无序集合。
- ![](attachments/Pasted%20image%2020230101215720.png)
##### zset(sorted set：有序集合)
- Redis zset 和 set 一样也是string类型元素的集合,且不允许重复的成员。
- 不同的是每个元素都会关联一个double类型的分数。redis正是通过分数来为集合中的成员进行从小到大的排序。
- ![](attachments/Pasted%20image%2020230101215806.png)
