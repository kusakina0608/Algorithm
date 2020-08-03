// TODO read
// Created by LKina on 2020-02-27.
//
#include <iostream>
#include <stack>
using namespace std;

int main(void){
    int n, max=1, max_i=0;
    scanf("%d", &n);
    int* seq=new int[n];
    int* len=new int[n];
    int* idx=new int[n];
    scanf("%d", &seq[0]);
    len[0]=1;
    idx[0]=-1;
    for(int i=1; i<n; i++){
        scanf("%d", &seq[i]);
        len[i]=1; idx[i]=-1;
        for(int j=0; j<i; j++){
            if(seq[j]<seq[i] && len[j]>=len[i]){
                len[i]=len[j]+1;
                idx[i]=j;
            }
        }
        if(max<len[i]){
            max=len[i];
            max_i=i;
        }
    }
    printf("%d\n", max);
    int i=max_i;
    stack<int> s;
    while(i!=-1){
        s.push(seq[i]);
        i=idx[i];
    }
    while(!s.empty()){
        printf("%d ", s.top());
        s.pop();
    }
    delete[] seq;
    return 0;
}