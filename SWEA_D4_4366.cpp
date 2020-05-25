//
// Created by Kina on 2020/05/25.
//
#include<iostream>
#include<string>

using namespace std;

int pow(int a, int b){
    int res = 1;
    for(int i=0; i<b; i++){
        res*=a;
    }
    return res;
}

int twoToInteger(string s, int size){
    int res=0;
    int exp=0;
    for(int i=size-1; i>=0; i--){
        res += (s[i]-'0')*pow(2, exp++);
    }
    return res;
}

int threeToInteger(string s, int size){
    int res=0;
    int exp=0;
    for(int i=size-1; i>=0; i--){
        res += (s[i]-'0')*pow(3, exp++);
    }
    return res;
}

int twoIndex(string s, int index){
    char c = s[index];
    if(c=='0'){
        s[index] = '1';
    }else{
        s[index] = '0';
    }
    return twoToInteger(s, s.size());
}



int find(int* arr, int size, string s, int index){
    char c = s[index];
    int tmp1, tmp2;
    if(c=='0'){
        s[index] = '1';
        tmp1 = threeToInteger(s, s.size());
        s[index] = '2';
        tmp2 = threeToInteger(s, s.size());
    }else{
        if(c=='1'){
            s[index] = '0';
            tmp1 = threeToInteger(s, s.size());
            s[index] = '2';
            tmp2 = threeToInteger(s, s.size());
        }
        else{
            s[index] = '0';
            tmp1 = threeToInteger(s, s.size());
            s[index] = '1';
            tmp2 = threeToInteger(s, s.size());
        }
    }
    for(int i=0; i<size; i++){
        if(arr[i] == tmp1) return tmp1;
        if(arr[i] == tmp2) return tmp2;
    }
    return -1;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        string two, three;
        cin>>two>>three;
        int size2, size3;
        size2 = two.size();
        int* res = new int[size2];
        for(int i=size2-1; i>=0; i--){
            res[i] = twoIndex(two, i);
        }
        size3 = three.size();
        int res2 = 0;
        for(int i=size3-1; i>=0; i--){
            res2 = find(res, size2, three, i);
            if(res2 != -1) break;
        }
        cout<<'#'<<test_case<<' '<<res2<<'\n';
    }
    return 0;
}