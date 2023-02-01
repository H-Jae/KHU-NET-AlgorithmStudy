#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define endl '\n'
#define fastio std::cin.tie(nullptr)->sync_with_stdio(false)

using namespace std;

constexpr int Size = 5 * 1e2;
int M, N;

int dx[] = { 1,-1,0,0 }; 
int dy[] = { 0,0,1,-1 };  

int Map[Size + 5][Size + 5];
int dp[Size + 5][Size + 5];

int solve(int cx, int cy) {
	if (cx == M && cy == N) return 1; // M , N -> 도착지에 가면 리턴해준다

	if (dp[cx][cy] != -1) return dp[cx][cy]; // 방문했으면 dp반환
	else dp[cx][cy]++; 

	for (int i = 0; i < 4; ++i) {
		int nx = cx + dx[i], ny = cy + dy[i];
		if (Map[nx][ny] && Map[nx][ny] < Map[cx][cy]) {
			dp[cx][cy] += solve(nx, ny);
		}
	}
	return dp[cx][cy];
}

int main() {

	fastio;

	cin >> M >> N;

	for (int i = 1; i <= M; ++i) for (int j = 1; j <= N; ++j) { cin >> Map[i][j]; dp[i][j] = -1; }
	

	cout << solve(1,1);

	return false;
}