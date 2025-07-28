#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
vector<ll> a;

ll cnt(ll x) {
    ll res = 0;
    int m = a.size();
    for (int mask = 1; mask < (1 << m); ++mask) {
        ll lcm = 1;
        bool ok = true;
        for (int i = 0; i < m; ++i) {
            if (mask >> i & 1) {
                ll g = __gcd(lcm, a[i]);
                if (lcm > x / (a[i] / g)) {
                    ok = false;
                    break;
                }
                lcm = lcm / g * a[i];
            }
        }
        if (!ok) continue;
        int bits = __builtin_popcount(mask);
        if (bits % 2) res += x / lcm;
        else res -= x / lcm;
    }
    return x - res;
}

ll solve(ll k) {
    ll l = 1, r = 1e18, ans = -1;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (cnt(mid) >= k) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll k;
        cin >> n >> k;
        a.resize(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << solve(k) << "\n";
    }
}