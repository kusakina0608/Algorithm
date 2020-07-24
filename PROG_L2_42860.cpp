//
// Created by Kina on 2020/07/19.
//
#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

char res[32];

int solution(string name) {
    int answer = 0;
    int len = name.size();
    memset(res, 0, sizeof(char)*32);
    for(int i=0; i<len; i++){
        res[i] = 'A';
    }
    string target(res);
    int idx = 0;
    int cur = 0;
    while(target != name){
        int min = -1;
        cout<<"===="<<endl;
        cout<<target<<endl;
        for(int i=0; i<len; i++){
            if(target[i] != name[i]) {
                int dist = i<cur?cur-i:i-cur;
                if(len-dist<dist){
                    dist = len-dist;
                }
                cout<<dist<<endl;
                if(min<0 || dist<min){
                    idx = i;
                    min = dist;
                }
            }
        }
        cur = idx;
        int cnt = target[cur]<name[cur]?name[cur]-target[cur]:target[cur]-name[cur];
        if(cnt>13){
            cnt = 26-cnt;
        }
        target[cur] = name[cur];
        answer += min + cnt;
    }
    return answer;
}

int main(void){
    cout<<solution("JBAWB");
}