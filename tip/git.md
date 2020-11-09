<!--
 * @Author: your name
 * @Date: 2020-08-19 09:38:21
 * @LastEditTime: 2020-09-09 11:45:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /ARTS/tip/git.md
-->
1. 常用配置

```
git config --global alias.co checkout
git config --global alias.br branch
git config --global alias.ci commit
git config --global alias.st status
git config --global alias.unstage 'reset HEAD --'
git config --global alias.last 'log -1 HEAD'
git config --global pull.rebase true
git config --global core.quotepath false
```

---

2. 子模块 （Submodule）
- 远程子模块仓库URL发生变化同步： `git submodule sync --recursive`
- 同步远程仓库： `git submodule update --init --recursive`
- 先 push 子模块到远程，再 push 主仓库到远程。
- 同步场景
> 1. `git clone` 包含子模块的项目时未使用 `git clone remot-url --recurse-submodules`时，可以使用 `git submodule update --init` 同步。

- 新增子模块

---

3. 远程分支管理
- 查看本地分支与远程分支跟踪关系 `git branch -vv`
- 查看所有分支状态 `git branch -a -vv`
- 跟踪远程分支 `git branch -u origin/hutao`, 或者 `git branch --set-upstream-to origin/hutao`(跟踪远程 `hutao`分支)
- 取消跟踪远程分支 `git branch --unset-upstream`
- 查看远程分支状态 `git remote show origin`
- 同步远程分支状态到本地（如新增、删除操作）`git remote prune origin`
- 删除远程分支 `git push origin :delet_branch`，既推送一个空分支到远程。

---

4. 文件跟踪操作
- 取消已跟踪的文件：`git rm --canched <filie-name> ` 或 `git rm -r --cached <dir>`。（注：此操作回删除文件，同步到远程分支后，远程分支也会取消跟踪）


5. git status 中文无法显示解决 `git config --global core.quotepath false`

6. 克隆远程指定分支：`git clone remote-branch  remote-reop-url`

7. 解决`git status`中文乱码`git config --global core.quotepath false`

8. 删除未跟踪的文件 `git clean -df`，（返回到某个节点，未跟踪文件的删除）
    > git clean 参数
    >   -n 不实际删除，只是进行演练，展示将要进行的操作，有哪些文件将要被删除。（可先使用该命令参数，然后再决定是否执行）
    >   -f 删除文件
    >   -i 显示将要删除的文件
    >   -d 递归删除目录及文件（未跟踪的）
    >   -q 仅显示错误，成功删除的文件不显示