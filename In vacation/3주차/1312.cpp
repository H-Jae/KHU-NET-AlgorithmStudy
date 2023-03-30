// BOJ 1312 - 유기농 배추

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int field[51][51];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int head = -1, rear = -1;
int cur_x, cur_y;
int next_x, next_y;

int M, N, K;
queue<pair<int, int>> q;

bool check(int a, int b) {
	return (a >= 0 && a < M && b >= 0 && b < N);
}

void out(int a) {
	printf("%d\n", a);
}

void BFS(int a, int b) {
	q.push(pair < int, int > (a, b));
    field[a][b] = 0;
	while (!q.empty()) {
		cur_x = q.front().first;
		cur_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			next_x = cur_x + dx[i];
			next_y = cur_y + dy[i];
			
			if (check(next_y, next_x) && field[next_x][next_y]) {
                field[next_x][next_y] = 0;
				q.push(pair < int, int >(next_x, next_y));
			}
		}
	}
	while (!q.empty()) {
		q.pop();
	}
}

int main() {
	int T; 
	int x, y;
	int cout = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &M, &N, &K);

		for (int l = 0; l < N; l++) { 
			for (int I = 0; I < M; I++) {
				field[l][I] = 0;
			}
		}

		for (int l = 0; l < K; l++) { 
			int a, b;
			scanf("%d %d", &a, &b);
				field[b][a] = 1;
		}



		for (int l = 0; l < N; l++) {
			for (int I = 0; I < M; I++) {
				if (field[l][I] == 1) {
					BFS(l, I); 
					
					
					cout++;
				}
			}
		}
		out(cout);
		cout = 0;
		
	}

}