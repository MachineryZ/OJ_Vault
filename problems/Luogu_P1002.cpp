/*
# [NOIP2002 普及组] 过河卒

## 题目描述

棋盘上 $A$ 点有一个过河卒，需要走到目标 $B$ 点。卒行走的规则：可以向下、或者向右。同时在棋盘上 $C$ 点有一个对方的马，该马所在的点和所有跳跃一步可达的点称为对方马的控制点。因此称之为“马拦过河卒”。

棋盘用坐标表示，$A$ 点 $(0, 0)$、$B$ 点 $(n, m)$，同样马的位置坐标是需要给出的。

![](https://cdn.luogu.com.cn/upload/image_hosting/ipmwl52i.png)

现在要求你计算出卒从 $A$ 点能够到达 $B$ 点的路径的条数，假设马的位置是固定不动的，并不是卒走一步马走一步。

## 输入格式

一行四个正整数，分别表示 $B$ 点坐标和马的坐标。

## 输出格式

一个整数，表示所有的路径条数。

## 样例 #1

### 样例输入 #1

```
6 6 3 3
```

### 样例输出 #1

```
6
```

## 提示

对于 $100 \%$ 的数据，$1 \le n, m \le 20$，$0 \le$ 马的坐标 $\le 20$。

**【题目来源】**

NOIP 2002 普及组第四题
*/

#include <iostream>
#include <vector>

int main() {
    int N, M;
    int x, y;
    std::cin >> N >> M >> x >> y;
    std::vector<std::vector<long long> > dp(N+1, std::vector<long long>(M+1, 0));
    int dx[8] = {2, 2, 1, 1, -2, -2, -1, -1};
    int dy[8] = {1,-1, 2,-2, 1, -1, 2, -2};
    for (int i = 0; i < 8; ++i) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (new_x >= 0 and new_x <= N and new_y >= 0 and new_y <= M) {
            dp[new_x][new_y] = -1;
        }
    }
    dp[x][y] = -1;
    dp[0][0] = 1;
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            if (i == 0 and j == 0)
                continue;
            if (dp[i][j] == -1)
                continue;
            if (i > 0)
                dp[i][j] += dp[i-1][j] == -1 ? 0 : dp[i-1][j];
            if (j > 0)
                dp[i][j] += dp[i][j-1] == -1 ? 0 : dp[i][j-1];
        }
    }
    // for (int i = 0; i <= N; ++i) {
    //     for (int j = 0; j <= M; ++j) {
    //         std::cout << dp[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    std::cout << dp[N][M] << std::endl;
    return 0;
}

/*

g++ ./problems/Luogu_P1002.cpp -o ./efiles/test

./efiles/test

*/