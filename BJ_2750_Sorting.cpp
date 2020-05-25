//
// Created by Kina on 2020/02/18.
//
#include <iostream>
using namespace std;
void BubbleSort(int* arr, int size);
void swap(int& a, int& b);

int main(void){
    int n;
    scanf("%d", &n);
    int* arr=new int[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    BubbleSort(arr, n);
    for(int i=0; i<n; i++){
        printf("%d\n", arr[i]);
    }
    delete[] arr;
    return 0;
}

void BubbleSort(int* arr, int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void swap(int& a, int& b){
    a=a^b;
    b=a^b;
    a=a^b;
}