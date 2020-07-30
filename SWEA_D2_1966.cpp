/*#include<iostream>
using namespace std;

int test_case, T, N;
int nums[64];

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubble_sort(int arr[], int n) {
	for (int i = n-1; i>0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr+j, arr+(j + 1));
			}
		}
	}
}

void selection_sort(int arr[], int n) {
	for (int i = 0; i < n-1; i++) {
		int min_idx = i;
		for (int j = i+1; j < n; j++) {
			if (arr[min_idx] > arr[j]) {
				min_idx = j;
			}
		}
		swap(arr + min_idx, arr + i);
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> nums[i];
		}
		//bubble_sort(nums, N);
		selection_sort(nums, N);
		cout << '#' << test_case << ' ';
		for (int i = 0; i < N; i++) {
			cout << nums[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}*/