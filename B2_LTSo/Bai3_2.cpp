#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll calc(ll n, ll p) {
    ll res = 0;
    while (n) {
        res += n / p;
        n /= p;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        map<ll, ll> mp;
        ll tmp = k;
        for (ll i = 2; i * i <= tmp; i++) {
            while (k % i == 0) {
                mp[i]++;
                k /= i;
            }
        }
        if (k > 1) mp[k]++;
        ll ans = LLONG_MAX;
        for (auto it : mp) {
            ll p = it.first, e = it.second;
            ll pw = calc(n, p); 
            ans = min(ans, pw / e);
        }
        cout << ans << '\n';
    }
}