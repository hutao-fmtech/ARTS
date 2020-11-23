 1. 常规操作

    - 同步时钟：`sudo apt-get install ntpdate`(安装ntp工具) , `ntpdate cn.pool.ntp.org`（同步服务器时间） , `hwclock --systohc`（写入硬件时钟）。
    - 通过`ctrl + r`键搜索过去敲过的命令。
    - 通过`find ./ -name xxx`查找文件所在位置。
    - 通过`find ./ -name xxx | xargs md5sum`确定文件是否一致。
    - 添加`-L`参数解决`find`不查找软连接目录问题。`find -L /directory/

2. `lsb_release -a` Ubuntu 查看发行版本