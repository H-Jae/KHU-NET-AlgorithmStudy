/*
BOJ 2527

Algorithm : Case work

경우의 수 탐색 -> 조건 별로 나누기
실수할 수 있는 여지가 좀 있다. 

*/

#include <cstdio>
int main() {
	for (int a, s, d, f, q, w, e, r; ~scanf("%d%d%d%d%d%d%d%d", &a, &s, &d, &f, &q, &w, &e, &r);) {
		if ((a == e || q == d) && (s == r || w == f)) printf("c");
		else if (e < a || d < q || r < s || f < w) printf("d");
		else if (a == e || q == d || s == r || w == f) printf("b");
		else printf("a");
		printf("\n");
	}
}