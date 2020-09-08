//
// Created by Kina on 20. 9. 8..
//
#include<iostream>
using namespace std;

int T, test_case, N, A, B, sum, min_val, max_val;

int main(int argc, char** argv) {
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> N >> A >> B;
        sum = A + B;
        min_val = N < sum ? sum-N : 0;
        max_val = A < B ? A : B;
        cout << '#' << test_case << ' ' << max_val <<' '<< min_val << '\n';
    }
    return 0;
}