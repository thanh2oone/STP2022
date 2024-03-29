// https://www.spoj.com/PTIT/problems/BCLUCKY/
#include<iostream>
using namespace std;

long long a[1000000];
long long cnt[1000000];
long long n, x;

void Clear(long long arr[]) {
	for (long long i = 0; i < n; i++) {
		arr[i] = 0;
	}
}

void BBSort(long long arr[]) {
	for (long long i = 0; i < n; i++) {
		for (long long j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				long long temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

long long MaxArr(long long arr[]) {
	long long max = arr[0];
	for (long long i = 0; i < n; i++) {
		if (arr[i] > max) max = arr[i];
	}
	return max;
}

long long MinArr(long long arr[]) {
	long long min = arr[0];
	for (long long i = 0; i < n; i++) {
		if (arr[i] < min) min = arr[i];
	}
	return min;
}

long long Profit() {
	Clear(cnt);
	if (n == 1) return 0;
	if (n == 2) {
		return a[0] > a[1] ? a[0] : a[1];
	}
	else {
		BBSort(a);
		for (long long i = 0; i < n; i++) {
			cnt[a[i]]++;
		}
		long long temp[1000000];
		Clear(temp);
		for (long long i = 0; i < n; i++) {
			temp[i] = cnt[a[i]];
		}

		long long profit = 0;
		if (MaxArr(a) && MinArr(temp)) {
			profit = n * x - MaxArr(a) * MinArr(temp);
		}
		return profit;
	}
}

int main() {
	//freopen("../Input.txt", "r", stdin);
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> x;
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	Clear(cnt);
	cout << Profit() << endl;
	Clear(a);
}