#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int MAXP = 31622776;
vector<int> pr;

void sieve() {
    vector<bool> isp(MAXP + 1, true);
    isp[0] = isp[1] = false;
    for (int i = 2; 1LL * i * i <= MAXP; ++i) {
        if (isp[i]) {
            for (int j = i * 2; j <= MAXP; j += i)
                isp[j] = false;
        }
    }
    for (int i = 2; i <= MAXP; ++i)
        if (isp[i]) pr.pb(i);
}

void factor(ll x, map<ll, int> &mp) {
    for (int p : pr) {
        if (1LL * p * p > x) break;
        while (x % p == 0) {
            mp[p]++;
            x /= p;
        }
    }
    if (x > 1) mp[x]++;
}

void factor_arr(const vector<ll> &a, map<ll, int> &mp) {
    for (ll x : a) factor(x, mp);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    sieve();
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    map<ll, int> fa;
    factor_arr(a, fa);
    vector<int> res;
    for (int i = 1; i <= m; ++i) {
        vector<ll> b(n);
        for (ll &x : b) cin >> x;
        map<ll, int> fb;
        factor_arr(b, fb);
        bool ok = true;
        for (auto it = fb.begin(); it != fb.end(); ++it) {
            ll p = it->first;
            int c = it->second;
            if (fa[p] < c) {
                ok = false;
                break;
            }
        }
        if (ok) res.pb(i);
    }
    cout << res.size() << "\n";
    for (int i : res) cout << i << " ";
    cout << "\n";
}

// map 0.29s 15300kB