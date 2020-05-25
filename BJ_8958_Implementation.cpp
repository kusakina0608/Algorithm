//
// Created by Kina on 2020/02/09.
//
#include <iostream>
#include <cstring>
using namespace std;

int main(void){
    int n_test;
    char str[128];
    cin>>n_test;
    cin.getline(str, 128);
    for(int test_case=0; test_case<n_test; test_case++){

        int len, sum=0, score=0;
        cin.getline(str, 128);
        len=strlen(str);
        for(int i=0; i<len; i++){
            if(str[i]=='O'){
                score++;
                sum+=score;
            }else{
                score=0;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}