##### 20230113
- 在云服务器RTX 3080 Ti上初步尝试训练模型，为降低花销，只为测试可用性，进行了3个epoch,默认超参数
- 训练集为抽取1/16的Coco2017数据集，进行随机单应变换和光度失真
- ![](attachments/Pasted%20image%2020230113222822.png)
- ![](attachments/Pasted%20image%2020230113222843.png)
- `python3 match_homography.py --eval --superglue /root/autodl-tmp/output/train/default/weights/best.pt --input_homography assets/coco_test_images_homo.txt --input_dir assets/coco_test_images`
- ![](attachments/Pasted%20image%2020230113221619.png)
- ![](attachments/Pasted%20image%2020230113222200.png)
