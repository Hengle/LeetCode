# just my leet code

[![Build Status](https://travis-ci.org/wentaojia2014/LeetCode.svg?branch=master)](https://travis-ci.org/wentaojia2014/LeetCode)


## 进度

* 2018/07/05  144 / 829

主要在做Array，一共3页，做了有一半。

easy题目不说了，medium题目，很多自己只能想出通用解法，偶尔一些能想出优化的解法，看别人的最优解都是奇技淫巧。

* 2018/07/23 152/865
Array两页都做完了，剩下一页

* 2018/08/07 164/877

Array最后一页。 开始尝试使用Java环境(jdk10, idea)来做了。解题思想是通用的，语言只是工具而已。

## build

````shell

mkdir build

cd build

# if you have ninja
cmake .. -G Ninja

ninja 

#else use make
cmake ..

make -j4

````