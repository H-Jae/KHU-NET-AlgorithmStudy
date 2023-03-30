// BOJ 11054 - 가장 긴 바이토닉 부분 수열

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define endl '\n'
#define fastio std::cin.tie(nullptr)->sync_with_stdio(false)

using namespace std;

constexpr int S = 1e3;
int N;
int num[S+1];
int ldp[S+1], rdp[S+1];

int main() {

	fastio;

	cin >> N;

	for (int i = 0; i < N; ++i) { cin >> num[i]; ldp[i] = 1, rdp[i] = 1; }

	for (int i = 0; i < N; ++i) for (int j = i - 1; j >= 0; j--) if ((num[j] < num[i]) && (ldp[i] < ldp[j] + 1)) ldp[i] = ldp[j] + 1;

	for (int i = N - 1; i >= 0; --i) for (int j = i + 1; j < N; j++) if ((num[j] < num[i]) && (rdp[i] < rdp[j] + 1)) rdp[i] = rdp[j] + 1;

	int ans = 0;

	for (int i = 0; i < N; ++i) ans = max(ans, (ldp[i] + rdp[i]));

	ans--;
	cout << ans;

    return false;
}