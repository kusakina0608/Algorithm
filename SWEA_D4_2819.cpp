//
// Created by Kina on 20. 9. 8..
//
#include<iostream>
using namespace std;

int map[4][4];
const int deltas[][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
bool bucket[10000000];
int stack[10000000];
int top;

bool is_in(int i, int j) {
    return 0 <= i && i < 4 && 0 <= j && j < 4;
}

void dfs_recur(int i, int j, int cnt, int hash) {
    if (cnt == 0) {
        if (!bucket[hash]) {
            bucket[hash] = true;
            stack[top] = hash;
            top++;
        }
        return;
    }
    for (int k = 0; k < 4; k++) {
        int ni = i + deltas[k][0];
        int nj = j + deltas[k][1];
        if (is_in(ni, nj)) {
            dfs_recur(ni, nj, cnt - 1, hash * 10 + map[ni][nj]);
        }
    }
}

int main(int argc, char** argv) {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> map[i][j];
            }
        }
        top = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                dfs_recur(i, j, 6, map[i][j]);
            }
        }
        cout << '#' << test_case << ' ' << top << '\n';
        for (int i = 0; i < top; i++) bucket[stack[i]] = false;
    }
    return 0;
}