//
// Created by Kina on 2020/05/04.
//

#include <iostream>

using namespace std;
int GCD(int a, int b){
    while(b != 0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main(void){
    int count, a, b, g, l;

    cin >> count;

    while(count>0){
        cin >> a >> b;
        //find GCD
        g = GCD(a,b);
        l = (a*b)/g;
        cout << l << endl;
        count--;
    }
    return 0;
}