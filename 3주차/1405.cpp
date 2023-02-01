// BOJ 1405 - 미친 로봇

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define endl '\n'
#define fastio std::cin.tie(nullptr)->sync_with_stdio(false)

using namespace std;

int N;
double p[4];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool visited[30][30];

double dfs(int x, int y, int cnt) {
    if (cnt == N) return 1.0; 
    double ret = 0.0;
    visited[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (visited[nx][ny]) continue;
      
        ret = ret + p[i] * dfs(nx, ny, cnt + 1);
    }

    visited[x][y] = false;
    return ret;
}


int main() {

    fastio;
    
    cin >> N;
    for (int i = 0; i < 4; ++i) {
        int tmp;
        cin >> tmp;
        p[i] = tmp / 100.0;
    }
    cout.precision(10);
    cout << fixed << dfs(14, 14, 0);

    return false;
}