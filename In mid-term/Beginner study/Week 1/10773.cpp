// BOJ 10773

/*
스택을 사용하면 간단하게 풀린다.
스택을 공부하며 문제를 풀 때라 스택을 구현해서 풀었다.
스택에 대해 모른다면 공부하고 다시 풀어보자
*/

#include <iostream>

int arr[100001];

int last = 0;

void push(int a) {
	arr[last] = a;
	last++;
}

int main() {
	int K, sum;
	sum = 0;

	scanf("%d", &K);

	int d;

	for (int i = 0; i < K; i++) {
		scanf("%d", &d);
		if (d == 0) {
			last--;
		}
		else { push(d); }
	}
	for (int i = 0; i < last; i++) {
		sum = sum + arr[i];
	}

	printf("%d", sum);
}