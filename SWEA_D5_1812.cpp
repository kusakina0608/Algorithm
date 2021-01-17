//
// Created by Kina on 2020/12/02.
//
#include<iostream>

using namespace std;
int T, N, M, test_case;
int arr[500], top;

void init_globals(){
    top = -1;
}

void sort_arr(){
    for(int i=top; i>0; i--){
        for(int j=0; j<i; j++){
            if(arr[j] >= arr[j+1]){
                arr[j] = arr[j] ^ arr[j+1];
                arr[j+1] = arr[j] ^ arr[j+1];
                arr[j] = arr[j] ^ arr[j+1];
            }
        }
    }
}

int main(int argc, char** argv) {
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        init_globals();
        cin>>N>>M;
        for(int n=0; n<N; n++){
            int val;
            cin>>val;
            arr[++top] = 1<<val;
        }
        sort_arr();
        int cnt = 1;
        int cur = M;
        for(int i=top; i>=0; i--){
            if(cur<arr[i]){
                cnt++;
                cur = M;
            }
            cur -= arr[i];
        }
        cout<<'#'<<test_case<<' '<<cnt<<endl;
    }
    return 0;
}