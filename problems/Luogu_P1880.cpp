/*

# [NOI1995] 石子合并

## 题目描述

在一个圆形操场的四周摆放 $N$ 堆石子，现要将石子有次序地合并成一堆，规定每次只能选相邻的 $2$ 堆合并成新的一堆，并将新的一堆的石子数，记为该次合并的得分。

试设计出一个算法,计算出将 $N$ 堆石子合并成 $1$ 堆的最小得分和最大得分。

## 输入格式

数据的第 $1$ 行是正整数 $N$，表示有 $N$ 堆石子。

第 $2$ 行有 $N$ 个整数，第 $i$ 个整数 $a_i$ 表示第 $i$ 堆石子的个数。

## 输出格式

输出共 $2$ 行，第 $1$ 行为最小得分，第 $2$ 行为最大得分。

## 样例 #1

### 样例输入 #1

```
4
4 5 9 4
```

### 样例输出 #1

```
43
54
```

## 提示

$1\leq N\leq 100$，$0\leq a_i\leq 20$。

*/

#include <iostream>
#include <vector>

int main() {

    int N;
    std::cin >> N;
    std::vector<int> vec(2*N+1, 0);
    std::vector<int> pre(2*N+2, 0); // pre[i] - pre[i-1] = vec[i-1]
    std::vector<std::vector<int> > dp(2*N+1, std::vector<int>(2*N+1, 0));
    for (int i = 0; i < N; ++i) {
        std::cin >> vec[i];
        vec[N+i] = vec[i];
    }
    for (int i = 1; i <=  2 * N + 1; ++i) {
        pre[i] = pre[i-1] + vec[i-1];
    } // vec[i] = pre[i+1] - pre[i];
    // vec[i, ..., j] = pre[j+1]] - pre[i];

    // dp[i][j] 表示区间 i, j的极值是多少
    // 转移方程 dp[i][j] = max(dp[i][j], dp[i]][k] + dp[k+1][j] + sum[j+1] - sum[i])
    // min
    for (int i = 0; i < 2*N+1; ++i) {
        for (int j = i; j < 2*N+1; ++j) {
            dp[i][j] = 9999999999;
        }
    }
    for (int i = 0; i < 2*N+1; ++i) {
        dp[i][i] = 0;
    }
    for (int i = 0; i < 2 * N + 1 - 1; ++i) {
        dp[i][i+1] = vec[i] + vec[i+1];
    }
    for (int len = 2; len <= N; len++) {
        for (int i = 1; i + len <= 2 * N; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k+1][j] + pre[j+1] - pre[i]);
            }
        }
    }
    int res_min = 9999999999;
    for (int i = 0; i < N; ++i) {
        res_min = std::min(res_min, dp[i][i+N-1]);
    }
    std::cout << res_min << std::endl;

    // max
    for (int i = 0; i < 2*N+1; ++i) {
        for (int j = i; j < 2*N+1; ++j) {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < 2 * N + 1 - 1; ++i) {
        dp[i][i+1] = vec[i] + vec[i+1];
    }
    for (int len = 2; len <= N; len++) {
        for (int i = 1; i + len <= 2 * N; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                dp[i][j] = std::max(dp[i][j], dp[i][k] + dp[k+1][j] + pre[j+1] - pre[i]);
            }
        }
    }
    int res_max = 0;
    for (int i = 0; i < N; ++i) {
        res_max = std::max(res_max, dp[i][i+N-1]);
    }
    std::cout << res_max << std::endl;

    return 0;
}

/*

g++ ./problems/Luogu_P1880.cpp -o ./efiles/test

./efiles/test

 */