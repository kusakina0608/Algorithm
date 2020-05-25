//
// Created by Kina on 2020/05/25.
//
#include <iostream>

using namespace std;

bool prime(int n){
    if (n < 2){
        return false;
    }
    for (int i = 2; i*i<=n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int main(void){
    int n, count, np = 0;

    cin >> count;
    while(count--){
        cin >> n;
        if(prime(n)){
            np++;
        }
    }
    cout << np;

    return 0;
}