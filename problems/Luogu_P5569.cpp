/*
# [SDOI2008] 石子合并

## 题目描述

在一个操场上摆放着一排 $N$ 堆石子。现要将石子有次序地合并成一堆。规定每次只能选相邻的 $2$ 堆石子合并成新的一堆，并将新的一堆石子数记为该次合并的得分。

试设计一个算法，计算出将 $N$ 堆石子合并成一堆的最小得分。

## 输入格式

第一行一个整数 $N$。

接下来 $N$ 行，第 $i$ 行一个整数 $a_i$，代表第 $i$ 堆石子的石子数。

## 输出格式

输出将所有石子合并为一堆的最小得分。

## 样例 #1

### 样例输入 #1

```
4
1
1
1
1
```

### 样例输出 #1

```
8
```

## 提示

$ N \leq 40000, a_i \leq 200$

**请注意 $N$ 的范围（来自上传者的提示）**

*/

#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> vec(N, 0);
    std::vector<int> pre(N+1, 0); // pre[i] - pre[i-1] = vec[i-1]
    std::vector<std::vector<int> > dp(N, std::vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        std::cin >> vec[i];
    }
    for (int i = 1; i <= N; ++i) {
        pre[i] = pre[i-1] + vec[i-1];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            dp[i][j] = 99999999;
        }
    }
    for (int i = 0; i < N; ++i) {
        dp[i][i] = 0;
    }
    for (int i = 0; i < N-1; ++i) {
        dp[i][i+1] = vec[i] + vec[i+1];
    }
    for (int len = 2; len <= N; len++) {
        for (int i = 0; i + len <= N; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                // std::cout << i << " " << k << " " << j << std::endl;
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k+1][j] + pre[j+1] - pre[i]);
            }
        }
    }
    std::cout << dp[0][N-1] << std::endl;
    return 0;

}

/*

g++ ./problems/Luogu_P5569.cpp -o ./efiles/test

./efiles/test



*/