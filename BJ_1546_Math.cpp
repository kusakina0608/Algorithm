//
// Created by Kina on 2020/02/08.
//
#include <iostream>
using namespace std;

double findMax(double* arr, int len){
    double max=0.0;
    for(int i=0; i<len; i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}

void reGrading(double* arr, int len, int max){
    for(int i=0; i<len; i++){
        arr[i] = ((arr[i])/max) * 100;
    }
}

double calcMean(double* arr, int len){
    double sum=0.0;
    for(int i=0; i<len; i++){
        sum+=arr[i];
    }
    return static_cast<double>(sum)/len;
}

int main(void){
    int n=0, val=0;
    cin>>n;
    double* arr=new double[n];
    for(int i=0; i<n; i++){
        cin>>val;
        arr[i]=val;
    }
    int max= findMax(arr, n);
    reGrading(arr, n, max);
    printf("%.2lf", calcMean(arr, n));
    delete[] arr;
    return 0;
}