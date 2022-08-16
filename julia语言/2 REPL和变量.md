# REPL使用

**运行模式**

常规模式：可以直接输入julia语法。

```julia
a=10 #回车
pringkln(a) #回车
```

帮助模式：按"?"进入，查看帮助文档。也可以在正常模式下按@doc宏来查看帮助文档。

```julia
? # 回车
println
# 或
@doc println
```

shell模式：按";"进入，可以运行shell命令。

package模式：按"]"进入，可以增加删除各种库。

```julia
; # 回车
add GR
rm GR
# 或
using Pkg
Pkg.add("GR")
Pkg.rm("GR")
```

```julia
Pkg.installed() # 查看当前包和它们的版本（貌似已经被弃用了）
Pkg.status()
```

# 变量和数据类型

## 变量

- 动态语言，无需声明之间赋值。
- 字符串、整型、浮点数等等。
- 支持中文，甚至中文变量名。
- 支持Unicode字符\alpha，按tab可以转换成α。
- 变量名小写、类型模块首字母大写、驼峰式命名（不鼓励下划线）、函数和宏不使用下划线、修改参数函数结尾使用`!`，表示函数会修改参数内容。

## 整型和浮点

操作：

- typeof()返回数据类型，可以使用ans返回上次运行的结果。

- supertype()返回父类型：Any、Number、Real、Integer、Signed、Int64.

- subtypes()返回所有子类型。

- sizeof()返回数据占据的**字节数**。Int64：8。
- bitstring可以转换为二进制字符串。
- typemin()\typemax()，返回当前数据类型最大最小值。
- eps()返回数据的精度（用在浮点数，考察某个数用浮点数表示的精度）

数据类型：

1. 整型：Int8、UInt8……注意Bool型为true和false，但占据8个bit（一字节）。默认为Int64。
2. 浮点型：Float16、32、64（半、单精度、双精度）——默认双精度。

输入Int、UInt查看你自己系统的类型，或者输入Sys.WORD_SIZE查看。

十六进制：Int十进制、UInt十六进制。0x-16 0b-2 0o-8，使用Int64直接转为十进制。

有符号数：直接加负号。

浮点数表示：1e10、2e-3、1f-5（32位）。

支持任意精度计算，使用BigInt、BigFloat等进行扩位。——BigFloat可以调节精度和舍入方式。

## 复数

使用im代表复数中的i或j

x=1+2im——直接支持加减乘除乘方等等。实数乘复数可以省略乘号。

也可以令x=1，y=2，z=complex(x,y)

运算顺序：2/5im表示2/(5*im)。

支持三角函数运算sim()、cos()；指数exp()；取模abs()；real取实部，imag取虚部，angle取相角。

对复数开根号，如-1，sqrt(-1+0im)

## 分数

使用双斜线1//2表示分数。

numerator取分子、denominator取分母、float转换为小数。isequal()判断两个数是否相等。

## 字符串

**用单引号表示字符**，可以用Int查看ASCII码值，Char返回原字符串，用'\u21'表示Unicode，可以输出对应字符。

**用双引号表示字符串**，用方括号表示索引，使用[1:4]截取对应位置字符串。

完整支持Unicode和ASCII，使用`\u`，`\U`来转义，但是UTF-8中字符是变长的，有时索引某个字符中的一部分会报错。

使用firstindex()、lastindex()来索引字符，for i in 1:10。也可以类似于Python一样，for i in str。

两个字符串操作：string(x,y)做拼接，也可以使用`*`做拼接。

特殊操作：插值操作符——取值（也可以取出数字型变量的值）。$x表示获取x字符串内部的值。

^表示多个相同字符串拼接，lowercase、uppercase大小写转换。

replace替换对应位置字符或字符串。

```julia
replace("duhjfhew", 'd' => 'e')
```

startwith()查看字符串是否以某个子串开头。

strip()去掉字符串前面的空格，split、join方法和Python相似。

多行字符串使用三个双引号来引用。

数学运算：

- 按照字符编码表中的排列顺序、按照第一个字符比较，相同则比较后一个字符。
- `findfirst(isequal('x'),"xhaih",1)`，第一个出现某字符的位置，从第三个参数索引处开始。
- occursin表示前一个字符串是否是后一个的子串。
- repeat类似于^。
- join，第二个参数表示前面字符串连接使用的参数，第三个参数表示最后两个字符串连接所用的参数。

正则表达式：r"(字符串)" 类型为Regetx。支持使用occursin或match（返回匹配的字符）等方法。

## 数据结构

### 元组

圆括号括住，不可更改，使用方括号表示索引（从1开始）。

- 使用length表示长度、使用x[end]表示最后一个元素。
- 使用x[2:end]进行截取。
- 数据类型可多样：浮点、整型、字符串。
- 使用类似字典的格式定义：x=(a=1,b=2)，使用x.a索引。

### 字典

使用Dict()声明，键值对之间使用"=>"。

- 使用dic.count查看键值对的值。
- dic.keys，dic.vals获取键和值，默认显示16个。
- dic[key]进行索引。
- 可以使用Dict关键字将Array（Array中的Tuple）转换成字典。
- 或者用两个Array分别对应键和值，使用Dict(zip(keys,values))。
- Dict()创建新字典。dic["1"] = 2直接建立项目，dic = Dict(String, Int64)指定类型。
- 遍历：for (k,v) in dic 或 for v in values(dic)。
- get方法查找对应key的值，没有返回指定参数；使用delete删除某一对元素；fieldnames(typeof(dic))。

### 集合

使用Set()关键字定义声明。

- 里面参数可以是数组，或者用步进的方式表示[1:2:10]。
- 使用in关键字查看集合中是否有某元素。
- 元素不重叠。
- intersect(A,B)表示交集，union(A,B)表示并集。
- 非Set也可以进行交/或操作。

