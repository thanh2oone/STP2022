// https://www.spoj.com/STP0522/problems/MSUBSTR/
// https://thuattoan.phamvanlam.com/spoj-com-thuat-toan-bai-msubstr-mirror-strings/

#include<iostream>
#include<algorithm>
using namespace std;

char s[3001];

void Input() {
	cin >> s;
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

int maxArr(int arr[], int size) {
	int max = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] > max) max = arr[i];
	}
	return max;
}

// TLE
void Solve() {
	char subString[10000];
	int lenSub = 0;
	int lenSubString[10000];
	int lenSubStr = 0;

	int len = lengthString(s);
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			int temp = 0;
			for (int k = i; k < j; k++) {
				if (s[k] == s[j - k - 1]) temp++;
			}
			if (temp == lengthString(subString)) lenSubString[lenSubStr++] = temp;
			temp = 0;
			clearStr(subString, lenSub);
			lenSub = 0;
		}
	}

	int countLen[10000];
	sort(lenSubString, lenSubString + lenSubStr);
	for (int i = 0; i < lenSubStr; i++) {
		countLen[lenSubString[i]]++;
	}

	int res = 0;
	int maxLen = maxArr(lenSubString, lenSubStr);
	for (int i = 0; i < lenSubStr; i++) {
		if (countLen[lenSubString[i]] == maxLen) res++;
	}
	cout << res << endl;
}

/*
AC
int countMax;

void Solve() {
	int len = lengthString(s);
	int maxLength = lengthString(s);

	while (1) {
		countMax = 0;
		bool stop = false;
		for (int i = 0; i < len; i++) {
			if (i + maxLength > len) break;
			if (maxLength == 1 || maxLength == 2 && s[i] == s[i + 1]) {
				countMax++;
				stop = true;
			}
			else {
				bool check = true;
				for (int j = 0; j <= (maxLength - 1) / 2; j++) {
					if (s[j + i] != s[maxLength - j - 1 + i]) { // Bớt đc 1 vòng lặp
						check = false;
						break;
					}
				}
				if (check == true) {
					countMax++;
					stop = true;
				}
			}
		}
		if (stop == true || maxLength == 1) break;
		maxLength--;
	}
	cout << maxLength << " " << countMax << endl;
}
*/

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);

	int tc; cin >> tc;
	cin.ignore(); // Xoá kí tự đầu trong bộ nhớ đệm
	for (int i = 0; i < tc; i++) {
		Input();
		Solve();
	}
	return 0;
}