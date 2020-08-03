//
// Created by Kina on 2020/02/08.
//
#include <iostream>
#include <cstring>
using namespace std;

int main(void){
    char a[31];
    char b[31];

    cin>>a>>b;

    int len_a, len_b;
    len_a=strlen(a);
    len_b=strlen(b);
    int pos_i, pos_j;
    bool flag=true;
    for(pos_i=0; pos_i<len_a; pos_i++){
        for(pos_j=0; pos_j<len_b; pos_j++) {
            if (a[pos_i] == b[pos_j]){
                flag=false;
                break;
            }
        }
        if(!flag) break;
    }
    for(int i=0; i<len_b; i++) {
        for (int j=0; j<len_a; j++) {
            if(j==pos_i){
                cout<<b[i];
            }else if(i==pos_j){
                cout<<a[j];
            }else{
                cout<<'.';
            }
        }
        cout<<endl;
    }
    return 0;
}