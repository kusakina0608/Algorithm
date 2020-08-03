//
// Created by Kina on 2020/02/09.
//
#include <iostream>
using namespace std;

int main(void){
    int n_test;
    cin>>n_test;
    for(int test_case=0; test_case<n_test; test_case++){
        int n_student, sum=0, ddokddok2=0;
        double mean;
        cin>>n_student;
        int* score=new int[n_student];
        for(int i=0; i<n_student; i++){
            cin>>score[i];
            sum+=score[i];
        }
        mean= static_cast<double>(sum)/n_student;
        for(int i=0; i<n_student; i++){
            if(static_cast<double>(score[i])>mean){
                ddokddok2++;
            }
        }
        printf("%.3lf", static_cast<double>(ddokddok2)/n_student*100);
        cout<<'%'<<endl;
    }
    return 0;
}