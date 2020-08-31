//
// Created by Kina on 20. 8. 31..
//
#include <string>
#include <vector>
#define N_BUCKET 283947
using namespace std;

int stack[N_BUCKET+1];		// hash값 저장
int counting[N_BUCKET+1];		// hash를 인덱스로 하여 카운팅
int top;

void init_globals() {
    for (int i = 0; i <= N_BUCKET; i++) {
        stack[i] = 0;
        counting[i] = 0;
    }
    top = 0;
}

int my_hash(string str) {
    int len = str.length();
    int sum = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] != '_') {
            sum += (str[i])*7 + 1;
        }
        else {
            sum += 27;
        }
    }
    return sum % N_BUCKET;
}

void hashmap(string str) {
    int hash = my_hash(str);
    if (counting[hash] == 0) {
        stack[top++] = hash;
    }
    counting[hash]++;
}

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    init_globals();
    int n_clo = clothes.size();
    for (int i = 0; i < n_clo; i++) {
        hashmap(clothes[i][1]);
    }
    for (int i = 0; i < top; i++) {
        answer *= (counting[stack[i]]+1);
    }
    return answer-1;
}