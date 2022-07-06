// https://www.spoj.com/STP0522/problems/PAIRS1/

#include<iostream>
using namespace std;

int n, k;
int a[100000];

void swp(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void sortArr() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swp(a[j], a[j + 1]);
			}
		}
	}
}

int binarySearch(int arr[], int l, int r, int value) {
	if (r >= l) {
		int mid = (l + r) / 2; // Position

		if (arr[mid] == value) return mid;
		if (arr[mid] < value) {
			return binarySearch(arr, mid + 1, r, value);
		}
		if (arr[mid] > value) {
			return binarySearch(arr, l, mid - 1, value);
		}
	}
	else return -1;
}

int main() {
	freopen("Input.txt", "r", stdin);
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		sortArr();

		int cnt = 0;
		
		for (int i = 0; i < n; i++) {
			if (binarySearch(a, 0, n, a[i] + k) != -1) cnt++;
		}
		cout << cnt << endl;
	}

	return 0;
}