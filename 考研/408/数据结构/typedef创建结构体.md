## typedef创建结构体
### typedef
- 定义struct Stu{......}
	- 使用需要**struct** Stu st;
- 使用typedef定义
```c++
typedef struct Student  
{  
int a;  
}Stu;
```
申请变量时可以Stu st; #注意 此时无需struct声明
- **typedef定义结构体数组类型**
```c++
typedef struct VertexNode
{
	char data;
	int weitht;
	struct EdgeNode * firstEdge;
}VertexNode,AdjList[MAX_VERTEX];
```
`AdjList adjlist;` 
等价于
`struct VertexNode adjlist[MAX_VERTEX];`