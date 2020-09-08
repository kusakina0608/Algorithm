//
// Created by Kina on 20. 9. 8..
//
#include<iostream>
using namespace std;

int T, test_case, N, val1, val2, cnt;

struct Point {
    int a;
    int b;
    Point* next;
};

Point buf[1024];
int bufCnt;
Point *head;

void addNode(int, int);

int main(int argc, char** argv) {
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cnt = 0;
        head = NULL;
        bufCnt = 0;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> val1 >> val2;
            addNode(val1, val2);
        }
        for (Point *p = head; p != NULL; p = p->next) {
            for (Point *q = p->next; q != NULL; q = q->next) {
                if (p->b > q->b) {
                    cnt++;
                }
            }
        }
        cout << '#' << test_case << ' ' << cnt<<'\n';
    }
    return 0;
}


void addNode(int a, int b) {
    Point *p = NULL;
    Point *prev = NULL;
    for (p = head; p != NULL && p->a < a; p = p->next) {
        prev = p;
    }
    buf[bufCnt] = { a, b, p };
    if (prev != NULL) {
        prev->next = &buf[bufCnt];
    }
    else { // 맨 앞에 삽입되는 경우
        head = &buf[bufCnt];
    }
    bufCnt++;
}