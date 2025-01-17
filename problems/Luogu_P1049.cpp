/*
# [NOIP2001 普及组] 装箱问题

## 题目描述

有一个箱子容量为 $V$，同时有 $n$ 个物品，每个物品有一个体积。


现在从 $n$ 个物品中，任取若干个装入箱内（也可以不取），使箱子的剩余空间最小。输出这个最小值。

## 输入格式

第一行共一个整数 $V$，表示箱子容量。

第二行共一个整数 $n$，表示物品总数。

接下来 $n$ 行，每行有一个正整数，表示第 $i$ 个物品的体积。

## 输出格式

- 共一行一个整数，表示箱子最小剩余空间。

## 样例 #1

### 样例输入 #1

```
24
6
8
3
12
7
9
7
```

### 样例输出 #1

```
0
```

## 提示

对于 $100\%$ 数据，满足 $0<n \le 30$，$1 \le V \le 20000$。

**【题目来源】**

NOIP 2001 普及组第四题
*/

#include <iostream>
#include <vector>

int main() {
    int n, W;
    std::cin >> W >> n;
    std::vector<int> w(n, 0);
    std::vector<int> dp(W+1, 0);
    for (int i = 0; i < n; ++i) 
        std::cin >> w[i];

    for (int i = 0; i < n; ++i) {
        for (int j = W; j >= w[i]; j--) {
            dp[j] = std::max(dp[j], dp[j - w[i]] + w[i]);
        }
    }
    std::cout << W - dp[W] << std::endl;
    return 0;
}

/*

g++ ./problems/Luogu_P1049.cpp -o ./efiles/test

./efiles/test

24
6
1
2
3
4
5
6
*/