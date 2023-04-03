// BOJ 11008

/*
직관적으로 문제를 보면 해결 방법이 보인다.

Plus : 혹시 문제를 풀다가 연산이 너무 낭비된다거나 효율적이지 못하다는
느낌을 받은 적이 있다면, 생각을 잘 했다.

이 문제를 최적화한 알고리즘이 바로 KMP 알고리즘 (문자열 검색 알고리즘)이다.
접두사와 접미사를 이용해서 접근한다.
문제를 풀다가 궁금증이 들었다면 이 알고리즘을 공부해보자.
*/

#include <iostream>
#define endl '\n'
using namespace std;

int main() {
	int t;
	cin >> t;
	string s, w;
	while (t--) {
		cin >> s >> w;
		int cnt = 0;
		for (int i = 0; i < s.size() - w.size() + 1; ++i) {
			int flg = 1;
			for (int j = 0; j < w.size(); ++j) {
				if (s[i + j] == w[j]) continue;
				flg = 0;
				break;
			}
			cnt += flg;
			if (flg) i += w.size() - 1;
		}
		cout << (s.size() - w.size() * cnt) + cnt << endl;
	}

	return 0;
}
