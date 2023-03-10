### 滑动窗口协议-选择重传协议SR
#### 产生的原因
- GBN在重传时必须把原来已经正确传送的数据帧重传->可不可以**只重传出错的帧**?
- **解决办法**
	- 设置单个确认
	- 加大接收窗口
	- 设置接收缓存,==缓存乱序到达的帧==。
#### 滑动窗口
![](attachments/%E6%B5%81%E9%87%8F%E6%8E%A7%E5%88%B6,%E5%8F%AF%E9%9D%A0%E4%BC%A0%E8%BE%93%E4%B8%8E%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%202022-10-07%2015.20.26.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E6%B5%81%E9%87%8F%E6%8E%A7%E5%88%B6,%E5%8F%AF%E9%9D%A0%E4%BC%A0%E8%BE%93%E4%B8%8E%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%202022-10-07%2015.20.26.excalidraw.md)%%
#### 运行中的SR
![](attachments/%E6%B5%81%E9%87%8F%E6%8E%A7%E5%88%B6,%E5%8F%AF%E9%9D%A0%E4%BC%A0%E8%BE%93%E4%B8%8E%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%202022-10-07%2019.58.28.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/%E6%B5%81%E9%87%8F%E6%8E%A7%E5%88%B6,%E5%8F%AF%E9%9D%A0%E4%BC%A0%E8%BE%93%E4%B8%8E%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%202022-10-07%2019.58.28.excalidraw.md)%%
#### 发送方与接受方需要做的事
##### 发送方
- **上层的调用**
	- 从上层收到数据后，SR发送方检查下一个可用于该帧的序号，如果**序号位于发送窗口内**，则发送数据帧;
	- 否则就像GBN一样，要么将数据缓存，要么返回给上层之后再传输。
- **收到了一个ACK**
	- 如果收到ACK，加入该帧序号在窗口内，则sR发送方将那个被确认的帧标记为**已接收**。
	- 如果该帧序号是窗口的下界(**最==左==边第一个窗口对应的序号**)，则窗口向前移动到具有最小序号的未确认帧处。
	- 如果**窗口移动了**并且有序号在窗口内的未发送帧，则发送这些帧。
- **超时事件**
	- 每个帧都有自己的定时器，一个超时事件发生后**只重传一个帧。** #注意
	- ![](attachments/Pasted%20image%2020221007200414.png)
		- #注意 不重发3号帧,3号帧还没有超时
##### 接受方
- **来者不拒** #注意
	- SR接收方将**确认一个正确接收的帧**而<mark style="background: #FF5582A6;">不管其是否按序</mark>。
	- **失序的帧将被<mark style="background: #FF5582A6;">缓存</mark>**，并返回给发送方一个该帧的确认帧【**收谁确认谁**】，直到==所有帧（即序号更小的帧）皆被收到为止，这时才可以将一批帧按序交付给上层==，然后向前移动滑动窗口。 #注意 
	- 如果收到了窗口序号外(**小于窗口下界**)的帧,就**返回一个ACK**。其他情况,就忽略该帧。 <!--SR:!2022-12-19,53,270-->


