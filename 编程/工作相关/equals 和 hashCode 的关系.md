# 什么是equals和hashcode
- `equals()` 的作用是用来判断两个对象**是否相等**。
- `hashCode()` 的作用是获取哈希码，也称为散列码；它实际上是返回一个int整数。这个哈希码的作用是确定**该对象在哈希表中的索引位置**
# equals 和 hashCode 的关系
- 在 HashMap 和 HashSet 中
	- 如果两个对象通过 `equals()` 方法比较相等，那么它们生成的 `hashCode()` 值也应该相同
	- ⭐如果覆盖了 `equals()` 方法，则应该也要覆盖 `hashCode()` 方法,**否则无法判定相同**
		- ![](attachments/Pasted%20image%2020230204191054.png)
	- ![](attachments/9bdd9915d2b1473aa499965ab0808ca1~tplv-k3u1fbpfcp-zoom-in-crop-mark%204536%200%200%200.png)
	- ![](attachments/Pasted%20image%2020230204191112.png)
- 