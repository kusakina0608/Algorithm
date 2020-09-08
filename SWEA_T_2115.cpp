//
// Created by Kina on 20. 9. 8..
//
// 두 명의 일꾼이 선택한 벌통은 서로 겹치면 안 된다.
// 일꾼이 채취할 수 있는 꿀의 최대 양은 C
#include<iostream>
using namespace std;
int T, test_case, N, M, C;
int map[10][10];

int main(int argc, char** argv) {
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> N >> M >> C;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }
        int MAX_BITS = 1 << M;
        int global_max_1 = 0;
        int global_max_2 = 0;
        for (int i1 = 0; i1 < N; i1++) {
            for (int j1 = 0; j1 <= N - M; j1++) {
                int local_max_1 = 0;
                for (int bits_1 = 0; bits_1 < MAX_BITS; bits_1++) {
                    int sum_1 = 0;
                    int square_sum_1 = 0;
                    for (int n_shift_1 = 0; n_shift_1 < M; n_shift_1++) {
                        if ((bits_1 >> n_shift_1) & 1 == 1) {
                            sum_1 += map[i1][j1 + n_shift_1];
                            square_sum_1 += map[i1][j1 + n_shift_1] * map[i1][j1 + n_shift_1];
                        }
                    }
                    if (sum_1 <= C) {
                        if (local_max_1 < square_sum_1) {
                            local_max_1 = square_sum_1;
                        }
                    }
                }
                int local_max_2 = 0;
                for (int i2 = 0; i2 < N; i2++) {
                    for (int j2 = 0; j2 <= N - M; j2++) {
                        if (i1 == i2 && (j2 <= j1 + M - 1 || j1 <= j2 + M - 1)) { // 채취 불가능
                            continue;
                        }
                        else {
                            for (int bits_2 = 0; bits_2 < MAX_BITS; bits_2++) {
                                int sum_2 = 0;
                                int square_sum_2 = 0;
                                for (int n_shift_2 = 0; n_shift_2 < M; n_shift_2++) {
                                    if ((bits_2 >> n_shift_2) & 1 == 1) {
                                        sum_2 += map[i2][j2 + n_shift_2];
                                        square_sum_2 += map[i2][j2 + n_shift_2] * map[i2][j2 + n_shift_2];
                                    }
                                }
                                if (sum_2 <= C) {
                                    if (local_max_2 < square_sum_2) {
                                        local_max_2 = square_sum_2;
                                    }
                                }
                            }
                        }
                    }
                }
                if (global_max_1 + global_max_2 < local_max_1 + local_max_2) {
                    global_max_1 = local_max_1;
                    global_max_2 = local_max_2;
                }
            }
        }
        cout << '#' << test_case << ' ' << global_max_1 + global_max_2 << '\n';
    }
    return 0;
}