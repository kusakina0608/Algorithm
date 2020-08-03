//
// Created by Kina on 2020/08/02.
//
#include <iostream>
using namespace std;

int N, pivot, L, R, p;
int xpos[100000];
int ypos[100000];

void k_swap(int n1, int n2){
    int tmp1 = *(xpos+n1);
    int tmp2 = *(ypos+n1);
    *(xpos+n1) = *(xpos+n2);
    *(ypos+n1) = *(ypos+n2);
    *(xpos+n2) = tmp1;
    *(ypos+n2) = tmp2;
}

int partition(int begin, int end){
    L = begin;
    R = end;
    pivot = (begin+end)/2;
    while(L<R){
        while((xpos[L]<xpos[pivot] || (xpos[L]==xpos[pivot] && ypos[L]<ypos[pivot])) && L<R) L++;
        while((xpos[R]>xpos[pivot] || (xpos[R]==xpos[pivot] && ypos[R]>=ypos[pivot])) && L<R) R--;
        if(L<R) k_swap(L++, R--);
    }
    k_swap(R, pivot);
    return R;
}

void quick_sort(int begin, int end){
    if(begin<end){
        int p = partition(begin, end);
        quick_sort(begin, p-1);
        quick_sort(p+1, end);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>xpos[i]>>ypos[i];
    }
    quick_sort(0, N-1);
    for(int i=0; i<N; i++){
        cout<<xpos[i]<<' '<<ypos[i]<<'\n';
    }
    return 0;
}