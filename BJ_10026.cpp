#define R 'R'
#define G 'G'
#define B 'B'
#include <iostream>

using namespace std;

int N;
char pic[100][100];
bool visited[100][100];

int di[] = { 0, 0, 1, -1 };
int dj[] = { 1, -1, 0, 0 };

int k_can_go(int i, int j) {
	return 0 <= i && i < N && 0 <= j && j < N;
}

void get_input() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> pic[i][j];
		}
	}
}

void reset_visit() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
}

void cluster1(char c, int i, int j) {
	visited[i][j] = true;
	for (int k = 0; k < 4; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		if (k_can_go(ni, nj) && !visited[ni][nj] && pic[ni][nj]==c) {
			cluster1(c, ni, nj);
		}
	}
}

bool color_check(char c1, char c2) {
	if (c1 == B) {
		if (c2 == B) {
			return true;
		}
		return false;
	}
	else {
		if (c2 == B) {
			return false;
		}
		return true;
	}
}

void cluster2(char c, int i, int j) {
	visited[i][j] = true;
	for (int k = 0; k < 4; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		if (k_can_go(ni, nj) && !visited[ni][nj] && color_check(pic[ni][nj], c)) {
			cluster2(c, ni, nj);
		}
	}
}

int go1() {
	reset_visit();
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				cnt++;
				cluster1(pic[i][j], i, j);
			}

		}
	}
	return cnt;
}

int go2() {
	reset_visit();
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				cnt++;
				cluster2(pic[i][j], i, j);
			}
		}
	}
	return cnt;
}

int main(void) {
	cin >> N;
	get_input();
	cout << go1() << ' ' << go2();
}