1. 通配符：`wildcard`, `patsubst`, `nodir`
    ```makefile
    #sample Makefile

    objects := $(patsubst %.c,%.o,$(wildcard *.c))

    foo : $(objects)
        cc -o foo $(objects)
    ```
    > 首先使用“wildcard”函数获取工作目录下的.c文件列表；之后将列表中所有文件名的后缀.c替换为.o。这样我们就可以得到在当前目录可生成的.o文件列表。因此在一个目录下可以使用如下内容的Makefile来将工作目录下的所有的.c文件进行编译并最后连接成为一个可执行文件。

    > SRC = $(wildcard *.c)
    
    > 等于指定编译当前目录下所有.c文件，如果还有子目录，比如子目录为inc，则再增加一个wildcard函数，像这样：
    
    > SRC = $(wildcard *.c) $(wildcard inc/*.c)

2. VS Code 写 Makefile 时，提示`makefile missing separator.  Stop.`
   > On VS Code, just click the "Space: 4" on the downright corner and change it to tab when editing your Makefile.