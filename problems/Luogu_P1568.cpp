/*

# 四方定理

## 题目描述

四方定理是众所周知的：任意一个正整数$n$，可以分解为不超过四个整数的平方和。例如：$25=1^{2}+2^{2}+2^{2}+4^{2}$，当然还有其他的分解方案，$25=4^{2}+3^{2}$和$25=5^{2}$。给定的正整数$n$，编程统计它能分解的方案总数。注意：$25=4^{2}+3^{2}$和$25=3^{2}+4^{2}$视为一种方案。

## 输入格式

第一行为正整数$t$($t\le 100$)，接下来$t$行，每行一个正整数$n$($n\le 32768$)。

## 输出格式

对于每个正整数$n$，输出方案总数。

## 样例 #1

### 样例输入 #1

```
1
2003
```

### 样例输出 #1

```
48
```
*/

#include <iostream>
#include <vector>
int main() {
    std::vector<std::vector<int> > dp(32769, std::vector<int>(5, 0));
    int n;
    std::cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i < 250; ++i) {
        for (int k = 1; k <= 4; ++k) {
            for (int j = 1; j <= 32768 and i*i + j <= 32768; j++) {
                if (j >= i*i)
                    dp[j][k] += dp[j - i*i][k-1];
            }
        }
    }
    while (n--) {
        int t;
        std::cin >> t;
        std::cout << (dp[t][1] + dp[t][2] + dp[t][3] + dp[t][4]) << std::endl;
    }
    return 0;
}

/*

g++ ./problems/Luogu_P1568.cpp -o ./efiles/test

./efiles/test

1
4

*/