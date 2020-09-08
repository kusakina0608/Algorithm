//
// Created by Kina on 20. 9. 8..
//
#include <iostream>
#define SIZE 15
using namespace std;

int org[SIZE][SIZE];
int map[SIZE][SIZE];
int kill[3][2];
int N, M, D, n_enemy, n_max, tmp, k_idx;
// 15!/(12!*3!)
// MAX 455

bool can_go(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < M;
}

int get_dist(int i1, int j1, int i2, int j2) {
    int d1 = i2 - i1;
    int d2 = j2 - j1;
    if (d1 < 0) d1 = -d1;
    if (d2 < 0) d2 = -d2;
    return d1 + d2;
}

void copy_map() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            map[i][j] = org[i][j];
        }
    }
}

bool push_point(int ci, int cj, int cd) {
    bool selected = false;
    int ni = ci;
    int nj = cj - cd;
    while (!selected && nj < cj) {
        if (can_go(ni, nj)) {
            if (map[ni][nj] == 1) {
                kill[k_idx][0] = ni;
                kill[k_idx][1] = nj;
                k_idx++;
                selected = true;
            }
        }
        ni--;
        nj++;
    }
    while (!selected && ni <= ci) {
        if (can_go(ni, nj)) {
            if (map[ni][nj] == 1) {
                kill[k_idx][0] = ni;
                kill[k_idx][1] = nj;
                k_idx++;
                selected = true;
            }
        }
        ni++;
        nj++;
    }
    return selected;
}

void kill_enemy() {
    for (int i = 0; i < k_idx; i++) {
        map[kill[i][0]][kill[i][1]] = 0;
    }
}

void solve() {
    n_max = 0;
    for (int a = 0; a < M-2; a++) { // Position of an archer A
        for (int b = a + 1; b < M-1; b++) {
            for (int c = b + 1; c < M; c++) {
                copy_map();
                for (int i = N-1; i >= 0; i--) {
                    k_idx = 0;
                    for (int d = 0; d < D; d++) {
                        if (push_point(i, a, d)) break;
                    }
                    for (int d = 0; d < D; d++) {
                        if (push_point(i, b, d)) break;
                    }
                    for (int d = 0; d < D; d++) {
                        if (push_point(i, c, d)) break;
                    }
                    kill_enemy();
                }
                tmp = 0;
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < M; j++) {
                        if (map[i][j] == 1) tmp++;
                    }
                }
                tmp = n_enemy - tmp;
                if (n_max < tmp) {
                    n_max = tmp;
                }
            }
        }
    }
}

int main(void) {
    cin >> N >> M >> D;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> org[i][j];
            if (org[i][j] == 1) {
                n_enemy++;
            }
        }
    }
    solve();
    cout << n_max << '\n';
    return 0;
}