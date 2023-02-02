#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define endl '\n'
#define fastio std::cin.tie(nullptr)->sync_with_stdio(false)

using namespace std;

struct Q {
	int x, y;
	int move;
	int cnt;
};

constexpr int S = 2 * 1e2;
int k, w, h;
queue<Q>q;
int visited[S + 5][S + 5][32];
int Map[S + 5][S + 5];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int digx[] = { 2,2,-2,-2,1,1,-1,-1 };
int digy[] = { 1,-1,1,-1,2,-2,2,-2 };


int main() {

	fastio;

	cin >> k;
	cin >> w >> h;
	fill(&Map[0][0], &Map[S + 4][S + 5], -1);

	for (int i = 2; i < h + 2; ++i) {
		for (int j = 2; j < w + 2; ++j) {
			cin >> Map[i][j];
		}
	}

	q.push({ 2,2,0});

	int ans = -1;

	while (!q.empty()) {
		int cx = q.front().x, cy = q.front().y;
		int m = q.front().move;
		int cnt = visited[cx][cy][m];
		q.pop();

		if (cx == h + 1 && cy == w + 1) {
			ans = cnt;
			break;
		}

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];

			if (( visited[nx][ny][m] > cnt + 1 || visited[nx][ny][m] == 0) && Map[nx][ny] == 0) {
				visited[nx][ny][m] = cnt + 1;
				q.push({ nx,ny,m});
			}
		}

		if (m == k) continue;

		for (int i = 0; i < 8; ++i) {
			int nx = cx + digx[i], ny = cy + digy[i];

			if ( (visited[nx][ny][m + 1] > cnt+1 || visited[nx][ny][m+1] == 0 ) && Map[nx][ny] == 0) {
				visited[nx][ny][m + 1] = cnt + 1;
				q.push({ nx,ny,m + 1 });
			}
		}
	}

	cout << ans;

	return false;

}