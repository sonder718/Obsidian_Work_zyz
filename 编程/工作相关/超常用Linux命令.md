- [[linux下工具]]
- grep 命令
	- 用于**查找文件里符合条件的字符串**
		- ! 达梦数据库 一面
	- ![](attachments/Pasted%20image%2020230101154719.png)
- cat命令
	- 从第一行开始显示文本内容（适用于内容较少的）
	- ![](attachments/Pasted%20image%2020230101154828.png)
- ls命令
	- Linux ls（英文全拼： list directory contents）命令用于显示指定工作目录下之内容（列出目前工作目录所含之文件及子目录)。
	- ![](attachments/Pasted%20image%2020230101154914.png)
- free命令
	- 总体内存占用的查看
	- ![](attachments/Pasted%20image%2020230101155102.png)
- 解压文件命令
	- [Linux命令-RAR指令的安装与详细使用 - 简书 (jianshu.com)](https://www.jianshu.com/p/b89ef18855b3)
```bash
# 压缩文件 file1 和目录 dir2 到 test.tar.gz
tar -zcvf test.tar.gz file1 dir2
# 解压 test.tar.gz（将 c 换成 x 即可）
tar -zxvf test.tar.gz
# 列出压缩文件的内容
tar -ztvf test.tar.gz 
# 压缩文件
zip -r test.zip file
# 解压文件
unzip test.zip
```