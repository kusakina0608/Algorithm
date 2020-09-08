//
// Created by Kina on 20. 9. 8..
//
#include<iostream>
#define SIZE 1000
using namespace std;

int T, test_case, N, buf, answer;
int adjacency[SIZE][SIZE];

void Floyd_Warshall() {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            if (i == k) continue;
            for (int j = i+1; j < N; j++) {
                if (j == k || j == i) continue;
                int d1 = adjacency[i][j];
                int d2 = adjacency[i][k] + adjacency[k][j];
                adjacency[i][j] = d1 < d2 ? d1 : d2;
                adjacency[j][i] = adjacency[i][j];
            }
        }
    }
}

int main(int argc, char** argv) {
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> N;
        answer = 2147483647;
        int tmp = N * N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> buf;
                adjacency[i][j] = buf == 0 ? 9999 : buf;
                if (i == j) {
                    adjacency[i][j] = 0;
                }
            }
        }
        Floyd_Warshall();
        for (int i = 0; i < N; i++) {
            int sum = 0;
            for (int j = 0; j < N; j++) {
                sum += adjacency[i][j];
            }
            if (sum < answer) {
                answer = sum;
            }
        }
        cout << '#' << test_case << ' ' << answer << '\n';
    }
    return 0;
}