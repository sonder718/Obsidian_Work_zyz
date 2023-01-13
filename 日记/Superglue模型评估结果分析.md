##### 总体思路
- make-pairs能够对是否匹配进行红绿区分,因此目前采用室内scannet_sample_pairs_with_gt测试样本进行评估
- 考虑到使用Coco数据集进行训练,未来应尝试在Coco数据集上评估
- 展示模型结果
[outdoor数据集模型评估结果](日记/outdoor数据集模型评估结果.md)
[indoor数据集模型评估结果](日记/indoor数据集模型评估结果.md)

- outdoor模型对应数据集
	- ![](attachments/Pasted%20image%2020230113215930.png)
	- ![](attachments/Pasted%20image%2020230113215917.png)
- outdoor数据集
	- `python3 match_homography.py --eval --superglue coco_homo --input_homography assets/outdoor_test_images_homo.txt --input_dir assets/outdoor_test_images`
	- ![](attachments/Pasted%20image%2020230113221425.png)
		- ![](attachments/Pasted%20image%2020230113221437.png)
- coco数据集
	- `python3 match_homography.py --eval --superglue /root/autodl-tmp/output/train/default/weights/best.pt --input_homography assets/coco_test_images_homo.txt --input_dir assets/coco_test_images`
	- ![](attachments/Pasted%20image%2020230113221619.png)
	- ![](attachments/Pasted%20image%2020230113222200.png)