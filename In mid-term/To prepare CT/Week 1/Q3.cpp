/*
Q3 : 주차 요금 계산

조건을 잘 따져서 풀면 어려울 것 없는 문제였다.

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> car;
    for (auto x : records) {
        int t = 0;
        string s, carnum, state;

        stringstream ss(x);
        ss >> s >> carnum >> state;

        if (state == "IN") {
            t -= (s[0] - 48) * 600 + (s[1] - 48) * 60 + (s[3] - 48) * 10 + (s[4] - 48);
            car[carnum] += t;
        }
        else {
            t += (s[0] - 48) * 600 + (s[1] - 48) * 60 + (s[3] - 48) * 10 + (s[4] - 48);
            car[carnum] += t;
        }
    }
    for (auto x : car) {
        int t = 0;
        if (car[x.first] <= 0) {
            t = 1439 + car[x.first];
        }
        else {
            t = car[x.first];
        }
        int fee = 0;
        if (t > fees[0]) {
            fee = fees[1] + ((t + fees[2] - 1 - fees[0]) / fees[2]) * fees[3];
        }
        else {
            fee = fees[1];
        }
        answer.push_back(fee);

    }

    return answer;
}