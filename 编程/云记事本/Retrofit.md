- 基础
[Retrofit with Kotlin Coroutine in Android - GeeksforGeeks](https://www.geeksforgeeks.org/retrofit-with-kotlin-coroutine-in-android/)
- 全面
[Retrofit With Kotlin- The Ultimate Guide (codersee.com)](https://codersee.com/retrofit-with-kotlin-the-ultimate-guide/)
# tips
- 值得注意的是一定要导入相应的版本，不然会导致闪退，如
![](attachments/Pasted%20image%2020220624193541.png)
# 使用方式
### 设置返回的数据类
![](attachments/Pasted%20image%2020220624200108.png)
### 设置api
![](attachments/Pasted%20image%2020220624200136.png)
### 设置单例RetrofitHelper
- baseUrl必须结尾为/
![](attachments/Pasted%20image%2020220624200202.png)
### 开协程请求数据
![](attachments/Pasted%20image%2020220624200518.png)
# 对于` Call<ResponseBody>`类型不能是suspend
不然在这里总是闪退
![](attachments/Pasted%20image%2020220626014244.png)

![](attachments/Pasted%20image%2020220626014133.png)