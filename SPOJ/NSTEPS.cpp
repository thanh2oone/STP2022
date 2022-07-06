// https://www.spoj.com/STP0522/problems/NSTEPS/

#include<iostream>
using namespace std;

int x, y;

int solve() {
	if (x == y) { // Top Way
		if (x % 2 == 0 && y % 2 == 0) return x + y;
		if (x % 2 != 0 && y % 2 != 0) return x + y - 1;
		else return -1;
	}
	else if (x != y) { // Bottom Way
		if (x % 2 == 0 && y % 2 == 0 && x - y == 2) return x + y;
		if (x % 2 != 0 && y % 2 != 0 && x - y == 2) return x + y - 1;
		else return -1;
	}
	else return -1;
}

int main() {
	freopen("Input.txt", "r", stdin);
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while (t--) {
		cin >> x >> y;

		int res = solve();
		if (res == -1) cout << "No Number" << endl;
		else cout << res << endl;
	}

	return 0;
}