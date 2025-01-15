/*
# BABTWR - Tower of Babylon

## 题面翻译

题目：     
有$n$种长方形方块，每种有无限个，第i种方块的三边边长是$x_{i}$,$y_{i}$,$h_{i}$（y是高，x是宽，z是长，但是这个不用管）。对于每一个方块，你可以任意选择一面作为底，这样高就随着确定了。
他们想要用堆方块的方式建尽可能高的塔。问题是，只有一个方块的底的两条边严格小于另一个方块的底的两条边，这个方块才能堆在另一个上面。这意味着，一个方块甚至不能堆在一个底的尺寸与它一样的方块的上面。要求计算出这个塔可以建出的最高的高度。

输入：       
输入包含至少一组数据，每组数据的第一行是一个整数$n$($n$<=30)，表示方块的种类数。      
这组数据接下来的$n$行，每行有三个整数，表示$x_{i}$,$y_{i}$,$z_{i}$。 输入数据会以$0$结束。

输出：       
对于每组数据，输出一行，表示在这个数据中，可搭出的塔最高的高度。

## 题目描述

![](https://cdn.luogu.com.cn/upload/vjudge_pic/SP100/7a939db1eae2f77be9ce3ec4d462683703792d71.png)Apart from the Hanging Gardens the Babylonians (around 3000-539 b.c.) built the Tower of Babylon as well. The tower was meant to reach the sky, but the project failed because of a confusion of language imposed from much higher above.

For the 2638th anniversary a model of the tower will be rebuilt. _n_ different types of blocks are available. Each one of them may be duplicated as many times as you like. Each type has a height _y_, a width _x_ and a depth _z_. The blocks are to be stacked one upon eachother so that the resulting tower is as high as possible. Of course the blocks can be rotated as desired before stacking. However for reasons of stability a block can only be stacked upon another if _both_ of its baselines are shorter.

## 输入格式

The number of types of blocks _n_ is located in the first line of each test case. On the subsequent _n_ lines the height _y $ _{i} $_ , the width _x $ _{i} $_  and the depth _z $ _{i} $_  of each type of blocks are given. There are never more than 30 different types available.

There are many test cases, which come one by one. Input terminates with n = 0.

**Edited:** You can assume that max(_x $ _{i} $_ , _y $ _{i} $_ , _z $ _{i} $_ ) <= 2500.

## 输出格式

For each test case your program should output one line with the height of the highest possible tower.

## 样例 #1

### 样例输入 #1

```
5
31 41 59
26 53 58
97 93 23
84 62 64
33 83 27
1
1 1 1
0
```

### 样例输出 #1

```
342
1
```

*/

#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 30 + 5;
const int MAXV = 500 + 5;

int d[MAXN][3];
int x[MAXN], y[MAXN], z[MAXN];

int babylon_sub(int c, int rot, int n) {
    if (d[c][rot] != -1) {
        return d[c][rot];
    }
    d[c][rot] = 0;
    int base1, base2;
    if (rot == 0) {
        base1 = x[c];
        base2 = y[c];
    }
    if (rot == 1) {
        base1 = y[c];
        base2 = z[c];
    }
    if (rot == 2) {
        base1 = x[c];
        base2 = z[c];
    }
    for (int i = 0; i < n; i++) {
        if ((x[i] < base1 && y[i] < base2) || (y[i] < base1 && x[i] < base2))
            d[c][rot] = std::max(d[c][rot], babylon_sub(i, 0, n) + z[i]);
        if ((y[i] < base1 && z[i] < base2) || (z[i] < base1 && y[i] < base2))
            d[c][rot] = std::max(d[c][rot], babylon_sub(i, 1, n) + x[i]);
        if ((x[i] < base1 && z[i] < base2) || (z[i] < base1 && x[i] < base2))
            d[c][rot] = std::max(d[c][rot], babylon_sub(i, 2, n) + y[i]);
    }
    return d[c][rot];
}

int babylon(int n) {
    for (int i = 0; i < n; ++i) {
        d[i][0] = -1;
        d[i][1] = -1;
        d[i][2] = -1;
    }
    int r = 0;
    for (int i = 0; i < n; ++i) {
        r = std::max(r, babylon_sub(i, 0, n) + z[i]);
        r = std::max(r, babylon_sub(i, 1, n) + x[i]);
        r = std::max(r, babylon_sub(i, 2, n) + y[i]);
    }
    return r;
}

int main() {
    int t = 0;
    while (true) {
        int n ;
        std::cin >> n;
        if (n == 0)
            break;
        t++;
        for (int i = 0; i < n; i++) {
            std::cin >> x[i] >> y[i] >> z[i];
        }
        // std::cout << babylon(n) << std::endl;
        std::cout << "Case" << t << ":" << " maximum height = " << babylon(n);
        std::cout << std::endl;
    }
    return 0;
}

/*

g++ ./problems/Luogu_BABTWR.cpp -o ./efiles/test

./efiles/test

*/