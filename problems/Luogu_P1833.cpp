/*
# 樱花

## 题目背景

《爱与愁的故事第四弹·plant》第一章。

## 题目描述

爱与愁大神后院里种了 $n$ 棵樱花树，每棵都有美学值 $C_i(0 \le C_i \le 200)$。爱与愁大神在每天上学前都会来赏花。爱与愁大神可是生物学霸，他懂得如何欣赏樱花：一种樱花树看一遍过，一种樱花树最多看 $P_i(0 \le P_i \le 100)$ 遍，一种樱花树可以看无数遍。但是看每棵樱花树都有一定的时间 $T_i(0 \le T_i \le 100)$。爱与愁大神离去上学的时间只剩下一小会儿了。求解看哪几棵樱花树能使美学值最高且爱与愁大神能准时（或提早）去上学。

## 输入格式

共 $n+1$行：

第 $1$ 行：现在时间 $T_s$（几时：几分），去上学的时间 $T_e$（几时：几分），爱与愁大神院子里有几棵樱花树 $n$。这里的 $T_s$，$T_e$ 格式为：`hh:mm`，其中 $0 \leq hh \leq 23$，$0 \leq mm \leq 59$，且 $hh,mm,n$ 均为正整数。

第 $2$ 行到第 $n+1$ 行，每行三个正整数：看完第 $i$ 棵树的耗费时间 $T_i$，第 $i$ 棵树的美学值 $C_i$，看第 $i$ 棵树的次数 $P_i$（$P_i=0$ 表示无数次，$P_i$ 是其他数字表示最多可看的次数 $P_i$）。

## 输出格式

只有一个整数，表示最大美学值。

## 样例 #1

### 样例输入 #1

```
6:50 7:00 3
2 1 0
3 3 1
4 5 4
```

### 样例输出 #1

```
11
```

## 提示

$100\%$ 数据：$T_e-T_s \leq 1000$（即开始时间距离结束时间不超过 $1000$ 分钟），$n \leq 10000$。保证 $T_e,T_s$ 为同一天内的时间。

样例解释：赏第一棵樱花树一次，赏第三棵樱花树 $2$ 次。
*/

#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string t1;
    std::string t2;
    int N;
    std::vector<int> w(N, 0);
    std::vector<int> v(N, 0);
    std::vector<int> num(N, 0);
    std::cin >> t1 >> t2 >> N;
    for (int i = 0; i < N; ++i)
        std::cin >> w[i] >> v[i] >> num[i];
    if (t1.size() == 4)
        t1 = "0" + t1;
    if (t2.size() == 4)
        t2 = "0" + t2;
    int W = std::stoi(t2.substr(0, 2)) * 60 - std::stoi(t1.substr(0, 2)) * 60;
    W += std::stoi(t2.substr(3, 2)) - std::stoi(t1.substr(3, 2));
    std::vector<long long> dp(W, 0);
    for (int i = 0; i < N; ++i) {
        if (num[i] == 0) {// 完全背包
            for (int j = 0; j <= W - w[i]; ++j) {
                dp[j + w[i]] = std::max(dp[j + w[i]], dp[j] + v[i]);
            }
        }
        else if (num[i] > 0) { // 多重背包
            int cnt = num[i];
            for (int k = 1; k <= num[i] and w[i] * k <= W; k *= 2) {
                int new_w = w[i] * k;
                int new_v = v[i] * k;
                for (int j = W; j >= new_w; --j) {
                    dp[j] = std::max(dp[j], dp[j - new_w] + new_v);
                }
                cnt -= k;
            }
            if (cnt > 0) {
                int new_w = w[i] * cnt;
                int new_v = v[i] * cnt;
                for (int j = W; j >= new_w; --j) {
                    dp[j] = std::max(dp[j], dp[j - new_w] + new_v);
                }
            }
        }
    }
    std::cout << dp[W] << std::endl;

    return 0;
}
/* cstring compile error
#include <iostream>
#include <vector>

int main() {
    int h1, m1, h2, m2, N;
    char colon; // 用于读取时间中的冒号
    std::cin >> h1 >> colon >> m1 >> h2 >> colon >> m2 >> N;

    // 计算总时间差（分钟）
    int W = (h2 - h1) * 60 + (m2 - m1);

    std::vector<int> w(N), v(N), num(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> w[i] >> v[i] >> num[i];
    }

    std::vector<long long> dp(W + 1, 0); // dp数组，大小为W+1

    for (int i = 0; i < N; ++i) {
        if (num[i] == 0) { // 完全背包
            for (int j = 0; j <= W - w[i]; ++j) {
                dp[j + w[i]] = std::max(dp[j + w[i]], dp[j] + v[i]);
            }
        } else if (num[i] > 0) { // 多重背包
            int cnt = num[i];
            for (int k = 1; k <= cnt && w[i] * k <= W; k *= 2) {
                int new_w = w[i] * k;
                int new_v = v[i] * k;
                for (int j = W; j >= new_w; --j) {
                    dp[j] = std::max(dp[j], dp[j - new_w] + new_v);
                }
                cnt -= k;
            }
            if (cnt > 0) {
                int new_w = w[i] * cnt;
                int new_v = v[i] * cnt;
                for (int j = W; j >= new_w; --j) {
                    dp[j] = std::max(dp[j], dp[j - new_w] + new_v);
                }
            }
        }
    }

    std::cout << dp[W] << std::endl;

    return 0;
}
*/

/*

g++ ./problems/Luogu_P1833.cpp -o ./efiles/test

./efiles/test


*/
#include <algorithm>
#include <iostream>
using namespace std;

struct edge {
  int v, next;
} e[6005];

int head[6005], n, cnt, f[6005][2], ans, is_h[6005], vis[6005];

void addedge(int u, int v) {  // 建图
  e[++cnt].v = v;
  e[cnt].next = head[u];
  head[u] = cnt;
}

void calc(int k) {
  vis[k] = 1;
  for (int i = head[k]; i; i = e[i].next) {  // 枚举该结点的每个子结点
    if (vis[e[i].v]) continue;
    calc(e[i].v);
    f[k][1] += f[e[i].v][0];
    f[k][0] += max(f[e[i].v][0], f[e[i].v][1]);  // 转移方程
  }
  return;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> f[i][1];
  for (int i = 1; i < n; i++) {
    int l, k;
    cin >> l >> k;
    is_h[l] = 1;
    addedge(k, l);
  }
  for (int i = 1; i <= n; i++)
    if (!is_h[i]) {  // 从根结点开始DFS
      calc(i);
      cout << max(f[i][1], f[i][0]);
      return 0;
    }
}