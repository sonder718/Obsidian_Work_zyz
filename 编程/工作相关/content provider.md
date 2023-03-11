# content provider
- android平台提供了Content Provider使一个应用程序的**指定数据集提供给其他应用程序**。其他应用可以通过**ContentResolve**r类从该内容提供者中获取或存入数据。
	- 这是**不同应用程序间共享数据的唯一方式**，因为android没有提供所有应用共同访问的公共存储区# Content Provider
- 在Android应用程序中，每个应用程序都有其私有的数据存储，ContentProvider提供了一种机制来共享这些数据。ContentProvider基于**Binder机制**实现了**进程间通信**，可以在不同的进程中访问数据。
	- 要使用ContentProvider进行跨进程通信，需要设置ContentProvider的exported属性为true
```java
ContentResolver resolver = getContentResolver();
//Uri对象指定了要访问的ContentProvider和数据表
Uri uri = Uri.parse("content://com.example.mycontentprovider/data");
//query()方法返回Cursor对象，可以使用Cursor对象获取数据
Cursor cursor = resolver.query(uri, null, null, null, null);
//向其他应用程序的ContentProvider插入数据
ContentValues values = new ContentValues();
values.put("name", "John");
values.put("age", 25);
resolver.insert(uri, values);

```# Content Provider
- 在Android应用程序中，每个应用程序都有其私有的数据存储，ContentProvider提供了一种机制来共享这些数据。ContentProvider基于**Binder机制**实现了**进程间通信**，可以在不同的进程中访问数据。
	- 要使用ContentProvider进行跨进程通信，需要设置ContentProvider的exported属性为true
```java
ContentResolver resolver = getContentResolver();
//Uri对象指定了要访问的ContentProvider和数据表
Uri uri = Uri.parse("content://com.example.mycontentprovider/data");
//query()方法返回Cursor对象，可以使用Cursor对象获取数据
Cursor cursor = resolver.query(uri, null, null, null, null);
//向其他应用程序的ContentProvider插入数据
ContentValues values = new ContentValues();
values.put("name", "John");
values.put("age", 25);
resolver.insert(uri, values);

```# Content Provider
- 在Android应用程序中，每个应用程序都有其私有的数据存储，ContentProvider提供了一种机制来共享这些数据。ContentProvider基于**Binder机制**实现了**进程间通信**，可以在不同的进程中访问数据。
	- 要使用ContentProvider进行跨进程通信，需要设置ContentProvider的exported属性为true
```java
ContentResolver resolver = getContentResolver();
//Uri对象指定了要访问的ContentProvider和数据表
Uri uri = Uri.parse("content://com.example.mycontentprovider/data");
//query()方法返回Cursor对象，可以使用Cursor对象获取数据
Cursor cursor = resolver.query(uri, null, null, null, null);
//向其他应用程序的ContentProvider插入数据
ContentValues values = new ContentValues();
values.put("name", "John");
values.put("age", 25);
resolver.insert(uri, values);

```# Content Provider
- 在Android应用程序中，每个应用程序都有其私有的数据存储，ContentProvider提供了一种机制来共享这些数据。ContentProvider基于**Binder机制**实现了**进程间通信**，可以在不同的进程中访问数据。
	- 要使用ContentProvider进行跨进程通信，需要设置ContentProvider的exported属性为true
```java
ContentResolver resolver = getContentResolver();
//Uri对象指定了要访问的ContentProvider和数据表
Uri uri = Uri.parse("content://com.example.mycontentprovider/data");
//query()方法返回Cursor对象，可以使用Cursor对象获取数据
Cursor cursor = resolver.query(uri, null, null, null, null);
//向其他应用程序的ContentProvider插入数据
ContentValues values = new ContentValues();
values.put("name", "John");
values.put("age", 25);
resolver.insert(uri, values);

```