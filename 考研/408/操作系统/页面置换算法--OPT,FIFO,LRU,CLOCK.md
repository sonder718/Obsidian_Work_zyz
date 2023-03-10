# 产生原因
- 内存满了,调出哪个页面?
- 希望能有较低的页面更换频率
# 最佳置换算法OPT
- 选择**未来最长时间不被访问**的页面 #注意 
	- 不是以后访问次数最小
- 无法预知，所以该算法**无法实现**

# 先入先出页面置换算法FIFO
- 即淘汰内存中**驻留时间最久的页面**
	- 按进入的先后次序链接成队列,设置一个指针总是**指向最老的页面** #注意
## 一个示例
在一个请求分页系统中，采用FIFO页面置换算法时，假如一个作业的页面走向为4、3、2、1、4、3、5、4、3、2、1、5，当分配给该作业的物理块数M分别为3和4时，试计算在访问过程中所发生的缺页次数和缺页率，并比较所得结果。

![](https://pic1.zhimg.com/80/v2-883b3d0ac9ecba414f0a15a13cb82f64_1440w.jpg)

-   M=3时，采用FIFO页面置换算法的缺页次数为12 - 3 = 9次，缺页率为75%；
-   M=4时，采用FIFO页面置换算法的缺页次数为12 -4 = 10次，缺页率为83%。
-   **Belady现象**
	- 由此可见，**增加**分配给作业的内存块数，反而**增加了缺页次数**，提高了缺页率，这种现象被称为是Belady现象。 #注意
	- #注意 LRU和OPT算法不会出现Belady现象
# 最近最久未使用置换算法LRU
- 需要寄存器和栈的硬件支持
- 选择**最近最久未使用的页面**
	- 每个页面设置有访问字段,记录==上次访问以来==经历的时间 #注意 #z408 
- #注意 性能接近OPT,但开销大
- ![](attachments/%E9%A1%B5%E9%9D%A2%E7%BD%AE%E6%8D%A2%E7%AE%97%E6%B3%95-OPT,FIFO,LRU,CLOCK%202022-11-07%2001.21.18.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E9%A1%B5%E9%9D%A2%E7%BD%AE%E6%8D%A2%E7%AE%97%E6%B3%95-OPT,FIFO,LRU,CLOCK%202022-11-07%2001.21.18.excalidraw.md), and the [dark exported image](attachments/%E9%A1%B5%E9%9D%A2%E7%BD%AE%E6%8D%A2%E7%AE%97%E6%B3%95-OPT,FIFO,LRU,CLOCK%202022-11-07%2001.21.18.excalidraw.dark.svg)%%

# 最少使用置换算法（LFU）
- 需要硬件支持

# 时钟置换算法CLOCK
- 试图用**比较小的开销**接近LRU的性能 #注意
## 简单的CLOCK算法(最近未用算法NRU)
- 循环检查各页面使用情况，只用==一位访问位==来表示**是否用过**，置换时候**把未使用的页面**换出去
- **访问时**
	- 将访问位置为1
- **替换时**
	- 经过一轮遍历，每次遍历到一个节点发现u=1的，将**该标记位置为0**，然后遍历下一个页面，一轮遍历完后，发现没有可以被逐出的页面，则进行下一轮遍历
	- #注意 替换指针初始指向1,当**完成替换**时,指向**下一帧**
	- ![](attachments/%E9%A1%B5%E9%9D%A2%E7%BD%AE%E6%8D%A2%E7%AE%97%E6%B3%95%202022-09-27%2021.40.42.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E9%A1%B5%E9%9D%A2%E7%BD%AE%E6%8D%A2%E7%AE%97%E6%B3%95%202022-09-27%2021.40.42.excalidraw.md)%%

![](attachments/%E9%A1%B5%E9%9D%A2%E7%BD%AE%E6%8D%A2%E7%AE%97%E6%B3%95%202022-09-27%2021.16.21.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E9%A1%B5%E9%9D%A2%E7%BD%AE%E6%8D%A2%E7%AE%97%E6%B3%95%202022-09-27%2021.16.21.excalidraw.md)%%

### 改进版CLOCK算法-增加置换代价(修改位)
- 因为修改过的页面在换出时付出的开销比未被修改过的页面大，在改进型Clock算法中，既考虑**页面的使用情况**，还要增加**置换代价**的因素； 
- 在选择页面作为淘汰页面时，把同时满足**未使用过**(使用位为0)和**未被修改**(修改位为0)作为首选淘汰页面。
- **淘汰优先级**
	-   (u=0, m=0) 没有使用也没有修改，被逐出的优先级最高；
	-   (u=1, m=0) 使用过，但是**没有修改过**，优先级第二； #注意 #z408 
	-   (u=0, m=1) 没有使用过，但是修改过，优先级第三；
	-   (u=1, m=1) 使用过也修改过，优先级第四。
- **算法执行方式**
	- 从指针的当前位置开始,扫描循环队列,寻找A=0且M=0的1类页面,将遇到的第一个1类页面作为选中的淘汰页。在**第一次扫描期间不改变访问位A。**
	- 若第1)步失败,则进行第二轮扫描,寻找A=0且M=1的2类页面。将遇到的第一个2类页面作为淘汰页。在第二轮扫描期间,**将所有扫描过的页面的访问位都置为0**。
	- 若第2)步也失败,则**将指针返回到开始的位置**,并将所有顿的访问位置为0。重复第1)步,并且若有必要,重复第2)步,此时一定
	- 能找到被淘汰的页。
- #注意 
- ![](attachments/Pasted%20image%2020220928111140.png)
