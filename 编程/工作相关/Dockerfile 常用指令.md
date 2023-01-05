#### 什么是Dockerfile
- Docker可以通过`Dockerfile`自动构建镜像，`Dockerfile`是一个包含多个指令的文档。如下
- ![](attachments/Pasted%20image%2020230101222959.png)
#### Dockerfile常用指令
##### FROM
- `FROM`命令用于初始化一个新的构建阶段，并为后续指令设置基础镜像
- ![](attachments/Pasted%20image%2020230101223051.png)
##### RUN
- `RUN`指令将在当前镜像之上的新层中执行命令，并且提交结果。在`docker build`时运行。
- ![](attachments/Pasted%20image%2020230101223114.png)
##### CMD
- Dockerfile使用`RUN`指令完成`docker build`所有的环境安装与配置，通过`CMD`指令来指示`docker run`命令运行镜像时要执行的命令。Dockerfile只允许使用一次`CMD`命令。使用多个`CMD`会抵消之前所有的命令，只有最后一个命令生效。一般来说，这是整个Dockerfile脚本的最后一个命令。
- ![](attachments/Pasted%20image%2020230101223137.png)
