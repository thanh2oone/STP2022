//https://www.spoj.com/PTIT/problems/BCACM11B/

#include <iostream>
using namespace std;

int a[100][100];
int n, x, y;

int print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

void solve() {
    int value = 1, d = 0; // value: giá trị từng ô của ma trận xoắn ốc gán vào mảng 2 chiều
                            // d: số vòng
    // Note: Đi theo hàng, < cột, đi theo cột, < hàng
    int row = n - 1, col = n - 1;
    while (value <= n * n) {
        for (int i = d; i <= col; i++) { // Hàng trên
            a[d][i] = value++; // 00 01 02 03 ...
        }
        for (int i = d + 1; i <= row; i++) { // Cột phải
            a[i][col] = value++; // 13
                                 // 23
                                 // 33
        }
        // value <= n * n: Chưa phải là vòng cuối (vòng trong cùng)
        for (int i = col - 1; i >= d && value <= n * n; i--) { // Hàng dưới
            a[row][i] = value++; // 32 31 30
        }
        // i > d: i = d đã điền vào trong khi điền hàng trên
        for (int i = row - 1; i > d && value <= n * n; i--) { // Cột trái
            a[i][d] = value++; // 10
                               // 20
                               // 30
        }
        row--;
        col--;
        d++;
    }
}

int main() {
    freopen("Input.txt", "r", stdin);
    int t; cin >> t;
    ios_base::sync_with_stdio;
    cin.tie(NULL);
    cout.tie(NULL);
    while (t--) {
        cin >> n >> x >> y;
        solve();
        //print();
        cout << a[x - 1][y - 1] << "\n";
    }
    return 0;
}