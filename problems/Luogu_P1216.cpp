/*
# [USACO1.5] [IOI1994]数字三角形 Number Triangles

## 题目描述

观察下面的数字金字塔。


写一个程序来查找从最高点到底部任意处结束的路径，使路径经过数字的和最大。每一步可以走到左下方的点也可以到达右下方的点。

![](https://cdn.luogu.com.cn/upload/image_hosting/95pzs0ne.png)

在上面的样例中，从 $7 \to 3 \to 8 \to 7 \to 5$ 的路径产生了最大权值。

## 输入格式

第一个行一个正整数 $r$ ,表示行的数目。

后面每行为这个数字金字塔特定行包含的整数。

## 输出格式

单独的一行,包含那个可能得到的最大的和。

## 样例 #1

### 样例输入 #1

```
5
    7
   3 8
  8 1 0
 2 7 4 4
4 5 2 6 5
```

### 样例输出 #1

```
30
```

## 提示

【数据范围】  
对于 $100\%$ 的数据，$1\le r \le 1000$，所有输入在 $[0,100]$ 范围内。

题目翻译来自NOCOW。

USACO Training Section 1.5

IOI1994 Day1T1
*/

#include <iostream>
#include <vector>

int main() {
    int N;
    std::vector<std::vector<int> > a(1005, std::vector<int>(1005, 0));
    std::vector<std::vector<int> > dp(1005, std::vector<int>(1005, 0));
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cin >> a[i][j];
        }
    }
    dp[0][0] = a[0][0];
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i+1][j] = std::max(dp[i+1][j], dp[i][j] + a[i+1][j]);
            dp[i+1][j+1] = std::max(dp[i+1][j+1], dp[i][j] + a[i+1][j+1]);
        }
    }
    int ret = 0;
    for (int i = 0; i < N; ++i)
        ret = std::max(ret, dp[N-1][i]);
    std::cout << ret;
    return 0;
}

/*

g++ ./problems/Luogu_P1216.cpp -o ./efiles/test

./efiles/test

5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

*/