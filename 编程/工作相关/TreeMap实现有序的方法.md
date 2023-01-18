#### TreeMap的继承和实现
- 继承于AbstractMap
	- AbstractMap实现了Map接口，并实现了Map接口中定义的方法，减少了其子类继承的复杂度
- 实现的接口
	- Map接口
		- 可以包含着key--value形式的元素
	- Cloneable接口
		- 实现了clone()方法，可以被克隆
	- NavigableMap接口
		- 更强的元素搜索能力
	- Serializable接口
		- 支持序列化操作，可通过Hessian协议进行传输
- ![](attachments/TreeMap%E5%AE%9E%E7%8E%B0%E6%9C%89%E5%BA%8F%E7%9A%84%E6%96%B9%E6%B3%95%202023-01-17%2018.23.19.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/TreeMap%E5%AE%9E%E7%8E%B0%E6%9C%89%E5%BA%8F%E7%9A%84%E6%96%B9%E6%B3%95%202023-01-17%2018.23.19.excalidraw.md), and the [dark exported image](attachments/TreeMap%E5%AE%9E%E7%8E%B0%E6%9C%89%E5%BA%8F%E7%9A%84%E6%96%B9%E6%B3%95%202023-01-17%2018.23.19.excalidraw.dark.svg)%%