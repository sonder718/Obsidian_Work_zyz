我们将约束处理技术整合到mtea中，以验证它们解决CMTOPs的能力。选择了一种约束处理技术，即可行性优先级。我们选择它是因为它可以很容易地嵌入到进化算法中，而不需要修改算法逻辑。可行性优先级的细节如图1所示。对于两个决策变量的选择，可行性优先原则将优先考虑它们的约束违背程度，其次是它们的目标函数值。通过约束处理t的积分

Feasibility 用FP表示
在实验中，我们将可行性优先级纳入遗传算法(GA)、MFEA[4]和AT-MFEA[7]中构建

[4] Abhishek Gupta, Yew-Soon Ong, and Liang Feng. 2016. Multifactorial Evolution:
Toward Evolutionary Multitasking. IEEE Transactions on Evolutionary Computation
20, 3 (2016), 343–357.

[7] Xiaoming Xue, Kai Zhang, Kay Chen Tan, Liang Feng, Jian Wang, Guodong
Chen, Xinggang Zhao, Liming Zhang, and Jun Yao. 2020. Affine Transformation-
Enhanced Multifactorial Optimization for Heterogeneous Problems. IEEE Transac-
tions on Cybernetics (2020), 1–15.

写注释:
FP-AT-MFEA:朱国强
FP-MFEA:张一卓
MFEA:张家齐
AT-MFEA:詹吉超

# 程序运行过程
![[attachments/FP-MFEA 2022-08-15 13.25.16.excalidraw]]
