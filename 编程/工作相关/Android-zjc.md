### 1.  [recyclerview和listview区别](https://blog.csdn.net/sjh66655/article/details/115094494)
1、优化
ListView优化需要自定义ViewHolder和判断convertView是否为null。 而RecyclerView是存在规定好的ViewHolder。

2、布局不同
对于ListView，只能在垂直的方向滚动。而对于RecyclerView，他里面的LayoutManager中制定了一套可以扩展的布局排列接口，所以我们可以重写LayoutManager来定制自己需要的布局。RecycleView可以根据LayoutManger有横向，瀑布和表格布局

3、更新数据
recycleView可以支持在添加，删除或者移动Item的时候，RecyclerView.ItemAnimator添加动画效果，而listview不支持。而且RecyclerView有四重缓存，而ListView只有二重缓存。ListView和RecyclerView最大的区别在于数据源改变时的缓存的处理逻辑，ListView是"一锅端"，将所有的mActiveViews都移入了二级缓存mScrapViews，而RecyclerView则是更加灵活地对每个View修改标志位，区分是否重新bindView。

4、自定义适配器
ListView的适配器继承ArrayAdapter;RecycleView的适配器继承RecyclerAdapter,并将范类指定为子项对象类.ViewHolder(内部类)。

5、绑定事件不同
ListView是在主方法中ListView对象的setOnItemClickListener方法；RecyclerView则是在子项具体的View中去注册事件。

### 2.  [activity启动模式，有哪些不同](https://blog.csdn.net/NakajimaFN/article/details/117960446)[讲解视频](https://www.bilibili.com/video/BV1Fb4y1W7TX/?spm_id_from=333.337.search-card.all.click&vd_source=901f7f5955487658af7c988c17f4c3ff)
**Activity的启动模式分为四种。（standard、singleTop、singTask、singleInstance）;**
（1）standard模式
    特点：1.Activity的默认启动模式
              2.每启动一个Activity就会在栈顶创建一个新的实例。例如：闹钟程序
    缺点：当Activity已经位于栈顶时，而再次启动Activity时还需要在创建一个新的实例，不能直接复用。

（2）singleTop模式
    特点：该模式会判断要启动的Activity实例是否位于栈顶，如果位于栈顶直接复用，否则创建新的实例。 例如：浏览器的书签。
    缺点：如果Activity并未处于栈顶位置，则可能还会创建多个实例。

（3）singleTask模式
    特点：使Activity在整个应用程序中只有一个实例。每次启动Activity时系统首先检查栈中是否存在当前Activity实例，如果存在则直接复用，并把当前Activity之上所有实例全部出栈。例如：浏览器主界面。

（4）singleInstance模式
    特点：该模式的Activity会启动一个新的任务栈来管理Activity实例，并且该实例在整个系统中只有一个。无论从那个任务栈中    启动该Activity，都会是该Activity所在的任务栈转移到前台，从而使Activity显示。主要作用是为了在不同程序中共享一个Activity实例。

### 3. activity的生命周期
-   onCreate：表示Activity正在被创建。可在onCreate中做一些控件、数据的初始化工作
-   onRestart：表示Activity正在被重新启动。
-   onStart：表示Activity正在被启动，这时已经可见，但没有出现在前台无法进行交互。
-   onResume：表示Activity已经可见，并且处于前台。
-   onPause：表示Activity正在停止（可做一次保存状态停止动画等非耗时操作）。可做一些小数据的保存（但会影响下一个页面的打开速度）
-   onStop：表示Activity即将停止（可进行重量级回收工作）。
-   onDestroy：表示Activity即将被销毁。可做一些首尾工作，如数据保存。

### 4.  [四大组件 七大布局 五大存储](https://blog.csdn.net/shenggaofei/article/details/52450668)
四大组件分别为activity、service、content provider、broadcast receiver；
六大布局分别为LinearLayout、TableLayout、FrameLayout、RelativeLayout、GridLayout、AbsoluteLayout、ConstraintLayout；
五大存储分别为SharedPreferences、文件存储、SQLite数据库方式、内容提供器（Content provider）和网络。