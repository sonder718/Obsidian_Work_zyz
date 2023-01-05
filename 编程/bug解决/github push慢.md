[(57条消息) 为什么开了代理，git push 还是很慢或报错_Xavier Jiezou的博客-CSDN博客_git速度慢而报错](https://blog.csdn.net/qq_42951560/article/details/124332605)
```
//取消http代理
git config --global --unset http.proxy
//取消https代理 
git config --global --unset https.proxy

git config --global http.proxy socks5://127.0.0.1:7890
git config --global https.proxy socks5://127.0.0.1:7890

```