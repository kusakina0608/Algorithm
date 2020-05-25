//
// Created by Kina on 2020/05/25.
//
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int sum = 0, val = 0;

        for(int i=0; i<10; i++){
            scanf("%d", &val);
            if(val%2==1)
                sum += val;
        }
        printf("#%d %d\n", test_case, sum);
    }
    return 0;
}