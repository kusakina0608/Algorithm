//
// Created by Kina on 2020/08/05.
//
#include<iostream>
using namespace std;

int T, test_case, P, Q, R, S, W;

int fee_A(int amount) {
    return P * amount;
}

int fee_B(int amount) {
    return amount < R ? Q : ((amount - R)*S) + Q;
}


int main(int argc, char** argv) {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> P >> Q >> R >> S >> W;
        int a = fee_A(W);
        int b = fee_B(W);
        cout << '#' << test_case << ' ' << (a < b ? a : b) << '\n';
    }
    return 0;
}