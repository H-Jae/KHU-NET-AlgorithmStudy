#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define endl '\n'
#define fastio std::cin.tie(nullptr)->sync_with_stdio(false)

using namespace std;

constexpr int S = 1500;
int R, C;
char Map[S+5][S+5];
int parent[S * S + 5];
queue<pair<int,int>> q;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int Swan[2];

int Find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {

	x = Find(x);
	y = Find(y);

	if (x != y) parent[x] = y;

	return;
}

void meltBFS(int x, int y) {

	q.push({x, y});

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
				if (Map[nx][ny] == '.') {
				Union(nx * C + ny, x * C + y);
			}
		}
	}
}

void BFS() {
	int qs = q.size();

	for (int i = 0; i < qs; ++i) {
		int cx = q.front().first, cy = q.front().second;
		q.pop();

		for (int j = 0; j < 4; ++j) {
			int nx = cx + dx[j], ny = cy + dy[j];
			if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
				if (Map[nx][ny] == 'X') {
					Map[nx][ny] = '.';
					meltBFS(nx, ny);
				}
			}
		}
	}
}

int main() {

	fastio;

	cin >> R >> C;

	for (int i = 0; i < R * C; ++i) {
		parent[i] = i;
	}

	int tmp = 0;

	for (int i = 0; i < R; ++i) {
		cin >> Map[i];
		for (int j = 0; j < C; ++j) {
			if (Map[i][j] == 'L') { Map[i][j] = '.'; Swan[tmp++] = i * C + j;}
			if (Map[i][j] == '.') meltBFS(i, j);
		}
	}
	int ans = 0;

	while (!q.empty()) {
		if (Find(Swan[0]) == Find(Swan[1])) break;
		BFS();
		ans++;
	}

	cout << ans;

	return false;
}