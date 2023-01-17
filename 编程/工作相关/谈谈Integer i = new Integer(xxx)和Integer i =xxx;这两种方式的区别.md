[谈谈Integer i = new Integer(xxx)和Integer i =xxx;这两种方式的区别](https://blog.csdn.net/qq_43386944/article/details/119773230)
1）第一种方式不会触发自动装箱的过程；而第二种方式会触发；
2）在执行效率和资源占用上的区别。第二种方式的执行效率和资源占用在一般性情况下要优于第一种情况（注意这并不是绝对的）。