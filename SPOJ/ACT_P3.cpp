// https://www.spoj.com/problems/ACT_P3/

#include<iostream>
//#pragma warning(disable:4996) //_CRT_SECURE_NO_WARNINGS
using namespace std;

int n;
int XtoY[20][2];
int index[25];

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	for (int tc = 1; tc <= t ; tc++) {
		cin >> n;

		for (int i = 0; i < 25; i++) {
			cin >> index[i];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				cin >> XtoY[i][j];
			}
		}

		for (int i = 1; i <= n; i++) {
			// Gán giá trị phần tử cần di chuyển vào 1 biến vì sau này sẽ mất
			int temp = index[XtoY[i - 1][0] - 1];

			// Nếu vị trí hiện tại nhỏ hơn vị trí cần đến (Đi tiến)
			if (XtoY[i - 1][0] - 1 < XtoY[i - 1][1] - 1) {
				for (int j = XtoY[i - 1][0]; j <= XtoY[i - 1][1] - 1; j++) {
				// Khoảng từ vị trí hiện tại đến vị trí cần đến dồn sang trái
					index[j - 1] = index[j];
				}
			}
			// Đi lùi
			else {
				for (int j = XtoY[i - 1][0] - 1; j >= XtoY[i - 1][1] - 1; j--) {
				// Khoảng từ vị trí hiện tại đến vị trí cần đến dồn sang phải
					index[j] = index[j - 1];
				}
			}
			// Gán vị trí cần đến là temp
			index[XtoY[i - 1][1] - 1] = temp;
		}

		cout << "Case #" << tc << ":" << "\n";
		for (int i = 1; i <= 25; i++) {
			cout << index[i - 1] << " ";
			if (i % 5 == 0) cout << endl;
		}
	}

	return 0;
}