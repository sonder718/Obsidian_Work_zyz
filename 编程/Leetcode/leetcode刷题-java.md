- [MisterBooo/LeetCodeAnimation: Demonstrate all the questions on LeetCode in the form of animation.（用动画的形式呈现解LeetCode题目的思路） (github.com)](https://github.com/MisterBooo/LeetCodeAnimation)
- [CodeTop企业题库](https://codetop.cc/home)
	- 面试考察频度

##### 链表
- [[2-两数相加]]
	- 逐位相加,计算进位和剩余位
- [[206-反转链表]]
	- 双指针pre和cur,始终cur->pre
- [[146-LRU缓存]]
	- hashmap<key,Node>
	- Node用双向链表链接方便获取最新和最老节点
	- Node中存放value
	- 先写抽象的函数move_node_to_header(..),再写具体函数实现
##### 滑动窗口
- [[3-无重复字符的最长子串]]
	- 滑动窗口
	- map找重复字符
	- 不进行字符串拼接