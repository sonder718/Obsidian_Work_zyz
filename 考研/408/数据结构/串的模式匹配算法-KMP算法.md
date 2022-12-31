### 什么是模式匹配串
- 求**子串(模式串)** 在**主串**中的位置
### 暴力求解
- 两个计数指针i,j
- O(mn)
- 最坏情况0000000001,找0001,**总是比较到最后一个才发现不等**
- ![](attachments/Pasted%20image%2020221017210241.png)
### KMP算法
- **时间复杂度**
	- ==O(m+n)==
- **目标**
	- 主串中的指针==永不回退== #注意
	- ![](attachments/%E4%B8%B2%E7%9A%84%E6%A8%A1%E5%BC%8F%E5%8C%B9%E9%85%8D%E7%AE%97%E6%B3%95-KMP%E7%AE%97%E6%B3%95%202022-10-17%2021.05.47.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E4%B8%B2%E7%9A%84%E6%A8%A1%E5%BC%8F%E5%8C%B9%E9%85%8D%E7%AE%97%E6%B3%95-KMP%E7%AE%97%E6%B3%95%202022-10-17%2021.05.47.excalidraw.md)%%
- **跳过**子串与主串**相同的前缀**
	- 和==子串==长度相同的**next数组**
		- **如果匹配到的最后一个字符是** `子串[i]`
		- 则已知**主串当前所指字符**前面的`next[i]`个字符和**子串的**前`next[i]`个字符==相同==,即无需回退再次尝试匹配
			- #注意 但是匹配出错的字符会==再次进行匹配尝试== #z408 
	- ![](attachments/%E4%B8%B2%E7%9A%84%E6%A8%A1%E5%BC%8F%E5%8C%B9%E9%85%8D%E7%AE%97%E6%B3%95-KMP%E7%AE%97%E6%B3%95%202022-10-17%2021.10.14.excalidraw.svg)

%%[🖋 Edit in Excalidraw](attachments/%E4%B8%B2%E7%9A%84%E6%A8%A1%E5%BC%8F%E5%8C%B9%E9%85%8D%E7%AE%97%E6%B3%95-KMP%E7%AE%97%E6%B3%95%202022-10-17%2021.10.14.excalidraw.md)%%
#### 采用部分匹配值的next数组(原始版)
- **部分匹配值**的next数组的**本质**
	- 子串中==最长==**相同前后缀的长度** #z408 
	- #注意 不能是子串**自身**,但是==可以有重叠==
		- ![](attachments/Pasted%20image%2020221017221212.png)
	- ![](attachments/%E4%B8%B2%E7%9A%84%E6%A8%A1%E5%BC%8F%E5%8C%B9%E9%85%8D%E7%AE%97%E6%B3%95-KMP%E7%AE%97%E6%B3%95%202022-10-17%2021.23.54.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E4%B8%B2%E7%9A%84%E6%A8%A1%E5%BC%8F%E5%8C%B9%E9%85%8D%E7%AE%97%E6%B3%95-KMP%E7%AE%97%E6%B3%95%202022-10-17%2021.23.54.excalidraw.md)%%
- **next数组的快速求解**
	- ![](attachments/Pasted%20image%2020221017213325.png)
	- ![](attachments/%E4%B8%B2%E7%9A%84%E6%A8%A1%E5%BC%8F%E5%8C%B9%E9%85%8D%E7%AE%97%E6%B3%95-KMP%E7%AE%97%E6%B3%95%202022-10-17%2021.27.53.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E4%B8%B2%E7%9A%84%E6%A8%A1%E5%BC%8F%E5%8C%B9%E9%85%8D%E7%AE%97%E6%B3%95-KMP%E7%AE%97%E6%B3%95%202022-10-17%2021.27.53.excalidraw.md)%%
#### 改进版next数组
- **背景**
	- 部分匹配值法有时会失配
	- ![](attachments/Pasted%20image%2020221017220649.png)
- **改进方式**
	- 部分匹配值表==整体右移一位==,**空缺用-1填充**,再==整体加1== #注意
	- ![](attachments/%E4%B8%B2%E7%9A%84%E6%A8%A1%E5%BC%8F%E5%8C%B9%E9%85%8D%E7%AE%97%E6%B3%95-KMP%E7%AE%97%E6%B3%95%202022-10-17%2022.10.46.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E4%B8%B2%E7%9A%84%E6%A8%A1%E5%BC%8F%E5%8C%B9%E9%85%8D%E7%AE%97%E6%B3%95-KMP%E7%AE%97%E6%B3%95%202022-10-17%2022.10.46.excalidraw.md)%%
#### 再次优化-nextval数组
-  `nextval[1]=0`
-  本位字符与`next`数组所对应的==字符==相比较
	- 如果相等则为`next[next[j]]`
		- #注意 如果修正后本位字符依旧与`next`数组所对应的字符**相等**,则需要再次修正
		- ![](attachments/Pasted%20image%2020221017231257.png)
	- 如果不相等则==不变==
- ![](attachments/%E4%B8%B2%E7%9A%84%E6%A8%A1%E5%BC%8F%E5%8C%B9%E9%85%8D%E7%AE%97%E6%B3%95-KMP%E7%AE%97%E6%B3%95%202022-10-17%2022.43.08.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E4%B8%B2%E7%9A%84%E6%A8%A1%E5%BC%8F%E5%8C%B9%E9%85%8D%E7%AE%97%E6%B3%95-KMP%E7%AE%97%E6%B3%95%202022-10-17%2022.43.08.excalidraw.md)%%