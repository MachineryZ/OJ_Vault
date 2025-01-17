/*
# 没有上司的舞会

## 题目描述

某大学有 $n$ 个职员，编号为 $1\ldots n$。

他们之间有从属关系，也就是说他们的关系就像一棵以校长为根的树，父结点就是子结点的直接上司。

现在有个周年庆宴会，宴会每邀请来一个职员都会增加一定的快乐指数 $r_i$，但是呢，如果某个职员的直接上司来参加舞会了，那么这个职员就无论如何也不肯来参加舞会了。

所以，请你编程计算，邀请哪些职员可以使快乐指数最大，求最大的快乐指数。

## 输入格式

输入的第一行是一个整数 $n$。

第 $2$ 到第 $(n + 1)$ 行，每行一个整数，第 $(i+1)$ 行的整数表示 $i$ 号职员的快乐指数 $r_i$。

第 $(n + 2)$ 到第 $2n$ 行，每行输入一对整数 $l, k$，代表 $k$ 是 $l$ 的直接上司。

## 输出格式

输出一行一个整数代表最大的快乐指数。

## 样例 #1

### 样例输入 #1

```
7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5
```

### 样例输出 #1

```
5
```

## 提示

#### 数据规模与约定

对于 $100\%$ 的数据，保证 $1\leq n \leq 6 \times 10^3$，$-128 \leq r_i\leq 127$，$1 \leq l, k \leq n$，且给出的关系一定是一棵树。
*/

#include <algorithm>
#include <iostream>
using namespace std;

struct edge {
    int v, next;
} e[6005];

int head[6005], n, cnt, f[6005][2], ans, is_h[6005], vis[6005];

void addedge(int u, int v) {
    e[++cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void calc(int k) {
    vis[k] = 1;
    for (int i = head[k]; i; i = e[i].next) {
        if (vis[e[i].v])
            continue;
        calc(e[i].v);
        f[k][1] += f[e[i].v][0];
        f[k][0] += max(f[e[i].v][0], f[e[i].v][1]);
    }
    return;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> f[i][1];
    for (int i = 1; i < n; ++i) {
        int l, k;
        std::cin >> l >> k;
        is_h[l] = 1;
        addedge(k, l);
    }
    for (int i = 1; i <= n; ++i) {
        if (!is_h[i]) {
            calc(i);
            std::cout << max(f[i][1], f[i][0]) << std::endl;
        }
    }
    return 0;
}

/*

g++ ./problems/Luogu_P1352.cpp -o ./efiles/test

./efiles/test

7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5

*/