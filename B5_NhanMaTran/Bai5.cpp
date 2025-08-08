#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

int n, k;

struct Matrix {
    int row, col;
    ll data[102][102];

    Matrix(int _row, int _col) : row(_row), col(_col) {
        memset(data, 0, sizeof(data));
    }

    Matrix operator * (const Matrix &other) const {
        Matrix result(row, other.col);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < other.col; ++j) {
                for (int z = 0; z < col; ++z) {
                    result.data[i][j] = (result.data[i][j] + data[i][z] * other.data[z][j] % MOD) % MOD;
                }
            }
        }
        return result;
    }
};

Matrix fastpow(const Matrix &M, int power) {
    if (power == 1) return M;
    Matrix half = fastpow(M, power / 2);
    Matrix result = half * half;
    if (power % 2 == 1) result = result * M;
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    Matrix ret(1, k);
    ret.data[0][0] = 1;

    Matrix base(k, k);
    for (int i = 0; i < k; ++i) {
        int prev1 = (i - 1 + k) % k; 
        int prev2 = (i - 2 + k) % k; 

        base.data[prev1][i] = 3;    
        base.data[prev2][i] = 3; 
        base.data[i][i] = 1; 
    }

    Matrix powBase = fastpow(base, n);

    ret = ret * powBase;

    cout << (ret.data[0][0] - 1 + MOD) % MOD << endl;
}