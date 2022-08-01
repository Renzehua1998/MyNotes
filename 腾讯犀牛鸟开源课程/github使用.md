# 一、注册

https://github.com

使用邮箱地址注册，填写用户名、邮箱、密码，输入验证码。

选择工作种类、编程经验、使用计划，完成设置。

邮箱中确认即可。

# 二、使用git工具clone项目

http://git-scm.com

git官网下载git安装包，安装在本地。不在右键列表添加GUI。

在对应文件夹运行git bash。

配置git用户名和邮箱（提交时候的个人信息）。

可以配置ssh-key。

git clone对应的仓库链接。

# 三、fork官方仓库

为什么fork？我们没有提交权限，自己fork一个可以提交修改。

进入官方仓库，点击fork即可。

拉取到本地（clone、pull）。

# 四、拉取不同分支

进入仓库点击分支可以看到主分支、开发分支。

```bash
git clone -b <拉取的分支> <仓库地址>
```

# 五、提交代码

修改对应代码部分

```bash
git status
git add -a
git commit -m ""
git push <远程仓库别名> <远程仓库分支>
```

没配置ssh的话需要登录一下获取授权。

可以看到修改了什么地方。

# 六、贡献代码

pr： pull request 请求官方仓库拉取我们的代码。

点击pull request，创建新申请。没有冲突显示可以合并，检查无误编写请求信息，创建请求。

等待管理员通过即可。