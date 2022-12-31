- **非持久连接**,
	- 每个网页元素对象(如JPEG图形、Flash等)的传输都需要**单独建立一个TCP连接**,如图6.12所示(第三次握手的报文段中捎带了客户对万维网文档的请求)。
	- 请求一个万维网文档所需的时间是**该文档的传输时间**(与文档大小成正比)加上**两倍往返时间RTT** (一个RTT用于TCP连接,另一个RTT用于请求和接收文档)。每个对象引用都导致2xRTT的开销,此外每次建立新的TCP连接都要分配缓存和变量,使万维网服务器的负担很重。
	- ![](attachments/Pasted%20image%2020221123155735.png)
- **持久连接**
	- 是指万维网服务器在发送响应后仍然保持这条连接,使同一个客户(浏览器)和该服务器可以继续在这条连接上传送后续的HTTP请求和响应报文,如图6.13所示。
	- #注意 ACK和HTTP请求==同时发送==
	- 非流水线与流水线
	- ![](attachments/HTTP%E7%9A%84%E6%8C%81%E4%B9%85%E8%BF%9E%E6%8E%A5%E5%92%8C%E9%9D%9E%E6%8C%81%E4%B9%85%E8%BF%9E%E6%8E%A5%202022-11-23%2016.01.41.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/HTTP%E7%9A%84%E6%8C%81%E4%B9%85%E8%BF%9E%E6%8E%A5%E5%92%8C%E9%9D%9E%E6%8C%81%E4%B9%85%E8%BF%9E%E6%8E%A5%202022-11-23%2016.01.41.excalidraw.md), and the [dark exported image](attachments/HTTP%E7%9A%84%E6%8C%81%E4%B9%85%E8%BF%9E%E6%8E%A5%E5%92%8C%E9%9D%9E%E6%8C%81%E4%B9%85%E8%BF%9E%E6%8E%A5%202022-11-23%2016.01.41.excalidraw.dark.svg)%%