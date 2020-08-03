//
// Created by Kina on 2020/08/02.
//
#include <iostream>
using namespace std;


int N, len;
char str[20];

int k_strlen(){
    while(str[len]!='\0')
        len++;
    return len;
}

void swap(char *a, char *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(){
    for(int i=len-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(str[j]<str[j+1]){
                swap(str+j, str+j+1);
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>str;
    k_strlen();
    bubble_sort();
    //cout<<cnt;
    for(int i=0; i<len; i++){
        cout<<str[i];
    }
    return 0;
}