##### 20230113-3epoch
- 在云服务器RTX 3080 Ti上初步尝试训练模型，为降低花销，只为测试可用性，进行了3个epoch,默认超参数
- 训练集为抽取1/16的Coco2017数据集，进行随机单应变换和光度失真
- ![](attachments/Pasted%20image%2020230113222822.png)
- ![](attachments/Pasted%20image%2020230113222843.png)
- `python3 match_homography.py --eval --superglue /root/autodl-tmp/output/train/default/weights/best.pt --input_homography assets/coco_test_images_homo.txt --input_dir assets/coco_test_images`
- ![](attachments/Pasted%20image%2020230113221619.png)
- ![](attachments/Pasted%20image%2020230113222200.png)
##### 20230113-10epoch
- 7分钟一个epoch
- ![](attachments/Pasted%20image%2020230113223951.png)
- ![](attachments/Pasted%20image%2020230113224553.png)
- 结束
	- ![](attachments/Pasted%20image%2020230113234644.png)
	- ![](attachments/Pasted%20image%2020230113234657.png)
- `python3 match_homography.py --eval --superglue /root/autodl-tmp/output/train/default/weights/best.pt --input_homography assets/coco_test_images_homo.txt --input_dir assets/coco_test_images`
- 相较于3轮的结果,的确取得了进步
	- 尝试对比
- ![](attachments/Pasted%20image%2020230113235055.png)
##### 20230113-10epoch-minmin
- 15分钟 10epoch
	- ![](attachments/Pasted%20image%2020230114001436.png)
- `python3 match_homography.py --eval --superglue /root/autodl-tmp/output/train/default/weights/best.pt --input_homography assets/coco_test_images_homo.txt --input_dir assets/coco_test_images`
	- ![](attachments/Pasted%20image%2020230114001942.png)
	- ![](attachments/Pasted%20image%2020230114002110.png)
	- ![](attachments/Pasted%20image%2020230114002122.png)