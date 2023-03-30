#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define endl '\n'
#define fastio std::cin.tie(nullptr)->sync_with_stdio(false); std::cout.tie(NULL);
#define INF 0x3f3f3f3f

using namespace std;
using pii = pair<int, int>;


constexpr int S = 5 * 1e4;
int T;
int n, m, t;
int s, g, h;
vector<int>d;
vector<int>hd;
vector<int>gd;
vector<pii>G[S+1];

inline bool c(int x,int nx) {
	return ((x == g && nx == h) || (x == h && nx == g));
}

void dijkstra(int st,vector<int>&_d) {
	_d[st] = 0;
	priority_queue<pii> pq;
	pq.push({ 0,st });
	while (!pq.empty()) {
		int cur = pq.top().second, dis = -pq.top().first;
		pq.pop();
		if (_d[cur] < dis) continue;

		for (auto &x : G[cur]) {
			int next = x.second, ndis = dis + x.first;
			if (_d[next] > ndis) {
				_d[next] = ndis;

				pq.push({ -ndis, next });
			}
		}
	}
}

int main() {

	fastio;

	cin >> T;
	while (T--) {
		cin >> n >> m >> t;
		d.clear();
		hd.clear();
		gd.clear();
		d.resize(n + 2, INF);
		hd.resize(n + 2, INF);
		gd.resize(n + 2, INF);
		cin >> s >> g >> h;
		for (int i = 0; i < m; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			G[u].push_back({ w,v });
			G[v].push_back({ w,u });
		}
		dijkstra(s,d);
		dijkstra(g, gd);
		dijkstra(h, hd);
		vector<int>ans;
		for (int i = 0; i < t; ++i) {
			int tmp;
			cin >> tmp;
			ans.push_back(tmp);
		}
		sort(ans.begin(), ans.end());

		
		for (auto &x : G) {
			vector<pii>tmp;
			tmp.swap(x);
		}

		for (auto &x : ans) {
			bool fl = false;
			if (d[x] == min(d[g] + gd[h] + hd[x], d[h] + hd[g] + gd[x])) cout << x << " ";
		}

		cout << endl;
	}

	return false;
}