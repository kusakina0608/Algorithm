//
// Created by Kina on 2020/05/25.
//
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    int digit, count;

    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        digit = test_case;
        count = 0;
        while(digit){
            if (((digit%10)!=0)&&((digit%10)%3==0)){
                count++;
            }
            digit = (digit-(digit%10))/10;
        }
        if(count){
            while(count--){
                printf("-");
            }
        }
        else{
            printf("%d", test_case);
        }
        printf(" ");
    }
    return 0;
}