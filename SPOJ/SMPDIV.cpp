// https://www.spoj.com/STP0522/problems/SMPDIV/

#include<iostream>
using namespace std;

int n = 0, x = 0, y = 0;
int res[10000] = { 0 };
int len = 0;

int main() {
	freopen("Input.txt", "r", stdin);
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while (t--) {
		cin >> n >> x >> y;
		
		for (int i = 1; i < n; i++) {
			if (i % x == 0 && i % y != 0) res[len++] = i;
		}

		for (int i = 0; i < len; i++) {
			cout << res[i] << " ";
		}

		for (int i = 0; i < len; i++) {
			res[i] = 0;
		}

		len = 0;
		cout << endl;
	}

	return 0;
}