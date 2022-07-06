// https://www.spoj.com/STP0522/problems/PROB01/

#include<iostream>
using namespace std;

int n;

int splitNum(int value) {
	int sum = 0;
	while (value > 0) {
		sum += value % 10;
		value /= 10;
	}
	if (sum < 10) return sum;
	else return splitNum(sum);
}

int main() {
	freopen("Input.txt", "r", stdin);
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		cout << "#" << i << " " << splitNum(n) << endl;	
	}

	return 0;
}