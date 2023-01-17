[try-catch-finally finally一定会执行么？finally和return执行顺序](https://blog.csdn.net/HandCream123/article/details/120115406)
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