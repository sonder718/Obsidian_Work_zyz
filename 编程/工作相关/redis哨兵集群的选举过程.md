# 故障节点主观下线
- Sentinel集群的每一个Sentinel节点会定时对redis集群的所有节点发心跳包检测节点是否正常。如果一个节点在`down-after-milliseconds`时间内**没有回复Sentinel节点的心跳包**，则该redis节点被该Sentinel节点主观下线。
# 故障节点客观下线
- 当节点被一个Sentinel节点记为主观下线时,该Sentinel节点会询问其他Sentinel节点，**如果Sentinel集群中超过`quorum`数量的Sentinel节点**认为该redis节点主观下线，则该**redis客观下线**
- 如果客观下线的redis节点是从节点或者是Sentinel节点，则操作到此为止
# Sentinel集群选举Leader
- 首先需要从Sentinel集群中**选举一个Sentinel节点作为Leader**
	- 当一个Sentinel节点确认redis集群的主节点主观下线后，会请求其他Sentinel节点要求将自己选举为Leader。被请求的Sentinel节点如果没有同意过其他Sentinel节点的选举请求，则同意该请求(选举票数+1)，否则不同意
- 如果一个Sentinel节点**获得的选举票数达到Leader最低票数**(`quorum`和`Sentinel节点数/2+1`的最大值)，则该Sentinel节点选举为Leader；否则重新进行选举

# Sentinel Leader决定新主节点
1.  **过滤故障的节点**
2.  选择优先级`slave-priority`最大的从节点作为主节点，如不存在则继续
3.  选择**复制偏移量**（数据写入量的字节，记录写了多少数据。主服务器会把偏移量同步给从服务器，当主从的偏移量一致，则数据是完全同步）最大的从节点作为主节点，如不存在则继续
4.  选择`runid`（redis每次启动的时候生成随机的`runid`作为redis的标识）最小的从节点作为主节点