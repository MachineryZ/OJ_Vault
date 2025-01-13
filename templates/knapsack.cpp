#include <iostream>
#include <vector>

/* 0-1 背包 */
/*

有 N 个物品，每个物品重量 wi，价值 vi，用 W 容量背包最多装下多少价值背包

dp数组定义：
    dp[i] 表示用 i 重量的背包最多能装下多少价值

转移方程：
    对于第j个物品, 是否要选择这个物品就代表着要和原来的状态做对比
    dp[i] = max(dp[i], dp[i - wi] + vi)

代码细节：
    要注意，枚举重量的时候，是从

*/

/***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */

/* 完全 背包 */
/*

有 N 个物品，每个物品重量 wi，价值 vi，用 W 容量背包最多装下多少价值背包

dp数组定义：
    dp[i] 表示用 i 重量的背包最多能装下多少价值

转移方程：
    对于第j个物品, 是否要选择这个物品就代表着要和原来的状态做对比
    dp[i] = max(dp[i], dp[i - wi] + vi)

代码细节：
    要注意，枚举重量的时候，是从重量为0的地方开始枚举

*/

/***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */

/*
多重背包
和 0-1 背包是一样的思路，多一层k的循环
for (int i = 1; i <= n; i++) {
  for (int weight = W; weight >= w[i]; weight--) {
    // 多遍历一层物品数量
    for (int k = 1; k * w[i] <= weight && k <= cnt[i]; k++) {
      dp[weight] = max(dp[weight], dp[weight - k * w[i]] + k * v[i]);
    }
  }

多重背包的优化，二进制优化：
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
*/