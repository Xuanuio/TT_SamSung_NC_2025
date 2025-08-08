#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e15 + 7;

// Kích thước ma trận 4x4 để xử lý cả T(i) và F(i)
struct Matrix {
    int m[4][4];

    // Khởi tạo ma trận toàn 0
    Matrix() {
        memset(m, 0, sizeof(m));
    }

    // Trả về ma trận đơn vị (I)
    static Matrix identity() {
        Matrix res;
        for (int i = 0; i < 4; ++i) res.m[i][i] = 1;
        return res;
    }

    // Định nghĩa phép nhân hai ma trận 4x4
    Matrix operator * (const Matrix &other) const {
        Matrix res;
        for (int i = 0; i < 4; ++i) {
            for (int k = 0; k < 4; ++k) {
                for (int j = 0; j < 4; ++j) {
                    // Dùng __int128 để tránh tràn số khi nhân lớn
                    __int128 tmp = (__int128)m[i][k] * other.m[k][j];
                    res.m[i][j] = (res.m[i][j] + tmp % MOD) % MOD;
                }
            }
        }
        return res;
    }
};

// Lũy thừa ma trận theo kiểu chia để trị (O(log n))
Matrix matrix_power(Matrix base, int exp) {
    Matrix res = Matrix::identity(); // Bắt đầu từ ma trận đơn vị
    while (exp) {
        if (exp % 2) res = res * base;
        base = base * base;
        exp /= 2;
    }
    return res;
}

int solve(int n) {
    // Trường hợp cơ bản theo định nghĩa Tribonacci
    if (n == 1) return 1; // T(1) = 1
    if (n == 2) return 3; // T(1) + T(2) = 1 + 2 = 3
    if (n == 3) return 6; // T(1) + T(2) + T(3) = 1 + 2 + 3 = 6

    // Tạo ma trận chuyển trạng thái 4x4
    // Chứa 4 giá trị: T(n), T(n-1), T(n-2), F(n)
    Matrix T;
    T.m[0][0] = 1; T.m[0][1] = 1; T.m[0][2] = 1; T.m[0][3] = 0; // T(n) = T(n-1) + T(n-2) + T(n-3)
    T.m[1][0] = 1; // T(n-1) = T(n-1)
    T.m[2][1] = 1; // T(n-2) = T(n-2)
    T.m[3][0] = 1; T.m[3][1] = 1; T.m[3][2] = 1; T.m[3][3] = 1; // F(n) = F(n-1) + T(n)

    // Tính T^(n-3)
    Matrix Tn = matrix_power(T, n - 3);

    // Base vector = {T(3), T(2), T(1), F(3)} = {3, 2, 1, 6}
    // Đây là điều kiện gốc khi n = 3
    int base[4] = {3, 2, 1, 6};

    // Nhân dòng 4 của ma trận Tn với vector base để ra F(n)
    int result = 0;
    for (int i = 0; i < 4; ++i) {
        __int128 tmp = (__int128)Tn.m[3][i] * base[i]; // F(n) nằm ở hàng thứ 3 (chỉ số 3)
        result = (result + tmp % MOD) % MOD;
    }

    return result;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << '\n';
    }
}