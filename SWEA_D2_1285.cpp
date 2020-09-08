// TODO()
// Created by Kina on 2020/08/05.
//
#include<iostream>
#define ABS(X) (((X)<0)?(-X):(X))
using namespace std;

int T, test_case, N, min_dist, cnt, val;

int main(int argc, char** argv) {
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        min_dist = 999999;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> val;
            val = ABS(val);
            if (val < min_dist) {
                min_dist = val;
                cnt = 1;
            }
            else if (val == min_dist) {
                cnt++;
            }
        }
        cout << '#' << test_case << ' ' << min_dist << ' ' << cnt << '\n';
    }
    return 0;
}