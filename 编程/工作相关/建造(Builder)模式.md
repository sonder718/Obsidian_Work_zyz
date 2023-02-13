# 特点
- 建造者模式属于**对象创建型模式**
- 返回一个组装好的**完整产品**
	- 抽象工厂模式返回一系列相关的产品
- 它允许用户只通过指定复杂对象的类型和内容就可以构建它们，用户**不需要知道内部的具体构建细节**
- 增加新的具体建造者无须修改原有类库的代码，指挥者类针对抽象建造者类编程，系统扩展方便，符合“开闭原则”。

# 模式结构
![600](attachments/17079df27a8ac5e8~tplv-t2oaga2asx-zoom-in-crop-mark%204536%200%200%200.png)
-   Builder:抽象建造者
-   ConcreteBuilder：具体建造者
-   Director：指挥者
-   Product：产品角色

# 代码实现
## Director根据设定的Builder生产具体的Product
- ![600](attachments/Pasted%20image%2020230206230706.png)
## Director指挥生产具体产品
![500](attachments/Pasted%20image%2020230206230836.png)
## Builder作为抽象接口
- ![500](attachments/Pasted%20image%2020230206230937.png)
## ConcreteBuilder继承接口,具体生产产品
- ![](attachments/Pasted%20image%2020230206231027.png)