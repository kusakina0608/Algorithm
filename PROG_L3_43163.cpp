//
// Created by Kina on 20. 9. 8..
//
#include <string>
#include <vector>
using namespace std;

bool check[50];
string queue[10000];
int level[10000];
int front, rear;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    front = -1;
    rear = -1;
    int strlen = begin.length();
    int veclen = words.size();
    for (int i = 0; i < 50; i++) {
        check[i] = false;
    }
    queue[++rear] = begin;
    level[rear] = 0;
    string cur;
    int cl;
    while (front != rear) {
        cur = queue[++front];
        cl = level[front];
        if (cur == target) {
            break;
        }
        for (int i = 0; i < veclen; i++) {
            if (!check[i]) {
                int cnt = 0;
                for (int j = 0; j < strlen; j++) {
                    if (cur[j] != words[i][j]) {
                        cnt++;
                    }
                }
                if (cnt == 1) {
                    queue[++rear] = words[i];
                    level[rear] = cl + 1;
                    check[i] = true;
                }
            }
        }
    }
    if (cur == target) {
        answer = cl;
    }
    else {
        answer = 0;
    }

    return answer;
}