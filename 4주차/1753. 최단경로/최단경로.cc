#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define endl '\n'
#define fastio std::cin.tie(nullptr)->sync_with_stdio(false); std::cout.tie(NULL);
#define INF 0x3f3f3f3f

using namespace std;
using pii = pair<int, int>;

constexpr int S = 2 * 1e4;
int V, E;
int K;
vector<pii>g[S + 5];
vector<int>d;

void dijkstra(int st) {
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
}

int main() {

	fastio;

	cin >> V >> E >> K;

	d.resize(V+1,INF);

	for (int i = 0; i < E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({ w,v });
	}
	dijkstra(K);
	for (int i = 1; i <= V; ++i) {
		if (d[i] - INF) cout << d[i] << endl;
		else cout << "INF" << endl;
	}


	return false;
}