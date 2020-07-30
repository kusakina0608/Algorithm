//
// Created by Kina on 2020/07/29.
//
#include<iostream>
using namespace std;

int test_case, T, N, total, cur_spd, speed, command;

int main(int argc, char** argv)
{
    cin>>T;
    // 0: 유지, 1: 가속, 2: 감속
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>N;
        total = 0;
        cur_spd = 0;
        for(int i=0; i<N; i++){
            cin>>command;
            if(command){
                cin>>speed;
                if(command==1){
                    cur_spd += speed;
                }else{
                    cur_spd -= speed;
                    if(cur_spd<0)
                        cur_spd=0;
                }
            }
            total += cur_spd;
        }
        cout<<'#'<<test_case<<' '<<total<<'\n';
    }
    return 0;
}