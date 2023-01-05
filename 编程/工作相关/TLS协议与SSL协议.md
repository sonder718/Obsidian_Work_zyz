##### 为什么需要
- HTTP在传输数据时使用的是**明文是不安全**的，为了解决这一隐患网景公司(Netscape)推出了**SSL安全套接字协议层。**
- SSL是基于HTTP之下TCP之上的一个协议层，是基于HTTP标准并**对TCP传输数据时进行加密**，所以HPPTS是==HTTP+SSL/TCP==的简称，Https默认使用端口443。
##### SSL协议
- Secure Socket Layer，安全套接字层。SSL是Netscape开发的位于可靠的面向连接的网络层协议(如TCP/IP)和应用层协议之间的一种协议。
- SSL为应用程序提供加密数据通道，它**采用了RC4、MD5以及RSA等加密算法，使用40 位的密钥**，适用于商业信息的加密。
- ![](attachments/Pasted%20image%2020230101145730.png)
- ![](attachments/Pasted%20image%2020230101145745.png)
##### TLS协议
- IETF对SSL3.0进行了标准化，并添加了少数机制(但是几乎和SSL3.0无差异)，标准化后的IETF更名为TLS1.0，可以说**TLS就是SSL的新版本3.1**
- ![](attachments/Pasted%20image%2020230101145949.png)
##### TLS下的TCP握手连接
- 服务器端进行非对称加密RSA,生产公钥与私钥,将公钥明文发给客户端
- 客户端生成对称加密的密钥,将密钥用公钥加密
- 服务器端将密钥的密文用私钥解密,得到密钥
- 从而客户端和服务器端可以进行对称加密AES通信
- ![](attachments/TLS%E5%8D%8F%E8%AE%AE%E4%B8%8ESSL%E5%8D%8F%E8%AE%AE%202023-01-01%2015.09.37.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/TLS%E5%8D%8F%E8%AE%AE%E4%B8%8ESSL%E5%8D%8F%E8%AE%AE%202023-01-01%2015.09.37.excalidraw.md), and the [dark exported image](attachments/TLS%E5%8D%8F%E8%AE%AE%E4%B8%8ESSL%E5%8D%8F%E8%AE%AE%202023-01-01%2015.09.37.excalidraw.dark.svg)%%