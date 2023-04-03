/*
Q7 : 사라지는 발판

전형적인 게임 이론 문제다.
minmax tree와 alpha-beta pruning에 대한 이해가 있으면 쉽게 풀 수 있다.
문제에 조건에 맞추어서 구현했다.

*/


#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int n, m;
bool visited[5][5]; 
vector<vector<int>> v;

int solve(int px, int py, int ex, int ey) {
    int ret = 0;

    if (visited[px][py]) return ret;

    for (int i = 0; i < 4; i++) {
        int nx = px + dx[i], ny = py + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (visited[nx][ny]) continue;
        if (!v[nx][ny]) continue;

        visited[px][py] = true;
        int res = solve(ex, ey, nx, ny) + 1;
        visited[px][py] = false;
        
        if(!(ret&1)&& res&1) ret = res;
        else if(ret&1 && res&1) ret = min(ret, res);
        else if(!(ret&1) && !(res&1)) ret = max(ret,res);

    }
    return ret;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    n = board.size();
    m = board[0].size();
    v = board;
    return solve(aloc[0], aloc[1], bloc[0], bloc[1]);
}