//
// Created by Kina on 20. 8. 31..
//
#include <string>
#include <vector>
#define B_SIZE 200000
using namespace std;

struct Node {
    string name;
    Node* next;
};

Node* bucket[B_SIZE];

int my_hash(string s) {
    unsigned int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += s[i] - 'a' + 1;
    }
    return sum % B_SIZE;
}

Node buf[100000];
int bufCnt;

Node* myAlloc(string name, Node* next) {
    buf[bufCnt] = { name, next };
    return &buf[bufCnt++];
}

void addNode(string name) {
    int hash = my_hash(name);
    bucket[hash] = myAlloc(name, bucket[hash]);
}

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    bufCnt = 0;
    for (int i = 0; i < B_SIZE; i++) {
        bucket[i] = NULL;
    }
    for (int i = 0; i < completion.size(); i++) {
        addNode(completion[i]);
    }
    for (int i = 0; i < participant.size(); i++) {
        int hash = my_hash(participant[i]);
        bool flag = false;
        Node* prev = NULL;
        for (Node* p = bucket[hash]; p != NULL; p = p->next) {
            if (p->name == participant[i]) {
                if(prev != NULL){
                    prev->next = p->next;
                }
                else {
                    bucket[hash] = p->next;
                }
                flag = true;
                break;
            }
            prev = p;
        }
        if (!flag) {
            answer = participant[i];
            break;
        }
    }
    return answer;
}