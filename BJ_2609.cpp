//
// Created by Kina on 2020/05/25.
//
#include <iostream>

using namespace std;

int GCDEuclideanLoop(int a, int b){
    while(b != 0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int a, b, g, l;
    cin >> a >> b;
    g = GCDEuclideanLoop(a, b);
    l = (a*b)/g;
    cout << g << endl;
    cout << l;

    return 0;
}