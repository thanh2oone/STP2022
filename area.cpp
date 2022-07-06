// Trước hết chia mỗi hình chữ nhật (HCN) thành hai đường thẳng thẳng đứng tương ứng với hai tọa độ x,
// do đó 1 HCN sẽ có một cạnh mở (bắt đầu 1 HCN mới) và 1 cạnh đóng (kết thúc một HCN).
// Sau đó ta sort danh sách 2n cạnh này theo thứ tự tăng dần trục x. Khi đó ta lần lượt
// tính diện tích trên mỗi khoảng của x, bắt đầu tại x = 0. Khi đi qua một khoảng, ta
// cộng thêm lượng [x(trước) - x(sau)] * (tổng chiều dài trên khoảng x này hiện tại có
// hình chữ nhật) vào ans. Khi x(trước) = x(sau) thì nó chỉ có nhiệm vụ cập nhật lại 
// chiều dài trên khoảng x này. Do đó, khi sort ta ưu tiên cạnh đóng trước, kết thúc
// những HCN để tránh cộng dư diện tích.
// Bây giờ, vấn đề đặt ra là làm sao tính được tổng chiều dài trên 1 khoảng x như vậy ? 
// Ta nhận thấy rằng mỗi lần qua 1 khoảng thì ta có hai thao tác trên trục y, thứ nhất 
// là lấy tổng chiều dài, thứ hai là cập nhật thêm hoặc xóa trên một đoạn, cùng với 0 <= y <= 30000 
// khiến ta liên tưởng đến Segment Tree.
// Mỗi nút Segment Tree lúc này lưu hai biến cnt và len lần lượt có ý nghĩa là số lượng HCN
// phủ cả đoạn này hiện tại và tổng chiều dài bị các HCN chiếm giữ hiện tại (nếu cnt > 0 thì
// tất nhiên là cả chiều dài đoạn này, còn không thì là tổng chiều dài từng phần của các HCN khác).
// Và ở đây do là trục tọa độ, để dễ dàng hơn ta chuyển thành đoạn trên trục, như (0->1) = 1; (1->2) = 2;
// … do đó với một HCN có hai thông số y1, y2 (y1 <= y2) thì nó sẽ bắt đầu từ đoạn y1 đến đoạn y2-1,
// trong trường hợp y1 == y2 thì ta không làm gì hết.
// Lúc này, với thao tác lấy tổng chiều dài trên cả trục y thì ta chỉ cần gọi t[1].len.
// Còn với thao tác update trên một đoạn, ta cộng số lượng HCN vào nút (1, với mở hoặc -1, nếu như là đóng).
// Với một nút có đoạn nằm trong đoạn update, thì nếu như đoạn này là mở thì toàn bộ đoạn này 
// được phủ nên t[k].len = r-l+1, trong trường hợp ngược lại, nếu đoạn này không còn HCN phủ
// cả đoạn nữa (ứng với trường hợp là cạnh đóng) thì ta truy xuất đến hai nút con để lấy tổng 
// chiều dài các HCN khác (lưu ý là nếu truy xuất đến nút lá, l == r, thì t[k].len = 0 do không còn HCN nào nữa).

// Việc combine hai nút chỉ là kiểm tra xem còn HCN hay không, nếu không thì lấy hai nút lá.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

struct data {
	int x, l, r, type;
};

struct seg {
	int cnt, len;
};

const int N = 30010;
int n, m, k;
ll ans;
data a[N];
seg t[4*N];

bool cmp(data u, data v) {
	return (u.x < v.x || (u.x == v.x && u.type < v.type));
}

void upd(int k, int l, int r, int L, int R, int type) {
	if (L > R || r < L || R < l) return ;
	if (L <= l && r <= R) {
		t[k].cnt += type;
		if (type == 1) t[k].len = r-l+1;
		else if (t[k].cnt == 0)
			if (l < r)
				t[k].len = t[k<<1].len + t[(k<<1)+1].len;
			else
				t[k].len = 0;
		return ;
	}
	int mid = (l+r)>>1;
	upd(k<<1, l, mid, L, R, type);
	upd((k<<1)+1, mid+1, r, L, R, type);
	if (t[k].cnt == 0 && l < r)
		t[k].len = t[k<<1].len + t[(k<<1)+1].len;
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1,&y1,&x2,&y2);
		a[++m] = {x1, y1+1, y2, 1};
		a[++m] = {x2, y1+1, y2, -1};
		k = max(k, y2);
	}

	sort(a+1,a+m+1,cmp);

	FOR(i,1,m) {
		ans += (ll)t[1].len * (ll)(a[i].x - a[i-1].x);
		upd(1, 1, k, a[i].l, a[i].r, a[i].type);
	}

	printf("%lld\n", ans);

	return 0;
}