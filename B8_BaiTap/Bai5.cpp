#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Matrix {
    int n;
    vector<vector<ll>> m;
    ll mod;
    Matrix(int n, ll mod, bool ident = false): n(n), mod(mod) {
        m.assign(n, vector<ll>(n, 0));
        if (ident) {
            for (int i = 0; i < n; i++) m[i][i] = 1;
        }
    }
    Matrix operator*(const Matrix& other) const {
        Matrix res(n, mod);
        for (int i = 0; i < n; i++)
            for (int k = 0; k < n; k++) if (m[i][k])
                for (int j = 0; j < n; j++) {
                    res.m[i][j] = (res.m[i][j] + m[i][k] * other.m[k][j]) % mod;
                }
        return res;
    }
    Matrix operator+(const Matrix& other) const {
        Matrix res(n, mod);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                res.m[i][j] = (m[i][j] + other.m[i][j]) % mod;
        return res;
    }
};

Matrix matPow(Matrix A, long long k) {
    Matrix res(A.n, A.mod, true);
    while (k) {
        if (k & 1) res = res * A;
        A = A * A;
        k >>= 1;
    }
    return res;
}

Matrix matSum(Matrix A, long long k) {
    if (k == 0) return Matrix(A.n, A.mod);
    if (k == 1) return A;
    if (k % 2 == 0) {
        Matrix half = matSum(A, k/2);
        Matrix P = matPow(A, k/2);
        Matrix I(A.n, A.mod, true);
        return half * (I + P);
    } else {
        Matrix prev = matSum(A, k-1);
        Matrix Ak = matPow(A, k);
        return prev + Ak;
    }
}

bool isPrime(long long x) {
    if (x < 2) return false;
    if (x % 2 == 0) return (x == 2);
    for (long long i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int N; long long K, M;
        cin >> N >> K >> M;
        vector<long long> a(N);
        for (int i = 0; i < N; i++) cin >> a[i];

        Matrix Adj(N, M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) if (i != j) {
                long long val = 6 * a[i] + a[j];
                if (isPrime(val)) Adj.m[i][j] = 1;
            }
        }

        Matrix S = matSum(Adj, K);
        cout << S.m[0][N-1] % M << "\n";
    }
}