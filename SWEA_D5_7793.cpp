//
// Created by Kina on 20. 8. 31..
//
#include<iostream>
using namespace std;

int T, test_case, N, M;

struct Point {
    int i;
    int j;
};

struct Node {
    Point pos;
    int time;
    Node *next;
};

Node *hyerin_head, *hyerin_last;
Node *devil_head, *devil_last;
Point goddess;
char map[64][64];
bool visited[64][64];
int di[] = { -1, 1, 0, 0 };
int dj[] = { 0, 0, -1, 1 };

Node buf[110000];
int bufCnt;

void enque(Node **headptr, Node **lastptr, int i, int j, int t) {
    if (*headptr == NULL) {
        buf[bufCnt] = { {i, j}, t, NULL };
        (*headptr) = &buf[bufCnt++];
        (*lastptr) = (*headptr);
    }
    else {
        buf[bufCnt] = { {i, j}, t, NULL };
        (*lastptr)->next = &buf[bufCnt++];
        (*lastptr) = (*lastptr)->next;
    }
}

Node* deque(Node **headptr, Node **lastptr) {
    if ((*headptr) == NULL) return NULL;
    Node* rtn = (*headptr);
    (*headptr) = (*headptr)->next;
    if ((*headptr) == NULL) {
        (*lastptr) = NULL;
    }
    return rtn;
}

void get_input() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf(" %c", &map[i][j]);
            visited[i][j] = false;
            if (map[i][j] == 'S') {
                enque(&hyerin_head, &hyerin_last, i, j, 0);
                map[i][j] = '.';
                visited[i][j] = true;
            }
            else if (map[i][j] == '*') {
                enque(&devil_head, &devil_last, i, j, 0);
            }
            else if (map[i][j] == 'D') {
                goddess.i = i;
                goddess.j = j;
            }
        }
    }
}

bool can_go(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < M;
}

bool is_normal(int i, int j) {
    return (map[i][j] == '.') || (map[i][j] == 'D');
}

void spread(int time) {
    while (devil_head != NULL && devil_head->time == time) {
        Node* p = deque(&devil_head, &devil_last);
        int ci = p->pos.i;
        int cj = p->pos.j;
        map[ci][cj] = '*';
        for (int k = 0; k < 4; k++) {
            int ni = ci + di[k];
            int nj = cj + dj[k];
            if (can_go(ni, nj)) {
                if (map[ni][nj] == '.') {
                    map[ni][nj] = '*';
                    enque(&devil_head, &devil_last, ni, nj, time + 1);
                }
            }
        }
    }
}


int bfs() {
    int curtime = 0;
    Node* cur;
    Point curpos;
    while (hyerin_head != NULL) {
        cur = deque(&hyerin_head, &hyerin_last);
        curpos = cur->pos;
        int ci = curpos.i;
        int cj = curpos.j;
        int ct = cur->time;
        if (curtime == ct) {
            spread(curtime++);
        }
        for (int k = 0; k < 4; k++) {
            int ni = ci + di[k];
            int nj = cj + dj[k];
            if (can_go(ni, nj)) {
                if (is_normal(ni, nj)) {
                    if (!visited[ni][nj]) {
                        visited[ni][nj] = true;
                        if (ni == goddess.i && nj == goddess.j) {
                            return ct + 1;
                        }
                        enque(&hyerin_head, &hyerin_last, ni, nj, ct + 1);
                    }
                }
            }
        }
    }
    return -1;
}

void init_globals() {
    hyerin_head = NULL;
    hyerin_last = NULL;
    devil_head = NULL;
    devil_last = NULL;
    bufCnt = 0;
}

int main(int argc, char** argv) {
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; ++test_case) {
        init_globals();
        get_input();
        int result = bfs();
        if (result < 0) printf("#%d GAME OVER\n", test_case);
        else printf("#%d %d\n", test_case, result);
    }
    return 0;
}