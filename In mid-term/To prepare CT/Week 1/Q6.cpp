/*
Q6 : 파괴되지 않은 건물

2차원 누적합에 대한 이해가 있다면 쉽게 풀 수 있다.
2차원 누적합에 대한 지식이 없었어서,
2차원 누적합에 대해서 찾아보고 문제를 해결했다.

*/


#pragma GCC optimize ("03")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <string>
#include <vector>

using namespace std;

int sum[1002][1002];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    
    int ans = 0;
    
    int n = board.size(), m = board[0].size();
    
    for(auto x : skill){
        int dx = (x[0] == 1) ? -1 : 1;
        int r1 = x[1], r2 = x[3];
        int c1 = x[2], c2 = x[4];
        int degree = x[5] * dx;
        
        sum[r2+1][c2+1] += degree;
        sum[r1][c2+1] -= degree;
        sum[r2+1][c1] -= degree;
        sum[r1][c1] += degree;
        
    }
    
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            if(i > 0) sum[i][j] += sum[i-1][j];
            if(j > 0) sum[i][j] += sum[i][j-1];
            if(i>0 && j>0) sum[i][j] -= sum[i-1][j-1];
            board[i][j] += sum[i][j];
        }
    }
    
    for(auto v : board) for(auto x : v) if(x > 0) ans++;
    
    
    return ans;
}