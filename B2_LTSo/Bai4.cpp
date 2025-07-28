#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
const int N = 1e6 + 5;

int spf[N];
map<int, int> pf[N];

void sieve() {
    for (int i = 2; i < N; ++i)
        if (!spf[i])
            for (int j = i; j < N; j += i)
                if (!spf[j]) spf[j] = i;
    for (int i = 2; i < N; ++i) {
        int x = i;
        while (x > 1) {
            int p = spf[x];
            pf[i][p]++;
            x /= p;
        }
    }
}

map<int, int> merge3(int m) {
    map<int, int> res = pf[m];
    for (auto it : pf[m + 1]) res[it.first] += it.second;
    for (auto it : pf[m + 2]) res[it.first] += it.second;
    return res;
}

ll cnt_d(const map<int, int>& f) {
    ll r = 1;
    for (auto it : f) r *= (it.second + 1);
    return r;
}

ll cnt_e(const map<int, int>& f) {
    ll r = 1;
    for (auto it : f) r *= (2 * it.second + 1);
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        auto f = merge3(m);
        ll d = cnt_d(f);
        ll e = cnt_e(f);
        ll c = (e - 2 * d) / 2;
        cout << c + 1 << '\n';
    }
}