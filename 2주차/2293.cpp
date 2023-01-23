#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define endl '\n'
#define fastio std::cin.tie(nullptr)->sync_with_stdio(false)

using namespace std;

constexpr int S = 1e4;

int dp[S + 1];
vector<int>Coin;
int n, k;


int main() {

	fastio;

	cin >> n >> k;

	for (int i = 0; i < n; ++i) { int tmp; cin >> tmp; Coin.push_back(tmp); }

	dp[0] = 1;

	for (auto x : Coin) for (int i = x; i <= k; ++i) if (dp[i - x]) dp[i] += dp[i - x];

	cout << dp[k];

	return false;
}
