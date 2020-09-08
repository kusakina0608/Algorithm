//
// Created by Kina on 20. 9. 8..
//
// 재귀호출을 통한 완전탐색
// 최적화
// 1) 현재 row 상태 저장
// 2) A 약품 투입
// 3) 원상복구
// 4) B 약품 투입
#include<iostream>
using namespace std;
int T, test_case, N, M, K, answer, state, cnt, current, counting;
int map[13][20];
int check[13];
bool flag;

void dfs(int index, int cnt) {
    if (answer <= cnt) return;
    register int i, j;
    if (index == N) {
        for (j = 0; j < M; j++) {
            flag = false;
            state = -1;
            counting = 0;
            for (i = 0; i < N; i++) {
                current = check[i] == -1 ? map[i][j] : check[i];
                if (current == state) {
                    counting++;
                }
                else {
                    counting = 1;
                    state = current;
                }
                if (counting >= K) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                return;
            }
        }
        if(cnt < answer){
            answer = cnt;
        }
        return;
    }
    else {
        dfs(index + 1, cnt);
        check[index] = 1;
        dfs(index + 1, cnt + 1);
        check[index] = 0;
        dfs(index + 1, cnt + 1);
        check[index] = -1;
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    register int i, j;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> N >> M >> K;
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                cin >> map[i][j];
            }
        }
        for (i = 0; i < N; i++) {
            check[i] = -1;
        }
        answer = 13;
        dfs(0, 0);
        cout << '#' << test_case << ' ' << answer << '\n';
    }
    return 0;
}