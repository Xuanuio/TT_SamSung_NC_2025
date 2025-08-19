#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD1 = 1000000007LL;
const ll MOD2 = 1000000009LL;
const ll BASE = 131;                 

struct DoubleHash {
    int n;
    vector<ll> p1, p2;               
    vector<ll> pre1, pre2;           
    vector<ll> suf1, suf2;           

    void build(const string &s, int n) {
        p1.assign(n + 2, 1);
        p2.assign(n + 2, 1);
        pre1.assign(n + 2, 0);
        pre2.assign(n + 2, 0);
        suf1.assign(n + 3, 0);
        suf2.assign(n + 3, 0);

        for (int i = 1; i <= n; ++i) {
            p1[i] = (p1[i - 1] * BASE) % MOD1;
            p2[i] = (p2[i - 1] * BASE) % MOD2;

            ll v = (unsigned char)s[i - 1] + 1;   
            pre1[i] = (pre1[i - 1] * BASE + v) % MOD1;
            pre2[i] = (pre2[i - 1] * BASE + v) % MOD2;
        }
        for (int i = n; i >= 1; --i) {
            ll v = (unsigned char)s[i - 1] + 1;
            suf1[i] = (suf1[i + 1] * BASE + v) % MOD1;
            suf2[i] = (suf2[i + 1] * BASE + v) % MOD2;
        }
    }

    inline pair<ll,ll> getForward(int l, int r) { 
        ll x1 = (pre1[r] - pre1[l - 1] * p1[r - l + 1]) % MOD1; if (x1 < 0) x1 += MOD1;
        ll x2 = (pre2[r] - pre2[l - 1] * p2[r - l + 1]) % MOD2; if (x2 < 0) x2 += MOD2;
        return {x1, x2};
    }
    inline pair<ll,ll> getBackward(int l, int r) { 
        ll y1 = (suf1[l] - suf1[r + 1] * p1[r - l + 1]) % MOD1; if (y1 < 0) y1 += MOD1;
        ll y2 = (suf2[l] - suf2[r + 1] * p2[r - l + 1]) % MOD2; if (y2 < 0) y2 += MOD2;
        return {y1, y2};
    }
    inline bool isPal(int l, int r) {
        return getForward(l, r) == getBackward(l, r);
    }
};

int longest_pal_hash(const string& s, int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    DoubleHash H;
    H.build(s, n);

    int ans = 1;

    for (int i = 1; i <= n; ++i) {
        int lo = 0, hi = min(i - 1, n - i), best = 0;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int l = i - mid, r = i + mid;
            if (H.isPal(l, r)) {
                best = mid; lo = mid + 1;
            } else hi = mid - 1;
        }
        ans = max(ans, best * 2 + 1);
    }

    for (int i = 1; i < n; ++i) {
        int lo = 0, hi = min(i, n - i), best = 0;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;   
            int l = i - mid + 1, r = i + mid;
            if (l <= r && H.isPal(l, r)) {
                best = mid; lo = mid + 1;
            } else hi = mid - 1;
        }
        ans = max(ans, best * 2);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n; 
        string s;
        cin >> n >> s;
        cout << longest_pal_hash(s, n) << '\n';
    }
}