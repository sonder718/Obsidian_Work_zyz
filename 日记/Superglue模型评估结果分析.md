##### 总体思路
- make-pairs能够对是否匹配进行红绿区分,因此目前采用室内scannet_sample_pairs_with_gt测试样本进行评估
- 考虑到使用Coco数据集进行训练,未来应尝试在Coco数据集上评估
##### outdoor模型情况
- ![](attachments/Pasted%20image%2020230113212511.png)
- ![](attachments/Pasted%20image%2020230113212530.png)

##### 默认情况
- 在云服务器RTX 3080 Ti上初步尝试训练模型，为降低花销，只为测试可用性，进行了3个epoch,默认超参数