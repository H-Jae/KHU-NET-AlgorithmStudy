#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define endl '\n'
#define fastio std::cin.tie(nullptr)->sync_with_stdio(false)

using namespace std;

int n;
int card[1001];
int dp[1001];

int main(){

    fastio;
    
    cin >> n;
    
    for(int i = 1; i<=n; ++i) cin >> card[i];
    
    dp[1] = card[1];
    
    for(int i = 2; i<= n; ++i){
        for(int j = 1; j<=i; ++j) dp[i] = max(dp[i],dp[i-j]+card[j]);
    }
    
    cout << dp[n];
    
}