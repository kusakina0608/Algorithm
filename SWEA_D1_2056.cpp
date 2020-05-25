//
// Created by Kina on 2020/02/15.
//
#include <iostream>
#include <string>
using namespace std;

int calendar[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(int argc, char** argv)
{
    int test_case;
    int T;
    string s;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>s;
        string year=s.substr(0, 4);
        string month=s.substr(4,2);
        string day=s.substr(6,2);
        int y=stoi(year);
        int m=stoi(month);
        int d=stoi(day);
        bool result=true;
        if(m<1 || m>12) result=false;
        if(result && (d<1 || d>calendar[m])) result=false;
        cout<<'#'<<test_case<<' ';
        if(result){
            cout<<year<<'/'<<month<<'/'<<day<<endl;
        }else{
            cout<<-1<<endl;
        }

    }
    return 0;
}