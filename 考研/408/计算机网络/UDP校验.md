- **检验范围**
	- 检查首部和**数据部分**
		- ![IPv4数据报的格式](考研/408/计算机网络/IPv4数据报的格式.md#^g29e95)
- **检验方式** 
	- 将==检验和字段置为0==,添加伪首部
	- 分解数据报为16位字,用==反码==表示并求和,==再求反码==
		- 因此计算出0,不填充0
		- 有时需要添加0字段,使满足16位对齐
	- ![](attachments/UDP%E6%A0%A1%E9%AA%8C%202022-11-08%2023.52.56.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/UDP%E6%A0%A1%E9%AA%8C%202022-11-08%2023.52.56.excalidraw.md), and the [dark exported image](attachments/UDP%E6%A0%A1%E9%AA%8C%202022-11-08%2023.52.56.excalidraw.dark.svg)%%