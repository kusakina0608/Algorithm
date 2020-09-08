//
// Created by Kina on 20. 9. 8..
//
#include<iostream>
using namespace std;

char bufX[512];
char bufY[512];
int memo[512][512];
int len = 0;

int main(int argc, char** argv) {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> len;
        cin >> bufX;
        cin >> bufY;
        for (int i = 1; i <= len; i++) {
            for (int j = 1; j <= len; j++) {
                if (bufX[i - 1] == bufY[j - 1]) {
                    memo[i][j] = memo[i - 1][j - 1] + 1;
                }
                else {
                    memo[i][j] = memo[i - 1][j] > memo[i][j - 1] ? memo[i - 1][j] : memo[i][j - 1];
                }
            }
        }
        printf("#%d %.2lf\n", test_case, ((double)memo[len][len] / len)*100.0);
    }
    return 0;
}