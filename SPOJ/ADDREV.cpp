// https://www.spoj.com/STP0522/problems/ADDREV/

#include<iostream>
using namespace std;

int a = 0, b = 0;

int reverseNumber(int num) {
	int rev = 0;
	while (num != 0) {
		rev = (rev * 10) + (num % 10);
		num /= 10;
	}
	return rev;
}

int main() {
	freopen("Input.txt", "r", stdin);
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while (t--) {
		cin >> a >> b;

		int rev_sum = reverseNumber(a) + reverseNumber(b);
		cout << reverseNumber(rev_sum) << endl;
	}
	
	return 0;
}