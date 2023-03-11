![600](attachments/Pasted%20image%2020230223211132.png)
# 字节流
- Java中的字节流处理的最基本单位为单个字节，它通常用来处理**二进制数据**
	- 字节流在默认情况下是不支持缓存的，字节流在操作时本身**不会用到缓冲区**（内存），是文件本身直接操作的，这意味着每调用一次read方法都会请求操作系统来读取一个字节
- **InputStream(字节输入流)**
	- **FileInputStream** 该流用于**从文件读取数据**，它的对象可以用关键字 new 来创建。
		- `InputStream f = new FileInputStream("C:/java/hello");`
	- ! [[JAVA读取二进制文件指定位置的数据-FileInputStream,RandomAccessFile]]
- **OutputStream（字节输出流）**
	-  **FileOutputStream**
		- `OutputStream f = new FileOutputStream("C:/java/hello")`
- **BufferedInputStream**
	- 使用**内存缓冲区**以提高读取的效率,对一个已存在的流的链接和封装，通过对数据进行处理为程序提供功能强大、灵活的读写功能，例如`BufferedInputStream`（缓冲字节流）

# 字符流
- Java中的字符流处理的最基本的单元是**Unicode码元**（大小2字节），它通常用来处理文本数据，例如字符、字符数组或字符串
- **字符流适用于文本文件的读写**，`OutputStreamWriter`类其实也是借助`FileOutputStream`类实现的，故其构造方法是`FileOutputStream`的对象
- **Reader（字符输入流）**
	- **FileReader**类从InputStreamReader类继承而来。该类按字符读取流中数据。可以通过以下几种构造方法创建需要的对象。
	- ![](attachments/Pasted%20image%2020230225223315.png)
	- [[Java读取.txt文件的指定行，并确定该行的字符数]]
- **Writer（字符输出流）**
