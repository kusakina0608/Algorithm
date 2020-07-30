//
// Created by Kina on 2020/07/29.
//
#include<iostream>
using namespace std;

int test_case, T, N, val;
int sosu[] = {2, 3, 5, 7, 11};

int main(int argc, char** argv){
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case){
        cin>>N;
        cout<<'#'<<test_case;
        for(int i=0; i<5; i++) {
            val = 0;
            while (N % sosu[i] == 0) {
                val++;
                N /= sosu[i];
            }
            cout << ' ' << val;
        }
        cout<<'\n';
    }
    return 0;
}