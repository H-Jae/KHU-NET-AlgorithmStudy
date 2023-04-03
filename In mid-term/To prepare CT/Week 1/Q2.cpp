/*

Q2 : k진수에서 소수 개수 구하기

sqrtn을 사용한 sieve구현과 진수 변환에 대한 이해가 확실하다면
접근하기 쉬웠던 문제였다.

*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> cv(int n, int k) {
    vector<int> ret;
    while (n) {
        ret.push_back(n % k);
        n /= k;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int sieve(ll n){
    if(n <= 1) return 0;
    for(ll i = 2; i*i <= n; i++)
        if(n % i == 0) return 0;
    return 1;
}

int solution(int n, int k) {
    vector<int> v = cv(n, k);
    ll cur = 0;
    int ret = 0;
    for (auto x : v) {
        if (!x) {
            ret += sieve(cur);
            cur = 0;
            continue;
        }
        cur = 10 * cur + x;
    }
    ret += sieve(cur);
    return ret;
}