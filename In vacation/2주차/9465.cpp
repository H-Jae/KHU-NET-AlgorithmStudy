#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define endl '\n'
#define fastio std::cin.tie(nullptr)->sync_with_stdio(false)

using namespace std;

constexpr int Size = 1e5;

int dp[3][Size+5];
int Map[2][Size+5];
int T, n;

int main() {
	fastio;
	cin >> T;

	while (T--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> Map[0][i];
		for (int i = 0; i < n; ++i) cin >> Map[1][i];

		dp[0][0] = Map[0][0];
		dp[1][0] = Map[1][0];

		for (int i = 0; i < n-1; ++i) {
			int ni = i + 1;
			dp[1][ni] = max(dp[0][i] + Map[1][ni], dp[2][i] + Map[1][ni]); // dp[어디가 숫자가 들어있는지][배열에 n번째] 1 : 2행에 0일때는 1행에 2일때는 둘다 공백
			dp[0][ni] = max(dp[1][i] + Map[0][ni], dp[2][i] + Map[0][ni]);
			dp[2][ni] = max(dp[0][i], dp[1][i]); 
		}

		cout << max(dp[1][n-1], dp[0][n-1]) << endl;
	}
}