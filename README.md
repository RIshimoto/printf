# printf
## 概要
42Tokyo[^1]の課題の一つ。tiny版printf。
[^1]:https://42tokyo.jp/

## 機能
printfについて詳しくは[こちら](https://www.mm2d.net/main/prog/c/printf_format-01.html)
### 変換指定子
cspdiuxX%

### フラグ
-0.*

### 使用した関数
malloc, free, write, va_start, va_arg, va_copy, va_end

## 実行
```
$ git clone https://github.com/RIshimoto/printf
$ cd printf
$ make all
$ ./printf
```
