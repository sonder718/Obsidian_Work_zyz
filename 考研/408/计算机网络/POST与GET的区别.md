- **post和get的区别：**
-   都包含请求头请求行，post多了**请求body**。
-   get多用来查询，**请求参数**放在==url==中，直接就可以在URL中看到内容.不会对服务器上的内容产生作用。post用来**提交**，如把账号密码放入body中,用户无法直接看到.
-   GET提交的数据长度是有限制的，因为URL长度有限制，具体的长度限制视浏览器而定。而POST没有。