// BOJ 25183

/*
문제에 주어진 대로 구현을 잘 하면 풀 수 있는 문제다.
*/

#include <bits/stdc++.h>

using namespace std;

string op[2] = { "YES", "NO" };
string s;
int n, cnt, ans;
char pos = 'x';

int main() {

	cin >> n >> s;

	for (int i = 0; i < n; ++i) {
		char cur = s[i];
		if (pos == 'x') {
			pos = cur;
			cnt = 1;
		}
		else {
			if (abs(pos - cur) == 1) {
				cnt++;
			}
			else {
				ans = max(cnt, ans);
				cnt = 1;
			}
			pos = cur;
		}
	}

	ans = max(cnt, ans);
	
	(ans >= 5) ? cout << op[0] : cout << op[1];

	return 0;
}