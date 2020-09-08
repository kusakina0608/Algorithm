//
// Created by Kina on 20. 9. 8..
//
#include<iostream>
using namespace std;

int queue[110000][2]; // i, j
int T, test_case, N, K, max_len, front, rear, max_height, tmp_len;
int map[8][8];
int length[8][8];
int deltas[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void initialize();
void get_inputs();
void clear_length();
bool is_in(int, int);
int bfs(int, int, int);

int main(int argc, char** argv) {
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        initialize();
        get_inputs();
        // 깎는 경우
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 1; k <= K; k++) {
                    tmp_len = bfs(i, j, k);
                    if (max_len < tmp_len) {
                        max_len = tmp_len;
                    }
                }
            }
        }
        // 안깎는 경우
        tmp_len = bfs(0, 0, 0);
        if (max_len < tmp_len) {
            max_len = tmp_len;
        }
        cout << '#' << test_case << ' ' << max_len << '\n';
    }
    return 0;
}

void initialize() {
    max_len = 0;
}

void get_inputs() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
}

void clear_length() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            length[i][j] = 0;
        }
    }
}

bool is_in(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < N;
}

int bfs(int ti, int tj, int tk) {
    register int i;
    register int j;
    register int k;
    clear_length();
    max_height = -9999;
    front = -1;
    rear = -1;
    for (i = 0; i < N; i++) { // Find Start Point
        for (j = 0; j < N; j++) {
            if (max_height < map[i][j]) {
                max_height = map[i][j];
                rear = 0;
                queue[rear][0] = i;
                queue[rear][1] = j;
            }
            else if (max_height == map[i][j]) {
                rear++;
                queue[rear][0] = i;
                queue[rear][1] = j;
            }
        }
    }
    for (k = 0; k <= rear; k++) {
        length[queue[k][0]][queue[k][1]] = 1;
    }
    int local_max_len = 1;
    map[ti][tj] -= tk; // 깎아
    while (front != rear) {
        front++;
        i = queue[front][0];
        j = queue[front][1];
        for (k = 0; k < 4; k++) {
            int ni = i + deltas[k][0];
            int nj = j + deltas[k][1];
            if (is_in(ni, nj)) { // 부지 내부
                if (map[i][j] > map[ni][nj]) { // 이동 가능
                    length[ni][nj] = length[i][j] + 1;
                    local_max_len = length[ni][nj];
                    rear++;
                    queue[rear][0] = ni;
                    queue[rear][1] = nj;
                }
            }
        }
    }
    map[ti][tj] += tk; // 깎아
    return local_max_len;
}
