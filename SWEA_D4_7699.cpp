//
// Created by Kina on 20. 8. 31..
//
#include <iostream>
#define MAX_CNT 50000
using namespace std;

char map[20][21];
int R, C, max_cnt;

struct Node {
    int i;
    int j;
    int cnt;
    int check;
    Node* next;
};

Node buf[MAX_CNT];
int bufCnt;
Node *head;

Node* myAlloc(int ci, int cj, int ccnt, int ccheck) {
    buf[bufCnt] = { ci, cj, ccnt, ccheck, head };
    return &buf[bufCnt++];
}

void addNode(int ci, int cj, int ccnt, int ccheck) {
    head = myAlloc(ci, cj, ccnt, ccheck);
}

// Alpha to num (bit shift)
int alpha2num(char c) {
    return c - 'A';
}

int di[] = { -1, 1, 0, 0 };
int dj[] = { 0, 0, -1, 1 };

bool can_go(int i, int j) {
    return 0 <= i && i < R && 0 <= j && j < C;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        bufCnt = 0;
        max_cnt = 0;
        head = NULL;
        cin >> R >> C;
        for (int i = 0; i < R; i++) {
            cin >> map[i];
        }
        addNode(0, 0, 0, 0);
        for (Node* p = head; p != NULL; p = head)
        {
            head = head->next;
            int ci = p->i;
            int cj = p->j;
            int ccnt = p->cnt;
            int cchk = p->check;
            int mark = 1 << alpha2num(map[ci][cj]);
            if ((cchk & mark) == 0) {
                cchk |= mark;
                ccnt++;
                if (max_cnt < ccnt) {
                    max_cnt = ccnt;
                    if (max_cnt == 26) break;
                }
                for (int k = 0; k < 4; k++) {
                    int ni = ci + di[k];
                    int nj = cj + dj[k];
                    if (can_go(ni, nj)) {
                        int new_mark = 1 << alpha2num(map[ni][nj]);
                        if ((cchk & new_mark) == 0) {
                            addNode(ni, nj, ccnt, cchk);
                        }
                    }
                }
            }
        }
        cout << '#' << test_case << ' ' << max_cnt << '\n';
    }
    return 0;
}