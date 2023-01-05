##### 论文信息
- [[2104.00680] LoFTR: Detector-Free Local Feature Matching with Transformers (arxiv.org)](https://arxiv.org/abs/2104.00680)
- [LoFTR: Detector-Free Local Feature Matching with Transformers (zju3dv.github.io)](https://zju3dv.github.io/loftr/?utm_source=catalyzex.com)
- [LoFTR: Detector-Free Local Feature Matching with Transformers - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/433665290)
##### 主要工作
- 使用[[Transformer]]
- 不是按顺序执行图像特征检测、描述和匹配
- 多尺度:粗略级别+精细级别
##### 摘要
- 本文提出了一种新的局部图像特征匹配方法。首先在粗粒度上建立图像特征的检测、描述和匹配，然后在精粒度别上细化亚像素级别的密集匹配，而不是依次执行图像特征检测、描述和匹配。
- 与使用cost volume来搜索对应关系的**密集方法**相比，本文借鉴Transformer使用了**自注意层**和**互注意层**来获得两幅图像的特征描述符。
- 这种方法提供的全局接受域使得能够在**纹理较少的区域**产生**密集匹配**
##### 结构
- ![](attachments/LoFTR--Detector-free%20local%20feature%20matching%20with%20transformers%202023-01-05%2018.02.09.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/LoFTR--Detector-free%20local%20feature%20matching%20with%20transformers%202023-01-05%2018.02.09.excalidraw.md), and the [dark exported image](attachments/LoFTR--Detector-free%20local%20feature%20matching%20with%20transformers%202023-01-05%2018.02.09.excalidraw.dark.svg)%%
##### 运行过程
- ![](attachments/LoFTR--Detector-free%20local%20feature%20matching%20with%20transformers%202023-01-05%2000.42.33.excalidraw.svg)
%%[🖋 Edit in Excalidraw](attachments/LoFTR--Detector-free%20local%20feature%20matching%20with%20transformers%202023-01-05%2000.42.33.excalidraw.md), and the [dark exported image](attachments/LoFTR--Detector-free%20local%20feature%20matching%20with%20transformers%202023-01-05%2000.42.33.excalidraw.dark.svg)%%