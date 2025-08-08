#include <bits/stdc++.h>
using namespace std;

#define ll long long

// Modulo dùng để tránh tràn số và giữ kết quả nhỏ
const int MOD = 1e9 + 7;

// Cấu trúc ma trận 2x2
struct matrix {
    ll x[2][2];

    // Nạp chồng toán tử nhân ma trận
    friend matrix operator * (matrix a, matrix b) {
        matrix c;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c.x[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    // Nhân từng phần tử và lấy mod để tránh tràn
                    c.x[i][j] += ((a.x[i][k] % MOD) * (b.x[k][j] % MOD)) % MOD;
                    c.x[i][j] %= MOD;
                }
            }
        }
        return c;
    }
};

// Hàm lũy thừa ma trận: tính a^n (ma trận mũ n) bằng đệ quy
matrix binPow(matrix a, ll n) {
    // Cơ sở: a^1 = a
    if (n == 1) return a;

    // Gọi đệ quy tính a^(n/2)
    matrix tmp = binPow(a, n / 2);

    // Nếu n lẻ: a^n = a^(n/2) * a^(n/2) * a
    // Nếu n chẵn: a^n = a^(n/2) * a^(n/2)
    if (n % 2 == 1)
        return tmp * tmp * a;
    else
        return tmp * tmp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // Ma trận cơ sở dùng để tính Fibonacci
    // Ma trận này sinh ra dãy: F(n) = F(n-1) + F(n-2)
    matrix a;
    a.x[0][0] = 1; a.x[0][1] = 1;
    a.x[1][0] = 1; a.x[1][1] = 0;

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        // Trường hợp n = 0 thì F(0) = 0
        // Bạn có thể mở dòng này nếu đề yêu cầu chính xác F(0)
        // if(n == 0) {
        //     cout << "0\n";
        //     continue;
        // }

        // Tính ma trận a^n
        matrix ans = binPow(a, n);

        // Số Fibonacci thứ n được lưu tại ans.x[0][1]
        cout << ans.x[0][1] << endl;
    }
}