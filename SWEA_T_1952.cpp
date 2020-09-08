//
// Created by Kina on 20. 9. 8..
//
// 내년 1년 동안 각 달의 이용 계획을 수립
//  - 1일 이용권 : 1일 이용이 가능
//  - 1달 이용권 : 1달 동안 이용이 가능
//  - 3달 이용권 : 연속된 3달 동안 이용이 가능
//  - 1년 이용권 : 1년 동안 이용이 가능
// 가장 적은 비용으로 수영장을 이용할 수 있는 방법\
// * 3달 이용권은 11월, 12월, 1윌 이나 12월, 1월, 2월 동안 사용하도록 구매할 수는 없다
#include<iostream>
using namespace std;

int price[4]; // 1d, 1m, 3m, 1y
int plan[13];
int memo[4][13];

int T, test_case;

int main(int argc, char** argv) {
    cin >> T;
    register int i, j;
    for (test_case = 1; test_case <= T; ++test_case) {
        // Initialize memo
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 13; j++) {
                memo[i][j] = 0;
            }
        }
        // Get Prices
        for (i = 0; i < 4; i++) {
            cin >> price[i];
        }
        // Get Plans
        for (j = 1; j <= 12; j++) {
            cin >> plan[j];
        }
        i = 0;
        for (j = 1; j <= 12; j++) {
            memo[i][j] = memo[i][j-1] + plan[j] * price[i];
        }
        i = 1;
        for (j = 1; j <= 12; j++) {
            int tmp1 = memo[i][j - 1] + (plan[j]>0?1:0) * price[i];
            int tmp2 = memo[i][j-1] + memo[i - 1][j] - memo[i - 1][j - 1];
            memo[i][j] = tmp1 < tmp2 ? tmp1 : tmp2;
        }
        i = 2;
        memo[i][1] = memo[i - 1][1];
        memo[i][2] = memo[i - 1][2];
        for (j = 3; j <= 12; j++) {
            int tmp1 = memo[i][j - 3] + ((plan[j]>0)||(plan[j-1] > 0)||(plan[j-2] > 0)?1:0) * price[i];
            int tmp2 = memo[i][j - 1] + memo[i - 1][j] - memo[i - 1][j - 1];
            memo[i][j] = tmp1 < tmp2 ? tmp1 : tmp2;
        }
        memo[3][12] = price[3] < memo[2][12] ? price[3] : memo[2][12];
        cout << '#' << test_case << ' ' << memo[3][12] << '\n';
    }
    return 0;
}