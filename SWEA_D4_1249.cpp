//
// Created by Kina on 20. 8. 31..
//
#include<iostream>
#define INTMAX 0x7fffffff
using namespace std;

struct Field {
    int depth;
    bool visit;
};

struct Point {
    int i;
    int j;
};

struct Node {
    Point pos;
    int total;
    Node *next;
};

Field map[100][100];
Node buf[110000];
int T, test_case, N, bufCnt;
char c;
Node *head, *current;

int di[] = { -1, 1, 0, 0 };
int dj[] = { 0, 0, -1, 1 };

bool can_go(int i, int j){
    return 0 <= i && i < N && 0 <= j && j < N;
}

void enque(int i, int j, int sum) {
    buf[bufCnt] = { {i, j}, sum, NULL };
    Node* new_node = &buf[bufCnt++];
    if (head == NULL) {
        head = new_node;
        return;
    }
    Node* np_prev = head;
    for (Node* np = head; np != NULL && np->total < new_node->total; np = np->next) {
        np_prev = np;
    }
    new_node->next = np_prev->next;
    np_prev->next = new_node;
    return;
}

Node* deque() {
    Node* rtn = head;
    head = head->next;
    return rtn;
}

// Linked List Priority Queue
int main(int argc, char** argv) {
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> c;
                map[i][j] = { c - '0', false };
            }
        }
        int answer = INTMAX;
        Point start = { 0, 0 };
        Point dest = { N - 1, N - 1 };
        enque(start.i, start.j, 0);
        while (head != NULL) {
            current = deque();
            int ci = current->pos.i;
            int cj = current->pos.j;
            int ct = current->total;
            if (ci == dest.i && cj == dest.j) {
                if(ct < answer)
                    answer = ct;
            }
            if (!map[ci][cj].visit) {
                map[ci][cj].visit = true;
                for (int k = 0; k < 4; k++) {
                    int ni = ci + di[k];
                    int nj = cj + dj[k];
                    if (can_go(ni, nj)) {
                        if (!map[ni][nj].visit) {
                            int nt = ct + map[ni][nj].depth;
                            enque(ni, nj, nt);
                        }
                    }
                }
            }
        }
        cout << '#' << test_case << ' ' << answer << '\n';
    }
    return 0;
}