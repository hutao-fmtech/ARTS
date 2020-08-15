- 查看 GCC 帮助：`gcc --help > gcc.help`, 英文帮助更加一手和准确。

#### GCC 常用参数
1. 指定输出名称：`gcc main.c -o main`
2. 展开宏（只执行预编译）：`gcc -E test.c -o test.i`
3. 执行预编译与编译：`gcc -S main.c -o main.S`
4. 保存中间文件（.i .S .o): `gcc -save-temps main.c`
5. 打印所有执行命令：`gcc -v main.c`
6. 添加宏定义：`gcc -DMY_MICRO`
7. 查看文件依赖：`gcc -M main.c`

### ld 参数
1. 输出 target 内存使用（FLASH、RAM）情况：-Wl,--print-memory-usage。
 > 注意：由于RAM的 data 段是静态初始化的值，数据也是存在 Flash 中的，所以 Flash 所占用空间，等于这里输出数值 + data的大小。
 > 可通过 size 命令查看 text、data、bss 段各占用的空间大小。