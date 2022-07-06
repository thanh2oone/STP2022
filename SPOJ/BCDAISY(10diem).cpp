// https://www.spoj.com/PTIT/problems/BCDAISY/
// Using DFS

#include<iostream>
using namespace std;

int n, m;
int a[250][250] = { 0 };
int markStupidCow[250] = { 0 }; // Đánh dấu bò hư, ban đầu chưa có bò hư

void Input() {
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int cow1, cow2;
		cin >> cow1 >> cow2;
		
		// Giả sử tất cả bò đều được nối với nhau
		a[cow1][cow2] = 1;
		a[cow2][cow1] = 1;
	}

}

void DFS(int value) {
	for (int i = 1; i <= n; i++) {
		// a[value][i] == 1: Tìm xem bò value nối i có trong mảng a trên kia ko, có tức là có nối với nhau
		if (a[value][i] == 1 && markStupidCow[i] == 0) { // Nếu bò được nối và không có bò hư
			DFS(i); // Đệ quy xét bò tiếp theo
		}
		else markStupidCow[value] = 1; // Còn không thì đánh dấu là bò hư
	}
}

void Result() {
	bool check = true;
	for (int i = 1; i <= n; i++) {
		if (markStupidCow[i] == 0) {
			cout << i << endl;
			check = false;
		}
	}
	if (check == true) cout << 0 << endl;
}

int main() {
	freopen("Input.txt", "r", stdin);
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	DFS(1);
	Result();

	return 0;
}