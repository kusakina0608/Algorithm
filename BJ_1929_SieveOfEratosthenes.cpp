//
// Created by Kina on 2020/05/04.
//
#include <iostream>

using namespace std;

int main(void){
    int i, j, n, m, pn = 0;
    int* prime = NULL;
    bool* check = NULL;

    cin >> m >> n;

    prime = new int[n];
    check = new bool[n+1];

    for (i = 2; i <= n; i++){
        if (check[i] == false){
            if(i>=m){
                prime[pn++] = i;
            }
            for(j = i*2; j <= n; j += i){
                check[j] = true;
            }
        }
    }

    for(i = 0; i < pn; i++){
        printf("%d\n",prime[i]);
    }

    delete[] prime;
    delete[] check;

    return 0;
}