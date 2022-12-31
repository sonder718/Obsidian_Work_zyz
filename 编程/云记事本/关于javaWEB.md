作者：cess  
链接：https://www.zhihu.com/question/509707651/answer/2297232337  
来源：知乎  
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。  
  

**JavaWEB** 主要让你学习一个web项目到底怎么是回事，知道CS模式，服务器大致逻辑。Servlet Filter Listener 都是什么作用，怎么写；项目分层：控制层、业务层、持久层，分层后逻辑清晰；最终要以网页的形式返给客户，就有 jsp，要写 jsp 就得懂点前端知识，cookie session，网页[异步通信](https://www.zhihu.com/search?q=%E5%BC%82%E6%AD%A5%E9%80%9A%E4%BF%A1&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A%222297232337%22%7D)需要的 ajax json。学了这些就事实上能写项目了，但这个开发效率太低，属于什么都得从头自己弄，所以就诞生了框架。前些年流行的就是 SSM，包括SpringMVC、Spring、Mybatis。

  

**Spring** 是核心，其他框架都得在它基础上运行，它本质是个容器，通过XML配置文件可以配置bean对象，或者通过注解如 @Component，@Configuration + @Bean 等注解，告知程序启动时要给哪些类创建对象，并放入容器。两个重要概念 IOC 跟 AOP。

IOC 就是既然对象都有了，你用的时候就不用 new 了，写个注解，程序跑起来框架解析注解后就自动反给你这个对象。举个例子，你写了一个 XxxService 类，其他地方要使用这个类，现在只需要在 XxxService 类上添加 @Service 注解，使用的地方写上 @Autowired（或者 @Resource ） XxxService xxxService; 就可以使用了。你可能觉得 new XxxService 并不复杂啊，但通过注解从容器中拿到的都是同一个对象，而你每次 new 的都是不同的对象，显然一个 Service 类只需要一个对象就够了，这就节省了不必要的内存占用。再者可能 new 一个对象过程很复杂，XxxService 里面的属性又是其他复杂对象，复杂对象里又有对象，这种情况注解的优势就很明显了。并且通过注解你很可能拿到的是 XxxService 的代理对象，代理对象相比于 XxxService 是有增强的。

AOP 面向切片，主要是把一段代码嵌入到需要插入的方法的指定位置，是通过动态代理实现的。提高了复用性，也好扩展，还把其中最重要的事务切面给你准备好了。前面提到 XxxService ，如果我需要在这个类中的方法A中切入一段鉴权代码，可以在一个切面类中写一个切入点方法，通过注解指明切到 XxxService 的方法A的某个位置（可以指明符合条件的多个位置），Spring 在通过反射创建 XxxService 实例对象后，在初始化时会创建一个代理对象，这个代理对象的方法A就已经切入了鉴权代码。这样的好处就是，我在写方法A时完全不需要考虑[鉴权](https://www.zhihu.com/search?q=%E9%89%B4%E6%9D%83&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A%222297232337%22%7D)的代码，并且要切入到哪里，以及鉴权代码有变动，都完全符合开闭原则。

  

**SpringMVC** 可以简单认为把 JavaWEB 控制层往前的都给替了（其实不是，但初期了解没啥问题）。提出了一个前端控制器 DispatcherServlet，它会拦截所有请求，根据请求找到对应的处理方法来处理，你写的 Controller 方法只要标注是处理哪个请求就行，此外你写起来会简便很多，你要哪些参数，参数列表写个名字就直接解析给你（有些要配合注解）。还提出了model view controller三块，这样拆开更明确。

  

**Mybatis**（学这个之前务必要先掌握 JDBC 相关知识）是一个半自动持久层 ORM 框架。前面提到的持久层干的事情就是对数据库的增删改查，Mybatis 框架就是简化这一层而存在的。先回顾一下使用 JDBC 步骤：1 获取连接，2 创建PreparedStatement对象，3 编写SQL语句，4 预编译参数，5 执行语句，6 封装处理结果。大家可以发现，这6步中除了 SQL 语句外，其他部分基本上差不多。所以 Mybatis 做的事情实际上就是把这些共性的部分抽取出来，写成[通用代码](https://www.zhihu.com/search?q=%E9%80%9A%E7%94%A8%E4%BB%A3%E7%A0%81&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A%222297232337%22%7D)，我们实际上只要写 SQL 语句就可以了。这里要提到 ORM（对象关系映射），意思是建立起 Java对象与数据库表之间的对应关系，一张表对应一个 Java 对象，开发时通常将这一类对象放在一个 Entity 文件夹中，这样上面6这里，查询结果就知道封装成什么了。所以大家可以发现使用 Mybatis 只在持久层写了一个 XxxDao 接口，剩下就在写其对应的 XxxDao.xml 映射文件（主要就是SQL语句 以及 resultMap 之类的东西），显然框架在程序运行起来后，根据 XxxDao.xml 文件 自动生成了 XxxDao 的实现类。

这里要提一个东西叫 Mybatis-plus，它是在几乎不改变 Mybatis 的情况下全面的增强，比如：只需要把数据库表建立起来，它就会根据这些表自动生成对应的 控制层、业务层、持久层代码，支持主键自动生成（new 一个 Entity 对象，显然 主键 id 是null， 将其 insert 进[数据库](https://www.zhihu.com/search?q=%E6%95%B0%E6%8D%AE%E5%BA%93&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A%222297232337%22%7D)，你会发现这个对象的 id 自动就有了）、分页插件等等。

  

**SpringBoot** 是框架的框架，在前面之上又封装了一层，作用就是进一步简化开发。提出了约定大于配置，前面 SSM 中你得写大量的配置文件，SpringBoot 直接给你一套默认配置，并且你maven 导哪个包，对应的配置会自动生效，你只需要写你需要改的一小部分配置，就会自动替换掉默认配置。此外还增加了指标监控 等功能。