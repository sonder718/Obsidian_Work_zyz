# 基础类
## SQLiteOpenHelper
 Android为了让用户能够更加方便地管理数据库，丏门提供了一个 SQLiteOpenHelper帮助类，借助这个类就可以非常简单地对数据库进行创建。

       SQLiteOpenHelper是一个抽象类，这意味着如果想使用它的话，这就需要自己 创建一个类去继承他它就可以了。
————————————————
版权声明：本文为CSDN博主「撩得Android一次心动」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/indeedes/article/details/120046180
![](attachments/Pasted%20image%2020220622224325.png)
## Oncreate的调用
当db文件不存在即第一次创建时调用
![](attachments/Pasted%20image%2020220623013158.png)
UPDATE  sync ( LocalPath,mtimeLocal,sizeLocal) VALUES('/data/user/0/com.example.timetaker/files/新建笔记2.md','1655895753000','1620')