1. 常用配置

```
git config --global alias.co checkout
git config --global alias.br branch
git config --global alias.ci commit
git config --global alias.st status
git config --global alias.unstage 'reset HEAD --'
git config --global alias.last 'log -1 HEAD'

```

---

2. 子模块 （Submodule）
- 远程子模块仓库URL发生变化同步： `git submodule sync --recursive`
- 同步远程仓库： `git submodule update --init --recursive`

