// boj 1309 - 동물원 
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define endl '\n'
#define fastio std::cin.tie(nullptr)->sync_with_stdio(false)

using namespace std;

constexpr int mod = 9901;
constexpr int S = 1e5;
int N;

int dp[3][S + 1];
int sum[S+1];

int main() {

    fastio;
    cin >> N;

    dp[0][0] = 1;
    dp[1][0] = 1; 


    for (int i = 1; i < N; ++i) {
        dp[0][i] = (dp[1][i - 1] + dp[2][i - 1]) % mod;
        dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % mod;
        dp[2][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) % mod;
    }

    sum[0] = 2;

    for (int j = 1; j < N; ++j) sum[j] = (sum[j - 1] + dp[0][j] + dp[1][j]) % mod;

    int ans = 0;

    for (auto x : sum) ans += x;

    cout << (ans+1) % mod;

    return false;
}