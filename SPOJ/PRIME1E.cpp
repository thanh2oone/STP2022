// https://www.spoj.com/STP0522/problems/PRIME1E/

#include<iostream>
using namespace std;

int m = 0, n = 0;
int res[10000];
int len = 0;

int main() {
	freopen("Input.txt", "r", stdin);
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while (t--) {
		cin >> m >> n;
		
		for (int i = m; i <= n; i++) {
			bool check = true;
			if (i < 2) check = false;
			for (int j = 2; j*j <= i; j++) {
				if (i % j == 0) check = false;
			}
			if (check == true) res[len++] = i;
		}

		for (int i = 0; i < len; i++) {
			cout << res[i] << endl;
		}
		cout << endl;

		for (int i = 0; i < len; i++) {
			res[i] = 0;
		}

		len = 0;
	}

	return 0;
}