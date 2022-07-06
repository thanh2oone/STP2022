// https://www.spoj.com/problems/TOANDFRO/

#include<iostream>
//#pragma warning(disable:4996) //_CRT_SECURE_NO_WARNINGS
using namespace std;

const int range = 10009;
char s[range];
char msg[range][range];

int length(char str[]) {
	int len = 0;
	while (str[len] != '\0') len++;
	return len;
}

int main() {
	freopen("../Input.txt", "r", stdin);
	
	while (true) {
		ios_base::sync_with_stdio;
		cin.tie(NULL);
		cout.tie(NULL);

		int n; cin >> n;
		if (n == 0) break;
		cin.ignore();
		
		cin.getline(s, range);
		int len = length(s);
		
		int temp = 0;
		while (s[temp] != '\0') {
			for (int i = 0; i < len / n; i++) {
				if (i % 2 == 0) {
					for (int j = 0; j < n; j++) {
						msg[i][j] = s[temp];
						temp++;
					}
				}
				else {
					for (int j = n - 1; j >= 0; j--) {
						msg[i][j] = s[temp];
						temp++;
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < len / n; j++) {
				cout << msg[j][i];
			}
		}
		cout << endl;
	}
}