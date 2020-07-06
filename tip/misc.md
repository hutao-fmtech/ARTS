##### CentOS ssh 超时设置
参考[链接](http://einverne.github.io/post/2017/05/ssh-keep-alive.html)

- 方法1：设置服务端
```shell script

# 1. 设置超时参数
vi /etc/ssh/sshd_config
    ClientAliveInterval 30 #每隔30秒给客户端发一个心跳
    ClientAliveCountMax 60 #最大允许客户端60次没有应答，也就是30分钟，

# 2. 重启超时服务

systemctl restart sshd

```

- 方法2：设置客户端

```shell script
# 1. 设置超时参数
vi /etc/ssh/sshd_config
    ServerAliveInterval 30 #每隔30秒给服务端发一个心跳
    ServerAliveCountMax 60 #如果发送60次，依然无应答则断开
```

