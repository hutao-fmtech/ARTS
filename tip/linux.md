 1. 常规操作

    - 同步时钟：`sudo apt-get install ntpdate`(安装ntp工具) , `ntpdate cn.pool.ntp.org`（同步服务器时间） , `hwclock --systohc`（写入硬件时钟）。
    - 通过`ctrl + r`键搜索过去敲过的命令。
    - 通过`find ./ -name xxx`查找文件所在位置。
    - 通过`find ./ -name xxx | xargs md5sum`确定文件是否一致。
    - 添加`-L`参数解决`find`不查找软连接目录问题。`find -L /directory/

2. `lsb_release -a` Ubuntu 查看发行版本

3. 查看命令或函数所在的章节`man -f sleep` ，然后通过`man 3 sleep` 查看对应的章节的帮助。
    > 1、Standard commands （标准命令）
    > 2、System calls （系统调用）
    > 3、Library functions （库函数）
    > 4、Special devices （设备说明）
    > 5、File formats （文件格式）
    > 6、Games and toys （游戏和娱乐）
    > 7、Miscellaneous （杂项）
    > 8、Administrative Commands （管理员命令）
    > 9、 其他（Linux特定的）， 用来存放内核例行程序的文档。

4. 查看 so 的依赖关系：mips-linux-gnu-objdump -x libcurl.so | grep NEEDED