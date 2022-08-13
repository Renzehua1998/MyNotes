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