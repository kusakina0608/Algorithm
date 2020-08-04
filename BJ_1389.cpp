//
// Created by Kina on 2020/08/04.
//
#include <iostream>
using namespace std;

int N, M, front, rear, min_idx;
bool relation[101][101];
int sum[101];
int k_v_queue[10000];
int k_d_queue[10000];
bool visited[101];

void reset_visit() {
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}
}

void get_input() {
	cin >> N >> M;
	int a, b;
	for(int i=0; i<M; i++){
		cin >> a >> b;
		relation[a][b] = true;
		relation[b][a] = true;
	}
}

void bfs(int v) {
	int cv, cd, local_sum;
	reset_visit();
	front = rear = -1;
	rear++;
	k_v_queue[rear] = v;
	k_d_queue[rear] = 0;
	while (front != rear) {
		front++;
		cv = k_v_queue[front];
		cd = k_d_queue[front];
		if (!visited[cv]) {
			visited[cv] = true;
			sum[v] += cd;
			for (int i = 1; i <= N; i++) {
				if (!visited[i] && relation[cv][i]) {
					rear++;
					k_v_queue[rear] = i;
					k_d_queue[rear] = cd + 1;
				}
			}
		}
	}
}

int go() {
	min_idx = 1;
	for (int i = 1; i <= N; i++) {
		bfs(i);
		if (sum[min_idx] > sum[i]) {
			min_idx = i;
		}
	}
	return min_idx;
}

int main(void) {
	get_input();
	cout << go();
}