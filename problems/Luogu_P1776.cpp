/*
# 宝物筛选

## 题目描述

终于，破解了千年的难题。小 FF 找到了王室的宝物室，里面堆满了无数价值连城的宝物。

这下小 FF 可发财了，嘎嘎。但是这里的宝物实在是太多了，小 FF 的采集车似乎装不下那么多宝物。看来小 FF 只能含泪舍弃其中的一部分宝物了。

小 FF 对洞穴里的宝物进行了整理，他发现每样宝物都有一件或者多件。他粗略估算了下每样宝物的价值，之后开始了宝物筛选工作：小 FF 有一个最大载重为 $W$ 的采集车，洞穴里总共有 $n$ 种宝物，每种宝物的价值为 $v_i$，重量为 $w_i$，每种宝物有 $m_i$ 件。小 FF 希望在采集车不超载的前提下，选择一些宝物装进采集车，使得它们的价值和最大。

## 输入格式

第一行为一个整数 $n$ 和 $W$，分别表示宝物种数和采集车的最大载重。

接下来 $n$ 行每行三个整数 $v_i,w_i,m_i$。

## 输出格式

输出仅一个整数，表示在采集车不超载的情况下收集的宝物的最大价值。

## 样例 #1

### 样例输入 #1

```
4 20
3 9 3
5 9 1
9 4 2
8 1 3
```

### 样例输出 #1

```
47
```

## 提示

对于 $30\%$ 的数据，$n\leq \sum m_i\leq 10^4$，$0\le W\leq 10^3$。

对于 $100\%$ 的数据，$n\leq \sum m_i \leq 10^5$，$0\le W\leq 4\times 10^4$，$1\leq n\le 100$。

*/

#include <iostream>
#include <vector>

int main() {
    int W, N;
    std::cin >> N >> W;
    std::vector<int> w(N+5, 0);
    std::vector<int> v(N+5, 0);
    std::vector<int> num(N+5, 0);
    std::vector<long long> dp(4e4+5, 0);

    for (int i = 0; i < N; ++i)
        std::cin >> v[i] >> w[i] >> num[i];

    /* TLE version */
    // for (int i = 0; i < N; ++i) {
    //     for (int j = W; j >= w[i]; --j) {
    //         for (int k = 1; k * w[i] <= j and k <= num[i]; ++k) {
    //             dp[j] = std::max(dp[j], dp[j - k * w[i]] + k * v[i]);
    //         }
    //     }
    // }
    /* 二进制优化 */
    for (int i = 0; i < N; ++i) {
        int cnt = num[i];
        for (int k = 1; k <= cnt; k *= 2) {
            int new_w = w[i] * k;
            int new_v = v[i] * k;
            for (int j = W; j >= new_w; j--) {
                dp[j] = std::max(dp[j], dp[j - new_w] + new_v);
            }
            cnt -= k;
        }
        if (cnt > 0) {
            int new_w = w[i] * cnt;
            int new_v = v[i] * cnt;
            for (int j = W; j >= new_w; j--) {
                dp[j] = std::max(dp[j], dp[j - new_w] + new_v);
            }
        }
    }
    std::cout << dp[W] << std::endl;
    return 0;
}
/*
g++ ./problems/Luogu_P1776.cpp -o ./efiles/test

./efiles/test
4 20
3 9 3
5 9 1
9 4 2
8 1 3

*/