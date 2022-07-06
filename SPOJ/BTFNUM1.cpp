// https://www.spoj.com/TESTSTP1/problems/BTFNUM1/

#include<iostream>
//#pragma warning(disable:4996) //_CRT_SECURE_NO_WARNINGS
using namespace std;

int n, m;
int x, y;
bool beautiNum[10];

void Clear(bool arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = false;
	}
}

int main() {
	freopen("../Input.txt", "r", stdin);
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		
		Clear(beautiNum, 10);
		
		// Lưu số đẹp
		for (int j = 0; j < n; j++) {
			int temp; cin >> temp;
			beautiNum[temp] = true;
		}

		cin >> x >> y;
		int res = 0;
		for (int j = x; j <= y; j++) {
			int cnt = 0;
			int temp = j;
			while (temp != 0) {
				if (beautiNum[temp % 10]) cnt++;
				temp /= 10;
			}
			if (cnt >= m) res++;
		}
		cout << "#" << i + 1 << " " << res << endl;
	}
}

/*
Tại một số quốc gia, có một số các chữ số được coi là chữ số đẹp hơn các chữ số khác. Ví dụ tại đất nước A, số 5 và số 7 là 2 chữ số đẹp.
Công ty Samsung muốn bán được nhiều sản phẩm nhất tại nước A, nhưng người nước A chỉ mua sản phẩm khi sản phẩm đó được đánh số trong đó có n chữ số đẹp.
Ví dụ:
Các sản phẩm được đánh số từ x đến y (x,y <100 000) ví dụ trong trường hợp này là từ 0 <= mã sản phẩm <= 1000, muốn bán được sản phẩm cần phải chứa ít nhất 2 chữ số đẹp trong đó (là 5 và 7).
Vậy nên các số như 55, 77, 57, 75, 55x, 77x, 57x, 75x ... được coi là những sản phẩm có đủ chữ số đẹp và bán được.
Yêu cầu in ra số lượng các số thỏa mãn yêu cầu trên.
Ví dụ như trên có đáp án là: 55, 77, 57, 75, 77x, 55x, 57x, 75x, 7x7, 5x5, 7x5, 5x7, x55, x57, x75, x77 => 4 + 8 * 10 + 4 * 9 = 120 số.

Input
Dòng đầu tiên là số lượng test case. Mỗi test case được viết trên 3 dòng.
Dòng thứ nhất là số lượng các chữ số đẹp (n số), số lượng chữ số đẹp yêu cầu có trong mã sản phẩm (m số).
Dòng thứ 2 gồm n số là các chữ số đẹp cần có trong mã sản phẩm (0 <= số đẹp <= 9).
Dòng thứ 3 là 2 số x và y (x <= mã sản phẩm <= y)

Output
In ra theo định dạng sau: đầu tiên là ký tự "#", tiếp theo là số thứ tự của test case, tiếp theo là khoảng trắng (dấu cách), tiếp theo là số lượng các mã sản phẩm thỏa mãn
*/