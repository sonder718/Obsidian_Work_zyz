# 为什么需要Kafka(卡夫卡)
- 随着用户的迅速增长，**所有的访问都直接通过SQL数据库使得它不堪重负**，不得不加上**缓存服务**以降低SQL数据库的荷载；为了理解用户行为，开始**收集日志**并保存到Hadoop上离线处理，同时把日志放在**全文检索系统**中以便快速定位问题；由于需要给投资方看业务状况，也需要把数据汇总到**数据仓库**中以便提供交互式报表
- **困难**:不同系统之间的复杂的数据同步
![](attachments/Kafka%202023-01-30%2020.47.16.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/Kafka%202023-01-30%2020.47.16.excalidraw.md), and the [dark exported image](attachments/Kafka%202023-01-30%2020.47.16.excalidraw.dark.svg)%%
# 用途
- **日志收集**：一个公司可以用Kafka可以收集各种服务的log，通过kafka以统一接口服务的方式开放给各种consumer，例如hadoop、Hbase、Solr等。
-   **消息系统**：解耦和生产者和消费者、缓存消息等。
-   **用户活动跟踪**：Kafka经常被用来记录web用户或者app用户的各种活动，如浏览网页、搜索、点击等活动，这些活动信息被各个服务器发布到kafka的topic中，然后订阅者通过订阅这些topic来做实时的监控分析，或者装载到hadoop、数据仓库中做离线分析和挖掘。
-   **运营指标**：Kafka也经常用来记录运营监控数据。包括收集各种分布式应用的数据，生产各种操作的集中反馈，比如报警和报告。
