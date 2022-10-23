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

## CQL

### 简介

Cypher语言，Cypher Query Language。专用查询语言、声明性模式匹配、SQL语法、简单可读

| CQL命令  | 用法                         |
| -------- | ---------------------------- |
| CREATE   | 创建节点，关系和属性         |
| MATCH    | 检索有关节点，关系和属性数据 |
| RETURN   | 返回查询结果                 |
| WHERE    | 提供条件过滤检索数据         |
| DELETE   | 删除节点和关系               |
| REMOVE   | 删除节点和关系的属性         |
| ORDER BY | 排序检索数据                 |
| SET      | 添加或更新标签               |

小括号`()`表示节点，箭头`-><-`表示关系（带方向），`[:]`表示标签

> 注意事项：使用中输入命令按shift+enter才能换行，Enter就会直接运行

### 常用命令

[官方文档](https://neo4j.com/docs/cypher-manual/3.5/clauses/)

主要语法：

```CQL
%名称:%标签 {%属性名:'%属性值'}
```

1. LOAD CSV：必须在指定目录下

```CQL
// 在%NEO4J_HOME%\import目录
load csv from 'file:///西游记.csv' as line
create (:西游 {name:line[0],tail:line[1],label:line[3]})
// (名称-一般为n:标签 {属性})
```

2. CREATE创建

> CQL中节点的名称不能相同，如m，n

```CQL
//创建简单节点
create (n)
//创建多个节点
create (n),(m)
//创建带标签和属性的节点并返回节点
create (n:person {name:'如来'}) return n

//使用新节点创建关系
CREATE (n:person {name:'杨戬'})-[r:师傅]->(m:person {name:'玉鼎真人'}) return
type(r)
//使用已知节点创建带属性的关系
match (n:person {name:'沙僧'}),(m:person{name:'唐僧'})
create (n)-[r:`师傅`{relation:'师傅'}]->(m) return r
// 检索关系节点的详细信息
match (n:person)-[r]-(m:person) return n,m

// 创建全路径
create p=(:person{name:'蛟魔王'})-[:义兄]->(:person{name:'牛魔王'})<-[:义兄]-
(:person {name:'鹏魔王'}) return p
```

节点间关系使用`()-[]->()`表示

3. MATCH查询：用于声明待匹配相应节点，可以指定标签（:后面带标签），可以指定属性（用{}括住键值对）

   匹配一个节点的全部相关内容，使用`match p=()-[]->()`形式返回`p`即可

4. RETURN返回：加入return才会显示在屏幕上，可以返回标签、属性——属性使用n.name，**id使用id(n)**

5. WHERE子句：用于过滤MATCH的结果，使用and、or等关键字

6. DELETE删除：用于删除**节点和关系**，有关系要**先删除关系**

7. REMOVE删除：用于删除节点和关系的**属性、标签**

```CQL
//删除属性
MATCH (n:role {name:"fox"}) remove n.age return n

//创建节点
CREATE (m:role:person {name:"fox666"})
//删除标签
match (m:role:person {name:"fox666"}) remove m:person return m
```

8. SET子句：向现有节点或关系添加新属性，更新属性值（使用`%属性名.%属性值=%设置值`）

   ```CQL
   MATCH (n:role {name:"fox"}) set n.age=32 return n
   ```

9. ORDER BY排序：后加排序参考，默认升序，可以加DESC子句降序排序（在后面加上即可）

10. UNION子句：

    ```CQL
    MATCH (n:role) RETURN n.name as name
    UNION
    MATCH (m:person) RETURN m.name as name
    MATCH (n:role) RETURN n.name as name
    UNION all
    MATCH (m:person) RETURN m.name as name
    ```

    - UNION：公共行组合并返回到一组结果中，**名称必须匹配**（列名称应该相同，列的数据类型应该相同——可以使用 as 子句进行重命名）**不重复**
    - UNION ALL：**重复**、**名称必须匹配**

11. LIMIT和SKIP子句：返回前几行，跳过前几行

12. NULL值：未定义值

13. IN操作符：用于**提供值的集合**——使用中括号

    ```CQL
    match (n:`西游`) where n.name in['孙悟空','唐僧'] return
    id(n),n.name,n.tail,n.label
    ```

14. INDEX索引：提供属性上的索引，以提高应用程序的性能

    ——为具有相同标签名称的所有节点的属性创建索引

```CQL
// 创建索引
create index on :`西游` (name)
// 删除索引
drop index on :`西游` (name)
```

15. UNIQUE约束：创建唯一约束，不可以有相同的属性避免重复

```CQL
//创建唯一约束
create constraint on (n:xiyou) assert n.name is unique
//删除唯一约束
drop constraint on (n:xiyou) assert n.name is unique
```

16. DISTINCT关键字：去重

    用法：`return distinct(n.name)`

其他命令可以自己在网站看下（待续）

### 常用函数

1. **字符串函数**：upper、lower、replace、substring
2. **聚合**：count、max、min、sum、avg
3. **关系函数**：startnode、endnode、id、type

### neo4j-admin

**都要先关闭服务！**

- 数据库备份：

  ```CQL
  cd %NEO4J_HOME%/bin
  neo4j install-service
  //关闭neo4j
  neo4j stop
  //备份
  neo4j-admin dump --database=graph.db --to=/neo4j/backup/graph_backup.dump
  ```

- 数据库恢复：

  ```CQL
  //数据导入
  neo4j-admin load --from=/neo4j/backup/graph_backup.dump --database=graph.db --
  force
  //重启服务
  neo4j start
  ```