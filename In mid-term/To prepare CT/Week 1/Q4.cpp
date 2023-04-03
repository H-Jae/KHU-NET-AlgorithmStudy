/*
Q4 : 양궁 대회

비트를 이용해서 모든 부분집합을 순회했다.
그 후 그리디하게 접근하여 풀었다.

화살이 남았을 때의 경우를 기저 사례로 설정해주는 것도 잊지 말자.

*/

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <bitset>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct P{
    int sum, bit;
};

bool cmp(const P &l, const P &r){
    if(l.sum == r.sum) {
        bitset<11> lb(l.bit), rb(r.bit);
        
        for(int i = 0; i < 11; ++i){
            if(lb[i] && rb[i]) continue;
            else if(lb[i]) return true;
            else if(rb[i]) return false;
        }
    }
    else return l.sum > r.sum;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ret, v;
    
    reverse(info.begin(), info.end());
    
    for (int bit = (1 << 11); bit--;) {
        int cnt = 0; int idx = 11;
        
        while(idx--) if(bit & (1<<idx)) cnt += info[idx] + 1;
        
        if(cnt == n) v.push_back(bit);
        if(cnt < n) v.push_back(bit + 1);
    }
    
    vector<P> gap; 
    
    for(auto x : v){
        int gp = 0;
        for(int i = 11; i--;){
            if(x & 1 << i) gp += i;
            else if(info[i]) gp -= i;
        }
        gap.push_back({gp,x});
    }
    
    sort(gap.begin(),gap.end(),cmp);
    
    auto ans = *gap.begin();
    
    if(ans.sum < 1) {
        ret.push_back(-1);
        return ret;
    }
    int cnt = 0;
    for(int i = 11; i--;) {
        if (ans.bit & (1 << i)){
            if(i) {ret.push_back(info[i] + 1); cnt += info[i] + 1;}
            else if(cnt < n) ret.push_back(n - cnt);
        }
        else ret.push_back(0);
    }
                                         
    return ret;
}