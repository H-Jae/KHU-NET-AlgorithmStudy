/*
Q5 : 양과 늑대

비트필드를 이용한 DFS로 문제를 풀었다.

비트 다루는 걸 좋아해서 무난하게 풀었다.
양과 늑대를 어떻게 카운팅하는가,
양과 늑대의 카운팅 기점이 문제의 관건이 될 것 같다.

*/

#include <bits/stdc++.h>
#include <bitset>
using namespace std;

vector<int> l, r, c;
int n, ans = 1;
bool visited[1 << 17];

void dfs(int cur) {
    if (visited[cur]) return;
    visited[cur] = true;
    
    bitset<17> bit(cur);
    int wolf = 0, cnt = 0;
    
    for (int i = 0; i < n; ++i) {
        if (bit[i]) {
        if(c[i]) wolf++;
        else cnt++;
        }
    }
    
    if (wolf >= cnt) return;
    
    ans = max(ans, cnt);
    
    for (int i = 0; i < n; ++i) {
        if (!bit[i]) continue;
        if (l[i] != -INT_MAX) dfs(cur | (1 << l[i]));
        if (r[i] != -INT_MAX) dfs(cur | (1 << r[i]));
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    n = info.size();
    c = info;
    l.resize(n, -INT_MAX);
    r.resize(n, -INT_MAX);

    for (int i = 0; i < n - 1; ++i) {
        int u = edges[i][0], v = edges[i][1];
        if (l[u] == -INT_MAX) l[u] = v;
        else r[u] = v;
    }

    dfs(1);
    return ans;
}