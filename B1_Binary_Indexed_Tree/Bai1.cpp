#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005                
#define int long long              

int a[MAXN], bit[MAXN];           // Mảng a lưu giá trị ban đầu, mảng bit là cây Binary Indexed Tree (Fenwick Tree)

// Hàm cập nhật BIT: tăng giá trị tại chỉ số idx lên val
void update(int idx, int val) {
    while (idx < MAXN) {
        bit[idx] += val;          // Cập nhật nút hiện tại
        idx += (idx & -idx);      // Di chuyển lên các nút cha trong BIT
    }
}

// Hàm tính tổng từ 1 đến idx
int getSum(int idx) {
    int ans = 0;
    while (idx > 0) {
        ans += bit[idx];          // Cộng dồn giá trị tại chỉ số hiện tại
        idx -= (idx & -idx);      // Di chuyển lên các nút cha bên trái trong BIT
    }
    return ans;                   // Trả về tổng đoạn [1..idx]
}

main() {
    ios_base::sync_with_stdio(false); // Tăng tốc độ nhập xuất
    cin.tie(nullptr);                

    int n;
    cin >> n;                        // Nhập số lượng phần tử

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];                 // Nhập giá trị cho mảng a
        update(i, a[i]);            // Cập nhật giá trị vào BIT
    }

    int q;
    cin >> q;                        // Nhập số truy vấn
    while (q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            // Cập nhật: tăng giá trị tại vị trí u lên val
            int u, val;
            cin >> u >> val;
            update(u, val);
        } else if (cmd == 2) {
            // Truy vấn tổng đoạn [u..v]
            int u, v;
            cin >> u >> v;
            cout << getSum(v) - getSum(u - 1) << '\n'; // Tổng đoạn [u..v] = getSum(v) - getSum(u-1)
        }
    }
}

/*
Cách viết gọn các hàm update và getSum:

void update(int i, int v) {
    for (; i < MAXN; i += i & -i)
        bit[i] += v;
}

int get(int i) {
    int ans = 0;
    for (; i; i -= i & -i)
        ans += bit[i];
    return ans;
}

// Hàm reset dữ liệu (nếu cần)
void reset(int n) {
    for (int i = 1; i <= n; ++i) {
        a[i] = 0;
        bit[i] = 0;
    }
}
*/