//
// Created by LKina on 2020-02-25.
//
#include <iostream>
using namespace std;

int d[20];

int main(void){
    d[0] = 0;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    int T;
    cin>>T;
    for(int tc=1; tc<=T; tc++) {
        int n;
        cin >> n;
        for (int i = 4; i <= n; i++) {
            d[i] = d[i - 1] + d[i - 2] + d[i - 3];
        }
        cout << d[n] << endl;
    }
    return 0;
}