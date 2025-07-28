#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> res;
    for (int t = 1; t <= m; ++t) {
        vector<ll> b(n);
        for (int i = 0; i < n; ++i) cin >> b[i];
        vector<ll> cura = a;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ll g = __gcd(cura[i], b[j]);
                if (g > 1) {
                    cura[i] /= g;
                    b[j] /= g;
                }
            }
        }
        int ok = 1;
        for (int j = 0; j < n; ++j) {
            if (b[j] != 1) {
                ok = 0;
                break;
            }
        }
        if (ok) res.pb(t);
    }
    cout << res.size() << "\n";
    for (int i : res) cout << i << " ";
}

// CT toán học, AC 0.04s 1528kB