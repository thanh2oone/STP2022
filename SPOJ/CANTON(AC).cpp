// https://www.spoj.com/STP0522/problems/CANTON/
// https://thuattoan.phamvanlam.com/spoj-com-thuat-toan-bai-canton-count-on-cantor/
// https://github.com/arvind-kalyan/SPOJ-Solutions/blob/master/Solutions/CANTON-9990816.cpp

#include<iostream>
using namespace std;

int n;

void Input() {
	cin >> n;
}

int lengthString(char str[]) {
	int len = 0;
	while (str[len] != '\0') len++;
	return len;
}

void clearArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}

void clearStr(char str[], int length) {
	for (int i = 0; i < length; i++) {
		str[i] = '\0';
	}
	//cout << "TERM " << n << " IS " << l[n] << "/" << r[n] << endl;
}

void Process() {
	int sum = 0;
	int indexRow = 1;

	for (int i = 1;; i++) {
		sum += i;
		if (sum >= n) {
			indexRow = i;
			break;
		}
	}
	int temp = n - (sum - indexRow);
	int total = indexRow + 1;

	if (indexRow % 2 == 0) cout << "TERM " << n << " IS " << temp << "/" << total - temp << endl;
	else cout << "TERM " << n << " IS " << total - temp << "/" << temp << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);

	int tc; cin >> tc;
	cin.ignore(); // Xoá kí tự đầu trong bộ nhớ đệm
	for (int i = 0; i < tc; i++) {
		Input();;
		Process();
	}
	return 0;
}

/*
1/1 1/2 1/3 1/4 1/5 ...
2/1 2/2 2/3 2/4
3/1 3/2 3/3
4/1 4/2
5/1

In the above diagram, the first term is 1/1, the second term is 1/2,
the third term is 2/1, the fourth term is 3/1, the fifth term is 2/2,...
Show the 'n' term
*/