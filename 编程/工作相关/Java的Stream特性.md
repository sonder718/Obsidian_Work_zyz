# Stream用法示例
- Stream就是一组元素的序列,支持对这些元素进行各种操作，而这些操作是通过**Lambda表达式指定**的
	- 类似数据库查询语句
- ![](attachments/Pasted%20image%2020230206225236.png)
# Stream特性
-   不是数据结构：它没有内部存储，它只是用操作管道从 source（数据结构、数组、generator function、IO channel）抓取数据。它也绝不修改自己所封装的底层数据结构的数据。例如 Stream 的 filter 操作会产生一个不包含被过滤元素的新 Stream，而不是从 source 删除那些元素。
-   不支持索引访问：但是很容易生成数组或者 List 。
-   惰性化：很多 Stream 操作是向后延迟的，一直到它弄清楚了最后需要多少数据才会开始。Intermediate 操作永远是惰性化的。
-   并行能力。当一个 Stream 是并行化的，就不需要再写多线程代码，所有对它的操作会自动并行进行的。
-   可以是无限的：集合有固定大小，Stream 则不必。limit(n) 和 findFirst() 这类的 short-circuiting 操作可以对无限的 Stream 进行运算并很快完成。
-   **注意事项：所有 Stream 的操作必须以 lambda 表达式为参数。**