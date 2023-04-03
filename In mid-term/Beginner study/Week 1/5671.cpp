// BOJ 5671

/*
중복값을 잘 카운팅해주면 좋다.
값을 삽입할 때 중복된 값을 넣지 않는 set을 사용하였다.
set대신 unordered_set을 사용한 이유는,
set은 요소 삽입에 걸리는 시간 O(lg n)이다.
unordered_set은 정렬을 하지 않기에, 요소 삽입에 걸리는 시간이 O(1)이다.
따라서 unordered_set을 사용해주었다.
*/

#include <iostream>
#include <unordered_set>
#define endl '\n'
#define fastio ios::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int a[5001];

int main() {
	fastio;
	
	for (int i = 1; i <= 5000; ++i) {
		int cur = i;
		int cnt = 0;
		unordered_set<int>s;
		while (cur) {
			s.insert(cur % 10);
			cur /= 10;
			cnt++;
		}
		a[i] = a[i - 1] + ((s.size() == cnt) ? 1 : 0);
	}

	int n, m;
	while (cin >> n >> m) cout << a[m] - a[n-1] << endl;

	return 0;
}