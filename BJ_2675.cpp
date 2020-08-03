//
// Created by Kina on 2020/02/09.
//
#include <iostream>
#include <cstring>
using namespace std;

int main(void){
    int T;
    cin>>T;
    for(int test_case=0; test_case<T; test_case++){
        int n_iter;
        cin>>n_iter;
        char str[100];
        //cin.getline(str, 20);
        cin>>str;
        int len=strlen(str);
        for(int i=0; i<len; i++){
            for(int j=0; j<n_iter; j++){
                cout<<str[i];
            }
        }
        cout<<endl;
    }
    return 0;
}