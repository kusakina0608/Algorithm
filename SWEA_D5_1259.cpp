//
// Created by Kina on 20. 9. 8..
//
#include<iostream>
using namespace std;

int v1, v2;
int h1[50];
int h2[50];

int T, test_case, n;

int main(int argc, char** argv) {
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> v1 >> v2;
            h1[v1] = v2;
            h2[v2] = v1;
        }
        while (h2[v1] != 0) {
            v1 = h2[v1];
        }
        cout << '#' << test_case;
        while (h1[v1] != 0) {
            cout << ' ' << v1<<' '<<h1[v1];
            v1 = h1[v1];
        }
        cout<< '\n';
        for (int i = 0; i < 50; i++) {
            h1[i] = 0;
            h2[i] = 0;
        }
    }
    return 0;
}