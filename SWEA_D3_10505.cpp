//
// Created by Kina on 20. 9. 8..
//
#include<iostream>
using namespace std;

int T, test_case, N, sum, tmp, answer;
double mean;

struct Income{
    int value;
    int cnt;
    Income *next;
};
Income *head;
Income buf[50000];
int bufCnt;

void addNode(int v) {
    Income *p = NULL;
    Income *prev = NULL;
    for (p = head; p != NULL && p->value <= v; p = p->next) {
        prev = p;
    }
    if (prev == NULL) {
        buf[bufCnt] = { v, 1, p };
        head = &buf[bufCnt++];
    }
    else {
        if (prev->value == v) { // 카운트 + 1
            (prev->cnt)++;
        }
        else { // 새로운 노드 추가
            buf[bufCnt] = { v, 1, p };
            prev->next = &buf[bufCnt++];
        }
    }
}

int main(int argc, char** argv) {
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        bufCnt = 0;
        answer = 0;
        sum = 0;
        head = NULL;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> tmp;
            sum += tmp;
            addNode(tmp);
        }
        mean = (double)sum / N;
        for (Income* p = head; p != NULL && p->value <= mean; p = p->next) {
            answer += p->cnt;
        }
        cout << '#' << test_case << ' ' << answer << '\n';
    }
    return 0;
}