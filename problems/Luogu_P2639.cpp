#include <iostream>
#include <vector>

int main() {
    int W, N;
    std::cin >> W >> N;
    std::vector<int> w(N, 0);
    std::vector<int> dp(W+1, 0);
    for (int i = 0; i < N; ++i)
        std::cin >> w[i];
    for (int i = 0; i < N; ++i) {
        for (int j = W; j >= w[i]; --j) {
            dp[j] = std::max(dp[j], dp[j - w[i]] + w[i]);
        }
    }
    std::cout << dp[W] << std::endl;
    return 0;
}

/*

g++ ./problems/Luogu_P2639.cpp -o ./efiles/test

./efiles/test

*/