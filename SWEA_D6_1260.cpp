//
// Created by Kina on 20. 9. 8..
//
#include<iostream>
using namespace std;

int T, test_case, N, head, arrlen;
int matrix[100][100];
bool visit[100][100];
int front[100];
int back[100];
int arr[100];
int mat[100][100];

int di[] = { -1, 0, 1, 0 };
int dj[] = { 0, 1, 0, -1 };

void k_init_globals();
void k_get_input();
bool k_can_go(int, int);
bool k_left_top(int, int);
void k_brute_force();
void dp();

int main(int argc, char** argv) {
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        k_init_globals();
        k_get_input();
        k_brute_force();
        dp();
        cout <<'#'<<test_case<<' '<< mat[1][arrlen-1] << '\n';
    }
    return 0;
}

void k_solve(int left, int right) {
    int min_idx = left;

}

void k_init_globals() {
    for (int i = 0; i < 100; i++) {
        front[i] = 0;
        back[i] = 0;
    }
    head = 0;
    arrlen = 0;
}

void k_get_input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
}

bool k_can_go(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < N;
}

bool k_left_top(int i, int j) {
    int ni = i + di[0];
    int nj = j + dj[0];
    if (k_can_go(ni, nj) && matrix[ni][nj] != 0) {
        return false;
    }
    ni = i + di[3];
    nj = j + dj[3];
    if (k_can_go(ni, nj) && matrix[ni][nj] != 0) {
        return false;
    }
    return true;
}

void k_brute_force() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] != 0) {
                if (!visit[i][j]) {
                    if (k_left_top(i, j)) {
                        int nrow = 0;
                        int ncol = 0;
                        int diff = 0;
                        while (i + diff < N && matrix[i + diff][j] != 0) {
                            diff++;
                            nrow++;
                        }
                        diff = 0;
                        while (j + diff < N && matrix[i][j + diff] != 0) {
                            diff++;
                            ncol++;
                        }
                        front[ncol] = nrow;
                        back[nrow] = ncol;
                    }
                }
            }
        }
    }
    while (front[head] == 0) {
        head++;
    }
    while (front[head] != 0) {
        head = front[head];
    }
    while (head != 0) {
        arr[arrlen++] = head;
        head = back[head];
    }
}

void dp() {
    int i = 1;
    int j = 1;
    while (j < arrlen) {
        i = 1;
        while (i + j < arrlen) {
            int min = 2147483647;
            for (int k = i; k < i+j; k++) {
                int tmp = mat[i][k] + mat[k + 1][i + j] + arr[i - 1] * arr[k] * arr[i + j];
                if (tmp < min) {
                    min = tmp;
                }
            }
            mat[i][i + j] = min;
            i++;
        }
        j++;
    }
}