//
// Created by Kina on 2020/05/25.
//
#include<iostream>

using namespace std;

typedef struct{
    int _mid;
    int _final;
    int _assign;
    float score;
} student;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    int n; // number of student
    int k; // target student
    int count;
    float percentile;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n >> k;
        student stu[100];

        for(int i=0; i<n; i++){
            cin >> stu[i]._mid >> stu[i]._final >> stu[i]._assign;
            stu[i].score = (stu[i]._mid)*0.35 + (stu[i]._final)*0.45 + (stu[i]._assign)*0.2;
        }
        count=0;

        for(int i=0; i<n; i++){
            if(stu[i].score <= stu[k-1].score){
                count++;
            }
        }

        percentile = (count)*(1/(float)(n+1)); // calc percentile

        cout<<"#"<<test_case<<' ';
        if( percentile > 0.7 ){
            if( percentile > 0.9 ){
                cout << "A+";
            } else if(percentile > 0.8){
                cout << "A0";
            } else{
                cout << "A-";
            }
        }
        else if(percentile > 0.4){
            if( percentile > 0.6 ){
                cout << "B+";
            } else if(percentile > 0.5){
                cout << "B0";
            } else{
                cout << "B-";
            }
        }
        else if(percentile > 0.1){
            if( percentile > 0.3 ){
                cout << "C+";
            } else if(percentile > 0.2){
                cout << "C0";
            } else{
                cout << "C-";
            }
        }
        else{
            cout << "D0";
        }
        cout<<endl;
    }
    return 0;
}