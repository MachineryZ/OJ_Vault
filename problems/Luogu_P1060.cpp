#include <iostream>
#include <vector>

int main() {
    int W, n;
    std::cin >> W >> n;
    std::vector<int> w(n, 0);
    std::vector<int> p(n, 0);
    std::vector<int> dp(W+1, 0);
    for (int i = 0; i < n; ++i) 
        std::cin >> w[i] >> p[i];
    for (int i = 0; i < n; ++i) {
        for (int j = W; j >= w[i]; --j) {
            dp[j] = std::max(dp[j], dp[j - w[i]] + p[i] * w[i]);
        }
    }
    std::cout << dp[W] << std::endl;
    return 0;
}

/*

g++ ./problems/Luogu_P1060.cpp -o ./efiles/test

./efiles/test

 */