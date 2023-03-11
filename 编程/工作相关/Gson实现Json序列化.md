- Google提供的用来java对象和JSON数据之间进行映射的JAVA类库，可以将一个JSON字符转成一个java对象
- Gson与bean之间最重要的就是**属性和json的key要一一对应**，如果不对应要添加注释说明是json数据中的那个key，用==@SerializedName()==即可。
	- [Java bean是什么](Java%20bean是什么.md)
- ![600](attachments/Pasted%20image%2020230227001226.png)
```java
 RepostData repostData = new RepostData(); //实体类
 Gson gson = new Gson();
 java.lang.reflect.Type type = new TypeToken<RepostData>() {}.getType();
 RepostData jsonBean = gson.fromJson(JSONObject.toJSONString(testdetail), type);
```

