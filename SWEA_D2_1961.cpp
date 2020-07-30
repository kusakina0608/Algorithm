#include<iostream>
using namespace std;

int test_case, T, N;
int arr[7][7];
int tmp_arr[3][7][7];

void rotate90(int a[7][7], int b[7][7], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[j][n-1-i] = a[i][j];
		}
	}
}

int main(int argc, char** argv)
{
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		rotate90(arr, tmp_arr[0], N);
		rotate90(tmp_arr[0], tmp_arr[1], N);
		rotate90(tmp_arr[1], tmp_arr[2], N);
		cout << '#' << test_case<<'\n';
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < N; k++) {
					cout << tmp_arr[j][i][k];
				}
				cout << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}