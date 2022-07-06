// https://www.spoj.com/STP0522/problems/MTARECTANGLE/

#include<iostream>
using namespace std;

int n, a[100000];
int cnt[100000];
int temp[100000];

void Input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

int max1(int sizeT) {
	int max = temp[0];
	for (int i = 0; i < sizeT; i++) {
		if (temp[i] > max) max = temp[i];
	}
	return max;
}

int max2(int sizeT) {
	int max = temp[0];
	for (int i = 0; i < sizeT; i++) {
		if (temp[i] > max && temp[i] != max1(sizeT)) max = temp[i];
	}
	return max;
}

void ClearArr(int arr[]) {
	for (int i = 0; i < 100000; i++) {
		arr[i] = 0;
	}
}

void Process() {
	for (int i = 0; i < n; i++) {
		cnt[a[i]]++;
	}

	int sizeT = 0;
	for (int i = 0; i < n; i++) {
		if (cnt[a[i]] >= 2) {
			temp[sizeT++] = a[i];
		}
	}

	if (sizeT >= 4) {
		// Nếu phần tử lớn nhất max1 có số lần xuất hiện >= 4 thì chắc chắn tích max1 * max1 > max1 * max2
		if (cnt[max1(sizeT)] >= 4) cout << max1(sizeT) * max1(sizeT) << endl;
		else cout << max1(sizeT) * max2(sizeT) << endl;
	}
	else cout << -1 << endl;
}

int main() {
	freopen("Input.txt", "r", stdin);
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);

	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		Input();
		ClearArr(cnt);
		ClearArr(temp);
		Process();
	}
	return 0;
}