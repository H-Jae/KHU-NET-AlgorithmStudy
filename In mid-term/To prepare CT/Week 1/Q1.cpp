/*
Q1 : 신고 결과 받기
map을 이용하면 간단하게 풀릴 문제였다.

*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<string, int> m1;
unordered_map<string, set<string>> m2;
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int n = id_list.size();
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++)
        m1[id_list[i]] = i;

    for (auto x : report) {
        auto idx = x.find(' ');
        m2[x.substr(idx, -1)].insert(x.substr(0, idx));
    }

    for (auto x : m2)
        if (x.second.size() >= k)
            for (auto y : x.second)
                ans[m1[y]]++;

    return ans;
}