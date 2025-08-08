#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll MOD; // Modulo toàn cục được dùng trong phép nhân ma trận

// Định nghĩa struct matrix để biểu diễn ma trận 2x2
struct matrix {
    ll x[2][2]; // Ma trận 2x2

    // Hàm khởi tạo mặc định: khởi tạo toàn bộ phần tử bằng 0
    matrix() {
        memset(x, 0, sizeof(x));
    }

    // Nạp chồng toán tử nhân (*) để nhân hai ma trận modulo MOD
    friend matrix operator * (const matrix &a, const matrix &b) {
        matrix c;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c.x[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    // Tính tổng từng phần tử theo công thức nhân ma trận
                    // c.x[i][j] = (c.x[i][j] + a.x[i][k] * b.x[k][j]) % MOD;
                    c.x[i][j] = (c.x[i][j] + (__int128)a.x[i][k] * b.x[k][j]) % MOD;
                }
            }
        }
        return c;
    }
};

// Hàm lũy thừa ma trận: tính a^n bằng phương pháp bình phương nhị phân
matrix binPow(matrix a, ll n) {
    matrix res; // Ma trận kết quả
    res.x[0][0] = res.x[1][1] = 1; // Khởi tạo ma trận đơn vị (identity matrix)
    // res = I

    while (n > 0) {
        if (n & 1) res = res * a; // Nếu bit cuối là 1, nhân vào kết quả
        a = a * a; // Bình phương cơ sở
        n >>= 1;   // Chia n cho 2
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t; // Nhập số lượng test
    while (t--) {
        ll n;
        cin >> n >> MOD; // Nhập n và modulo

        // Trường hợp cơ bản: F(0) = F(1) = 1
        if (n == 0 || n == 1) {
            cout << 1 % MOD << '\n';
            continue;
        }

        // Ma trận cơ sở cho dãy Fibonacci:
        // | F(n)   |   =   | 1 1 | ^ n  *  | F(1) |
        // | F(n-1) |       | 1 0 |         | F(0) |
        matrix base;
        base.x[0][0] = 1;
        base.x[0][1] = 1;
        base.x[1][0] = 1;
        base.x[1][1] = 0;

        matrix result = binPow(base, n); // Tính base^n

        cout << result.x[0][0] << '\n'; // F(n) = phần tử [0][0] của ma trận
    }
}