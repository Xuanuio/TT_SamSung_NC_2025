#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define gnuhn 1000006

int mpr[gnuhn]; // smallest prime factor

void sieve() {
    mpr[1] = 1;
    for (int i = 2; i < gnuhn; i++) {
        if (mpr[i] == 0) {
            mpr[i] = i;
            if (1LL * i * i < gnuhn) {
                for (ll j = 1ll * i * i; j < gnuhn; j += i) {
                    if (!mpr[j]) mpr[j] = i;
                }
            }
        }
    }
}

ll count_divisors(int n) {
    ll ans = 1;
    while (n > 1) {
        int cnt = 0;
        int d = mpr[n];
        while (n % d == 0) {
            n /= d;
            cnt++;
        }
        ans *= (cnt + 1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    sieve();
    int t; cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        if(n == 0) cout << "0\n";
        else cout << count_divisors(n) << "\n";
    }
}