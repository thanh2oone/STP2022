// https://www.spoj.com/PTIT/problems/EXCEL/

#include<iostream>
//#pragma warning(disable:4996) //_CRT_SECURE_NO_WARNINGS
using namespace std;

char s[100000];
int row = 0, col = 0;
char res_col[100000];

// Tính độ dài chuỗi
int lengthOfString(char str[]) {
	int len = 0;
	while (str[len] != '\0') len++;
	return len;
}

// Convert char sang int
int charToInt(char c) {
	return c - '0'; // 48
}

// Convert int sang char
char intToChar(int n) {
	return (char)n + '0'; // 48
}

// Đảo ngược chuỗi
void reverseString(char str[], int str_len) {
	for (int i = 0; i < str_len / 2; i++) {
		char temp = str[i];
		str[i] = str[str_len - i - 1];
		str[str_len - i - 1] = temp;
	}
}

int main() {
	freopen("../Input.txt", "r", stdin);
	while (1) {
		ios_base::sync_with_stdio;
		cin.getline(s, 100000);

		// Độ dài chuỗi ban đầu
		int s_len = lengthOfString(s);
		col = 0, row = 0;

		// Tách lấy chuỗi là vị trí hàng
		int i = 1;
		while (s[i] != 'C') {
			row = row * 10 + charToInt(s[i]);
			i++;
		}
		i++;
		// Tách lấy chuỗi là vị trí cột
		while (i < s_len) {
			col = col * 10 + charToInt(s[i]);
			i++;
		}

		if (col == 0 && row == 0) break;

		int j = 0;
		while (col != 0) {
			int temp = (col - 1) % 26;
			res_col[j] = temp + 'A';
			col = (col - 1) / 26;
			j++;
		}

		res_col[j] = '\0'; // Đánh dấu kết thúc chuỗi
		
		int res_col_len = lengthOfString(res_col);
		/*for (int j = res_col_len - 1;  j >= 0; j--) {
			cout << res_col[j];
		}
		cout << row << endl;*/
		reverseString(res_col, res_col_len);
		cout << res_col << row << endl;
	}
	return 0;
}