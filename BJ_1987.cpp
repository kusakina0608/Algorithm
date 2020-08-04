//
// Created by Kina on 2020/08/04.
//
#include <iostream>
using namespace std;

int R, C, top, max_depth;
int k_i_stack[5000];
int k_j_stack[5000];
int k_depth_stack[5000];
int k_bits_stack[5000];
char map[20][20];

int di[] = { 0, 0, -1, 1 };
int dj[] = { 1, -1, 0, 0 };

bool k_can_go(int i, int j) {
	return 0 <= i && i < R && 0 <= j && j < C;
}

int alpha2bits(char c) {
	return 1 << (int)(c - 'A');
}

void dfs() {
	top = -1;
	max_depth = 0;
	top++;
	k_i_stack[top] = 0;
	k_j_stack[top] = 0;
	k_depth_stack[top] = 0;
	k_bits_stack[top] = 0;
	while (top>-1) {
		//cout << "top: " << top << '\n';
		int ci = k_i_stack[top];
		int cj = k_j_stack[top];
		int cd = k_depth_stack[top];
		int cb = k_bits_stack[top];
		top--;
		int cbit = alpha2bits(map[ci][cj]);
		if ((cb&cbit) == 0) {// && cb&cbit==0
			//cout << "visit (" << ci << ", " << cj << "): " << map[ci][cj]<<'\n';
			cd++;
			cb |= cbit;
			if (max_depth < cd) max_depth = cd;
			for (int k = 0; k < 4; k++) {
				int ni = ci + di[k];
				int nj = cj + dj[k];
				if (k_can_go(ni, nj)) {
					int nbit = alpha2bits(map[ni][nj]);
					if ((cb&nbit) == 0) {
						top++;
						k_i_stack[top] = ni;
						k_j_stack[top] = nj;
						k_depth_stack[top] = cd;
						k_bits_stack[top] = cb;
					}
				}
			}
		}
	}
}

int main(void) {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
	dfs();
	cout << max_depth;
	return 0;
}