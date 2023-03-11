# 题目分析
设A 和B 是2 个字符串。要用最少的字符操作将字符串A 转换为字符串B。  
这里所说的字符操作包括  
(1)**删除**一个字符；  
(2)**插入**一个字符；  
(3)将一个字符**改为**另一个字符。  
将字符串A变换为字符串B 所用的最少字符操作次数也称为字符串A到B 的编辑距离，记为 D(A,B)。  
试设计一个有效算法，对任给的2 个字符串A和B，**计算出它们的编辑距离D(A,B)**。

# 朴素的想法
- 建立一个矩阵，用来存放子问题及原问题的编辑距离，并将递归边界在矩阵中填好
- ![](attachments/Pasted%20image%2020230227204334.png)
	- 把A中前i个字符变为B中前0个字符(null)需要i次
	- **状态转移方程**
		- **已知**`dp[i][0],dp[0][j]`
		- 计算`A[:1]转换为B[:1]`的最少次数
		- 当a[i]等于b[j]时
			- d[i][j] = d[i-1][j-1], 比如 fxy -> fay 的编辑距离等于 fx -> fa 的编辑距离
		- 当a[i]不等于b[j]时，d[i][j]等于如下 3 项的最小值：
			- `d[i-1][j]+ 1`
				- 删除a[i]或b中插入a[i]
					- `比如 fxy -> fab 的编辑距离 =  fx -> fab 的编辑距离 + 1`
			- `d[i][j-1]+ 1`
				- 删除 b[j]或者插入b[j]
					- 比如 fxy -> fab 的编辑距离 = fxyb -> fab 的编辑距离 + 1= fxy -> fa 的编辑距离 + 1`
			- `d[i-1][j-1]+ 1`
				- 将a[i]b[j]同时删除（等价于**交换**操作）
					- 比如 fxy -> fab 的编辑距离 = fxb -> fab 的编辑距离 + 1 = fx -> fa 的编辑距离 + 1
	- ![](attachments/Pasted%20image%2020230227212421.png)



```java
public class Main()
{
    int get_convert_mn(String m,String n)
    {
        if(m==null ||m.length()==0) return n.length();
        if(n==null || n.length()==0)return m.length();
        int [][]dp=new int [m.length()+1][n.length()+1];
        for(int i=0;i<m.length();i++)
        {
            dp[i][0]=i;//把m中前i个字符变为n中前0个字符需要i个操作数
        }
        for(int i=0;i<n.length();i++)
        {
            dp[0][i]=i;
        }
        for(int i=1;i<=m.length();i++)
        {
            for(int j=1;j<n.length();j++)
            {
                if(m.CharAt(i-1)==n.ChatAt(j-1))
                {
                    //字符相同,操作数不变
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=Math.min(dp[i-1][j]+1,dp[i][j-1]+1);
                    dp[i][j]=Math.min(dp[i][j],dp[i-1][j-1]+1)
                }
            }
        }
        return dp[m.length()][n.length()];
    }
    
}
```