// https://www.spoj.com/STP0522/problems/CANTON/

#include<iostream>
using namespace std;

int n;
int l[10000001];
int r[10000001];

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
}

void Process() {
	int d = 1;
	int temp = 1;
	while (d <= n) {
		if (d % 2 != 0) {
			for (int i = d; i >= 1; i--) {
				for (int j = 1; j <= d; j++) {
					if (i + j == d + 1) {
						//cout << i << j << endl;
						l[temp] = i;
						r[temp] = j;
						temp++;
					}
				}
			}
		}
		else {
			for (int i = d; i >= 1; i--) {
				for (int j = 1; j <= d; j++) {
					if (i + j == d + 1) {
						//cout << j << i << endl;
						l[temp] = j;
						r[temp] = i;
						temp++;
					}
				}
			}
		}
		d++;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);

	int tc; cin >> tc;
	cin.ignore(); // Xoá kí tự đầu trong bộ nhớ đệm
	for (int i = 0; i < tc; i++) {
		Input();
		clearArr(l, 10000001);
		clearArr(r, 10000001);
		Process();
		cout << "TERM " << n << " IS " << l[n] << "/" << r[n] << endl;
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