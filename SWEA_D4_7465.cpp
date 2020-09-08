//
// Created by Kina on 20. 9. 8..
//
#include<iostream>
using namespace std;

int T, test_case, N, M, v1, v2, answer;

// p[i] == 0은 자기 자신을 의미함
int p[128];

int find_set(int a) {
    if (p[a] != a) {
        p[a] = find_set(p[a]);
        return p[a];
    }
    else {
        return a;
    }
}

void make_set(int a, int b) {
    int pa = find_set(a);
    int pb = find_set(b);
    p[pa] = pb;
}

int main(int argc, char** argv) {
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        answer = 0;
        for (int i = 0; i < 128; i++) {
            p[i] = i;
        }
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            cin >> v1 >> v2;
            make_set(v1, v2);
        }
        for (int i = 1; i <= N; i++) {
            if (p[i] == i) answer++;
        }
        cout << '#' << test_case << ' ' << answer << '\n';
    }
    return 0;
}