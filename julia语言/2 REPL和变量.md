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

