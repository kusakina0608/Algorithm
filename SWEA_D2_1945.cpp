//
// Created by Kina on 2020/02/12.
//
#include<iostream>
#include<cmath>
using namespace std;

bool go(int target, int a, int b, int c, int d, int e){
    int val=1;
    val*=pow(2,a);
    val*=pow(3,b);
    val*=pow(5,c);
    val*=pow(7,d);
    val*=pow(11,e);
    /*cout<<"result: "<<val<<"    ("<<a<<", "<<b<<", "<<c<<", "<<d<<", "<<e<<')'<<endl;
    cout<<endl;*/
    if(val>target)
        return false;
    if(val==target){
        cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e;
        return true;
    }
    if(go(target, a+1, b, c, d, e)){ return true; }
    else if(go(target, a, b+1, c, d, e)){ return true; }
    else if(go(target, a, b, c+1, d, e)){ return true; }
    else if(go(target, a, b, c, d+1, e)){ return true; }
    else if(go(target, a, b, c, d, e+1)){ return true; }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int target;
        cin>>target;
        cout<<'#'<<test_case<<' ';
        go(target, 0, 0, 0, 0, 0);
        cout<<endl;
    }
    return 0;
}
