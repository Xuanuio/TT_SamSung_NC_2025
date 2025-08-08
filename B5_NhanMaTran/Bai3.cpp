#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll BASE;  // Biến toàn cục dùng làm modulo

// Cấu trúc ma trận 3x3
struct Matrix {
    ll mat[3][3];

    // Hàm khởi tạo: gán toàn bộ phần tử bằng 0
    Matrix() {
        memset(mat, 0, sizeof(mat));
    }

    // Toán tử nhân hai ma trận 3x3 theo modulo BASE
    Matrix operator * (const Matrix &other) const {
        Matrix res;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    res.mat[i][j] = (res.mat[i][j] + (__int128)mat[i][k] * other.mat[k][j]) % BASE;
        return res;
    }
};

// Hàm lũy thừa ma trận: tính base^power theo modulo BASE
Matrix matrixPower(Matrix base, ll power) {
    Matrix result;
    // Khởi tạo ma trận đơn vị (identity matrix)
    for (int i = 0; i < 3; ++i)
        result.mat[i][i] = 1;

    // Exponentiation by squaring (nhân lũy thừa nhanh)
    while (power > 0) {
        if (power % 2 == 1)
            result = result * base;
        base = base * base;
        power /= 2;
    }
    return result;
}

// Tính số Tesla thứ n theo công thức T(n) = T(n-1) + 2*T(n-2) + 3*T(n-3)
ll computeTesla(ll n) {
    // Trường hợp cơ bản
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 3;

    // Ma trận chuyển vị mô tả công thức truy hồi
    Matrix A;
    A.mat[0][0] = 1; A.mat[0][1] = 2; A.mat[0][2] = 3;  // T(n-1), T(n-2), T(n-3)
    A.mat[1][0] = 1;                                    // dịch T(n-1) -> T(n-2)
    A.mat[2][1] = 1;                                    // dịch T(n-2) -> T(n-3)

    // Tính A^(n-3)
    Matrix An = matrixPower(A, n - 3);

    // Vector khởi tạo: [T(3), T(2), T(1)] = [3, 2, 1]
    // Nhân ma trận An với vector để ra T(n)
    ll Tn = (An.mat[0][0] * 3 % BASE +  // T(3)
             An.mat[0][1] * 2 % BASE +  // T(2)
             An.mat[0][2] * 1 % BASE) % BASE;  // T(1)

    return Tn;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n >> BASE;
        cout << computeTesla(n) << '\n';
    }
}