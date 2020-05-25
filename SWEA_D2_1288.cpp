//
// Created by Kina on 2020/02/03.
//
#include<iostream>
using namespace std;

int main(int argc, char** argv){
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case){
        bool flag[10] = {true, true, true, true, true, true, true, true, true, true};
        int n;
        cin>>n;
        int i=1;
        int val=n, index;
        while(flag[0] || flag[1] || flag[2] || flag[3] || flag[4] || flag[5] || flag[6] || flag[7] || flag[8] || flag[9]){
            val = index = i*n;
            while(index >=10){
                flag[index%10]= false;
                index/=10;
            }
            flag[index]=false;
            i++;
        }
        cout<<'#'<<test_case<<' '<<val<<endl;
    }
    return 0;
}