#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

vector<pair<ll, ll>> f(ll k) {
    vector<pair<ll, ll>> res;
    for (ll i = 2; i * i <= k; ++i) {
        if (k % i == 0) {
            ll cnt = 0;
            while (k % i == 0) {
                ++cnt;
                k /= i;
            }
            res.pb({i, cnt});
        }
    }
    if (k > 1) res.pb({k, 1});
    return res;
}

ll l(ll n, ll p) {
    ll s = 0;
    while (n) {
        s += n / p;
        n /= p;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<pair<ll, ll>> a = f(k);
        ll m = 1e18;
        for (auto it = a.begin(); it != a.end(); ++it) {
            ll p = it->first;
            ll e = it->second;
            ll c = l(n, p) / e;
            if (c < m) m = c;
        }
        cout << m << '\n';
    }
}