//
// Created by Kina on 20. 8. 31..
//
#include <string>
#include <vector>

using namespace std;

struct Node {
    bool end;
    Node* next[10];
};

Node buf[15000000];
int bufCnt;
bool ans;
Node *head;

Node* myAlloc() {
    buf[bufCnt] = { false, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL} };
    return &buf[bufCnt++];
}

void addNumber(string s) {
    Node* p = head;
    bool flag = false;
    for (int i = 0; i < s.length(); i++) {
        int num = s[i] - '0';
        if ((p->next)[num] == NULL) {
            flag = true;
            (p->next)[num] = myAlloc();
        }
        p = (p->next)[num];
        if (p->end) {
            ans = false;
        }
    }
    if (flag == false) {
        ans = false;
    }
    p->end = true;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    ans = true;
    bufCnt = 0;
    head = myAlloc();
    for (int i = 0; i < phone_book.size() && ans; i++) {
        addNumber(phone_book[i]);
    }
    answer = ans;
    return answer;
}