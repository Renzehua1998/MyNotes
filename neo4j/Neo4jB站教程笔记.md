# Neo4j B站教程笔记

绪论：基于图的关系数据库

- 简介
- 环境搭建
- CQL语法
- 与SpringBoot结合

## 简介

### 图数据库定义

应用场景：海量复杂关系数据的运算、存储

NoSQL数据库，基于图构成的（graph）——包含大量的结构化，半结构化和非结构化的连接数据

分类：

1. 键值(key/value)数据库（查找块；无结构）

2. 列存储数据库（查找快、扩展方便；功能受限）

3. 文档型数据库（数据结构要求不严格；难以查找）

4. 图数据库（允许图算法；有时会涉及整个图不便于分布式存储）

对比：

- 关系型数据库中不同表使用外键进行关联
- 图数据库中使用点和边建立关系，无需join操作

### Neo4j优势

- 最先进的图数据库之一
- 属性图模型（Property graph model）
- 专属查询语言 Cypher

——有很多优点

### 数据模型

- 图论基础：节点和边——实体和关系
- 属性图模型：实体和关系都有属性，属性使用键值对表示

label：支持多标签（多种身份）

关系：单向、双向

属性：键值对，可以被索引和约束

**Neo4j Browser：**

浏览器控制台，可以通过Neo4j、bolt等协议连接数据库，web端口默认7474，数据库服务端口7687

### 使用场景

- 欺诈检测
- 实时推荐引擎
- **知识图谱**
- 主数据管理
- 供应链管理
- 网络运营
- 身份访问管理
- ……

## 环境搭建

https://neo4j.com/download-center/

- 企业版：分布式收费
- 社区版：Win+Linux，解压即可使用（注意版本）——4.0以上版本要保证JVM环境是jdk11
- desktop

### 社区版Windows安装

Windows下解压到某个文件夹下即可：**路径不能有中文**

——bin中有运行脚本、CQL语句脚本；certificates里是身份认证；config配置；data数据文件；import导入csv utf-8文件；lib一些jar包；logs日志；plugins一些插件；run运行。

在对应目录下执行

```bash
# 将Neo4j作为控制台应用程序运行 
<NEO4J_HOME>\bin\neo4j console 
# 将Neo4j作为服务使用进行安装 
<NEO4J_HOME>\bin\neo4j install-service
```

> console: 直接启动 neo4j 服务器
>
> install-service | uninstall-service | update-service ： 安装/卸载/更新 neo4j 服务
>
> start/stop/restart/status: 启动/停止/重启/状态
>
> -V 输出更多信息

注：data里面有store_lock，数据锁，保证使用中无法对数据进行操作

- 第一次需要更改密码

- 刚进去是一个入门手册，可以运行一下命令进行学习
- 每次节点id自动分配，支持重复数据，也可以自己去重（建立唯一标识）

### 社区版docker安装

注意对端口的开放暴露

- 7474 for HTTP. web

- 7473 for HTTPS.

- 7687 for Bolt. 连接

拉取镜像

```bash
docker pull neo4j:3.5.22-community # 旧版
docker pull neo4j:4.4.11-community # 最新版
```

执行镜像命令

```bash
docker run -d -p 7474:7474 -p 7687:7687 --name neo4j \
  -e "NEO4J_AUTH=neo4j/123456" \ # 指定密码
  -v /usr/local/soft/neo4j/data:/data \ # 指定挂载位置
  -v /usr/local/soft/neo4j/logs:/logs \
  -v /usr/local/soft/neo4j/conf:/var/lib/neo4j/conf \
  -v /usr/local/soft/neo4j/import:/var/lib/neo4j/import \
neo4j:4.4.11-community # 指定版本号
```

### Desktop安装

- 官网下载对应版本
- 下载完成后会提供校验码，傻瓜式安装
- 封装到客户端里面，可以自定义创建版本
- 支持连接远程服务
- 指定对应版本环境start，同样的使用方法