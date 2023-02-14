#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define endl '\n'
#define fastio std::cin.tie(nullptr)->sync_with_stdio(false); std::cout.tie(NULL);
#define INF 0x3f3f3f3f

using namespace std;
using pii = pair<int, int>;

constexpr int S = 1e3;
int N, M, X;
vector<pii>g[S + 5];

vector<int> dijkstra(int st) {
	vector<int>d;
	d.resize(N + 1, INF);
	d[0] = 0;
	d[st] = 0;
	priority_queue<pii> pq;
	pq.push({ 0,st });
	while (!pq.empty()) {
		int cur = pq.top().second, dis = -pq.top().first;
		pq.pop();
		if (d[cur] < dis) continue;

		for (auto &x : g[cur]) {
			int next = x.second, ndis = dis + x.first;
			if (d[next] > ndis) {
				d[next] = ndis;
				pq.push({ -ndis, next });
			}
		}
	}
	return d;
}

int main() {

	fastio;

	cin >> N >> M >> X;

	for (int i = 0; i < M; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({ w,v });
	}
	vector<int>ans;
	vector<int> fromX = dijkstra(X);
	for (int i = 1; i <= N; ++i) {
		vector<int> toX = dijkstra(i);
		ans.push_back(toX[X] + fromX[i]);
	}

	sort(ans.begin(), ans.end());

	cout << *(ans.end()-1);

	return false;
}