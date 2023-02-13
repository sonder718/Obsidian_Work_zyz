### 新生代与老年代
- ![](attachments/aHR0cDovL3d3dy41MXN0ZS5jb20vaW1nL3NoYXJlLzIwMjAvMjAyMDAyLzIwMjAwMjI3MDEuanBn.png)
-   老年代比新生代生命周期长。
-   新生代与老年代空间默认比例 `1:2`
-   HotSpot 中，Eden 空间和另外两个 Survivor 空间缺省所占的比例是：`8:1:1`。
-   几乎所有的 Java 对象都是在 Eden 区被 new 出来的，Eden 放不了的大对象，就直接进入老年代了。

