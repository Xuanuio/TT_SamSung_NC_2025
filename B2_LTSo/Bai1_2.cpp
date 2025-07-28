#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
const int MAXP = 1e7 + 5;

vector<ll> p;
bitset<MAXP> ip;

void sieve() {
    ip.set();
    ip[0] = ip[1] = 0;
    for (ll i = 2; i < MAXP; ++i) {
        if (ip[i]) {
            p.pb(i);
            for (ll j = i * i; j < MAXP; j += i)
                ip[j] = 0;
        }
    }
}

void f(ll n) {
    for (ll x : p) {
        if (x * x > n) break;
        int cnt = 0;
        while (n % x == 0) {
            n /= x;
            cnt++;
        }
        if (cnt > 0) cout << x << " " << cnt << '\n';
    }
    if (n > 1) cout << n << " 1\n";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        f(n);
    }
}