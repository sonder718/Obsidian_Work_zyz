### 问题1：[try-catch-finally finally一定会执行么？finally和return执行顺序](https://blog.csdn.net/HandCream123/article/details/120115406)
答: finally一定会执行。

当return只在外层时则try-catch-finally顺序执行（有异常才执行catch）；

当try中有return时，程序执行try代码块中return之前（包括return语句中的表达式运算）代码，然后
	1.无异常：再执行finally中的代码块，最后执行try中return；外层（return 4；）不再执行，因为程序在try中已经return过了。
	2.有异常：执行catch，再执行finally，执行外层外层return。

当catch中有return时，程序先执行try代码块，如果遇到异常执行catch：
	1.出现异常：程序执行catch代码块中return之前（包括return中的表达式运算）代码；再执行finally中的代码块，最后执行catch中return；外层（return 4；）不再执行。
    2.没有异常：程序执行try代码块，再执行finally代码块，最后再（return 4；）。

当try和finally中有return时，程序执行try块中return之前（包括return语句中的表达式运算）代码：
	 1.出现异常：程序执行catch块；再执行finally块，因为finally块中有return所以提前退出；外层（return 4；）不再执行。顺序执行：try(未出现异常的代码)-catch-finally；
    2.没有异常：因为finally块中有return执行finally，顺序执行：try-finally；
       

当catch和finally中有return时，程序执行try块中代码：
	1.出现异常：程序执行catch块中return之前（包括return语句中的表达式运算）代码；再执行finally块，因为finally块中有return所以提前退出。而不再执行catch中的return。
	2.没有异常：执行try后跳过catch执行finally；

当try，catch和finally中有return时，程序执行try块中return之前（包括return语句中的表达式运算）代码：
	1.出现异常：执行catch块中return之前（包括return语句中的表达式运算）代码；再执行finally块，因为finally块中有return所以提前退出。
	2.没有异常：执行finally块，因为finally块中有return所以提前退出。


### 问题2：[java8（JDK1.8）新特性](https://blog.csdn.net/weixin_40294256/article/details/126338618)
1、Lamdba表达式
2、[函数式接口](https://so.csdn.net/so/search?q=%E5%87%BD%E6%95%B0%E5%BC%8F%E6%8E%A5%E5%8F%A3&spm=1001.2101.3001.7020)
3、[方法引用](https://so.csdn.net/so/search?q=%E6%96%B9%E6%B3%95%E5%BC%95%E7%94%A8&spm=1001.2101.3001.7020)和构造引用
4、Stream API
5、接口中的默认方法和静态方法
6、新时间日期API
7、OPtional

### 问题3：[线程池的种类](https://blog.csdn.net/bangyanya/article/details/123518146)
5种：
1. newCachedThreadPool
2. newFixedThreadPool
3. newSingleThreadExecutor
4. newScheduleThreadPool
5. newSingleThreadScheduledExecutor

### 问题4：[装箱和拆箱](https://blog.csdn.net/qq_43386944/article/details/119773230)
**装箱**就是  **自动将基本数据类型转换为包装器类型**；
**拆箱**就是  **自动将包装器类型转换为基本数据类型**。

### 问题5：[谈谈Integer i = new Integer(xxx)和Integer i =xxx;这两种方式的区别](https://blog.csdn.net/qq_43386944/article/details/119773230)
1）第一种方式不会触发自动装箱的过程；而第二种方式会触发；
2）在执行效率和资源占用上的区别。第二种方式的执行效率和资源占用在一般性情况下要优于第一种情况（注意这并不是绝对的）。