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
    std::vector<int> dp
    for (int i = 0; i < N; ++i) {
        std::cin >> vec[i];
        vec[N+i] = vec[i];
    }

    return 0;
}