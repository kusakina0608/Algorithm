/*#include<iostream>
#include<string.h>
using namespace std;

int unit[] = { 50000, 10000, 5000, 1000, 500, 100, 50, 10 };

int test_case;
int T, i, j;
int money;


int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> money;
		cout << '#' << test_case << '\n';
		for (i = 0; i < 8; i++) {
			cout << money / unit[i] << ' ';
			money %= unit[i];
		}
		cout << '\n';
	}
	return 0;
}*/