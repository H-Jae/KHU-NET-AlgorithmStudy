#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define endl '\n'
#define fastio std::cin.tie(nullptr)->sync_with_stdio(false); cout.tie(NULL);

using namespace std;
using pii = pair<int, int>;

constexpr int S = 1e4;
int N, D;
int ans;
vector<pii>Graph[S+1];
vector<int>dist;
priority_queue<pii>pq; // pos, cost

int main() {

	fastio;

	cin >> N >> D;

	dist.resize(D+1, INT_MAX);

	for (int i = 0; i < N; ++i) {
		int u, v, cost;
		cin >> u >> v >> cost;
		if (cost >= v - u) continue;
		if (v > D) continue;
		Graph[u].push_back({ v,cost });
	}


	for (int i = 0; i <= D; ++i) {
		if (i == 0) dist[i] = 0;
		else dist[i] = min(dist[i - 1] + 1, dist[i]);

		if (Graph[i].empty()) continue;
		for (auto x : Graph[i]) {
			dist[x.first] = min(dist[i] + x.second, dist[x.first]);
		}
	}


	cout << dist[D];

	return false;
}