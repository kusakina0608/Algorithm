//
// Created by Kina on 20. 9. 8..
//
#include<iostream>
using namespace std;

int map[50][50];
bool check[50][50];
int n_delta[8] = { 0, 4, 2, 2, 2, 2, 2, 2 };
int ***deltas;
int T, test_case, N, M, R, C, L, answer;

void set_delta();
void get_input();
void reset_globals();

int queue[550000][2];
int front, rear;

int main(int argc, char** argv) {
    set_delta();
    cin >> T;
    register int i, j, ni, nj;
    for (test_case = 1; test_case <= T; ++test_case) {
        answer = 0;
        get_input();
        ++rear;
        queue[rear][0] = R;
        queue[rear][1] = C;
        ++rear;
        queue[rear][0] = -1;
        queue[rear][1] = -1;
        int hour = 1;
        while (front != rear) {
            ++front;
            i = queue[front][0];
            j = queue[front][1];
            if (i == -1 && j == -1) {
                hour++;
                ++rear;
                queue[rear][0] = -1;
                queue[rear][1] = -1;
                if (hour > L) {
                    break;
                }
                continue;
            }
            if (!check[i][j]) {
                check[i][j] = true;
                answer++;
                int idx = map[i][j];
                int nk = n_delta[idx];
                for (int k = 0; k < nk; k++) {
                    ni = i + deltas[idx][k][0];
                    nj = j + deltas[idx][k][1];
                    if (0 <= ni && ni < N && 0 <= nj && nj < M) {
                        if (!check[ni][nj]) {
                            if (map[ni][nj] != 0) {
                                bool flag = false;
                                int tmp_idx = map[ni][nj];
                                int tmp_nk = n_delta[tmp_idx];
                                for (int tmp_k = 0; tmp_k < tmp_nk; tmp_k++) {
                                    int nni = ni + deltas[tmp_idx][tmp_k][0];
                                    int nnj = nj + deltas[tmp_idx][tmp_k][1];
                                    if (nni == i && nnj == j) {
                                        flag = true;
                                    }
                                }
                                if (flag) {
                                    rear++;
                                    queue[rear][0] = ni;
                                    queue[rear][1] = nj;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << '#' << test_case << ' ' << answer << '\n';
        reset_globals();
    }
    return 0;
}

void set_delta() {
    deltas = new int**[8];
    deltas[0] = NULL;
    deltas[1] = new int*[4];
    deltas[1][0] = new int[2];
    deltas[1][0][0] = -1;
    deltas[1][0][1] = 0;
    deltas[1][1] = new int[2];
    deltas[1][1][0] = 1;
    deltas[1][1][1] = 0;
    deltas[1][2] = new int[2];
    deltas[1][2][0] = 0;
    deltas[1][2][1] = -1;
    deltas[1][3] = new int[2];
    deltas[1][3][0] = 0;
    deltas[1][3][1] = 1;

    deltas[2] = new int*[2];
    deltas[2][0] = new int[2];
    deltas[2][0][0] = -1;
    deltas[2][0][1] = 0;
    deltas[2][1] = new int[2];
    deltas[2][1][0] = 1;
    deltas[2][1][1] = 0;

    deltas[3] = new int*[2];
    deltas[3][0] = new int[2];
    deltas[3][0][0] = 0;
    deltas[3][0][1] = -1;
    deltas[3][1] = new int[2];
    deltas[3][1][0] = 0;
    deltas[3][1][1] = 1;

    deltas[4] = new int*[2];
    deltas[4][0] = new int[2];
    deltas[4][0][0] = -1;
    deltas[4][0][1] = 0;
    deltas[4][1] = new int[2];
    deltas[4][1][0] = 0;
    deltas[4][1][1] = 1;

    deltas[5] = new int*[2];
    deltas[5][0] = new int[2];
    deltas[5][0][0] = 1;
    deltas[5][0][1] = 0;
    deltas[5][1] = new int[2];
    deltas[5][1][0] = 0;
    deltas[5][1][1] = 1;

    deltas[6] = new int*[2];
    deltas[6][0] = new int[2];
    deltas[6][0][0] = 1;
    deltas[6][0][1] = 0;
    deltas[6][1] = new int[2];
    deltas[6][1][0] = 0;
    deltas[6][1][1] = -1;

    deltas[7] = new int*[2];
    deltas[7][0] = new int[2];
    deltas[7][0][0] = -1;
    deltas[7][0][1] = 0;
    deltas[7][1] = new int[2];
    deltas[7][1][0] = 0;
    deltas[7][1][1] = -1;
}

void get_input() {
    front = -1;
    rear = -1;
    cin >> N >> M >> R >> C >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
}


void reset_globals() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            map[i][j] = 0;
            check[i][j] = false;
        }
    }
}