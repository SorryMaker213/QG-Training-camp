# Git分布式版本控制工具

### 一、基础操作指令

* 创建新的本地仓库`git init`
* Git文件状态
  * Untracked：未跟踪
  * Unmodify：已入库但未修改
  * Modified：已修改但无其他操作
  * Staged：暂存
* **将文件从*工作区*添加到*暂存区***    `git add 文件名|通配符（.） `
* **将文件从*暂存区*提交到本地仓库**    `git commit -m '注释内容'`
* **查看文件修改状态**    `git status`
* **查看提交记录**    `git log [option]`
  * options
    * --all    显示所有分支
    * --pretty=oneline    将提交信息显示为一行
    * --abbrev-commit    使输出的commitID更简短
    * --graph    以图的形式显示
  * ` git-log`包括了以上参数
* 切换版本    `git reset --hard commitID`
  * commitID可通过`git-log`（或`git log`）查看
* 删除一个文件    `git rm [文件名]`
* 查看已删除的记录    `git reflog`  
* 查看修改内容    `git diff`
* 撤销在工作区的修改    `git checkout -- [文件名]`
* 撤销在暂存区的修改    `git reset HEAD <文件名>`
  * `HEAD`表示最新版本




### 二、分支管理

* 查看本地分支     ` git branch`
* 创建本地分支    ` git branch 分支名`
* **切换分支**    ` git checkout 分支名`
  * **创建并切换分支**    ` git checkout -b 分支名`
* **合并分支**    `git merge 分支名`
* 删除分支    *不能删除当前分支，只能删其他分支*
  * `git branch -d 分支名`    删除分支时需做检查
  * `git branch -D 分支名`    不做任何检查强制删除
* 查看分支合并图    `git log --graph`
* 解决冲突    *分支中对文件修改冲突*
  1. 处理文件中冲突的地方
  2. 将处理好的文件加入暂存区
  3. 提交到仓库



### 三、远程仓库

* 添加远端仓库    `git remote add <远端名称> <仓库路径>`
  * *远端名称默认    origin*
* 查看远端仓库    `git remote`
* 推送到远端仓库    `git push [-f] [--set-upstream] [远端名称] [本地分支名] [远端分支名]`
  * 如果远端分支名与本地分支名相同，可只写本地分支
  * -f：强制覆盖
  * `--set-upstream`：推送到远端并建立与远端分支的关联
  * 若当前分支已和远端分支关联，可省略分支名与远端名
* 从远端仓库克隆    `git clone <仓库路径> [本地目录]`
  * 本地目录若忽略，则会自动生成一个目录
* 从远程仓库抓取和拉取
  * 抓取    `git fetch [远端名称] [远端分支名]`
    * *将远端仓库中的修改抓取到本地，不会进行合并*
    * 如果没有指定后两个属性，则抓取所有分支
  * 拉取    `git pull [远端名称] [远端分支名]`
    * *将远端仓库中的修改拉到本地并自动合并*
    * 如果没有指定后两个属性，则抓取所有并更新当前分支



### 四、标签管理

- 为当前分支新建一个标签    `git tag <标签名>`

  - 默认为 `HEAD`，也可以指定一个commitID
  - 创建指定信息的标签    `git tag -a <标签名> -m "说明"`
    - `-a`指定标签名，`-m`指定说明文字

- 查看所有标签    `git tag`

- 推送某个标签到远端    `git push [远端名称] [标签名]`

- 推送全部本地标签    `git push [远端名称] --tags`

- 删除本地标签    `git tag -d <标签名>`

- 删除远端标签    `git push [远端名称] :reds/tags/<标签名>`

  



