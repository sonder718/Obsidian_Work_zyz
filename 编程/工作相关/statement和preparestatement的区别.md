Statement和PreparedStatement是Java中用于执行SQL查询语句的API之一，两者之间有以下区别和联系：  
  
区别：  
- 语法不同：PreparedStatement可以使用预编译的SQL，只需要发送一次SQL语句，后面只要发送参数即可，公用一个SQL语句，而Statement只能使用静态的SQL。  
- 效率不同：PreparedStatement使用了SQL缓冲区，效率要比Statement高。  
- 安全性不同：PreparedStatement可以防止SQL注入攻击，而Statement容易受到SQL注入攻击。  
  
联系：  
- PreparedStatement接口继承自Statement接口，因此两者都是用来执行SQL查询语句的API之一。