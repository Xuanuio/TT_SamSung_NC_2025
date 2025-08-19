#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD1 = 1000000007LL;
const ll MOD2 = 1000000009LL;
const ll BASE = 131;

struct DoubleHash {
    vector<ll> p1, p2, pre1, pre2;
    int n;
    void build(const string &s) {
        n = s.size();
        p1.assign(n + 1, 1);
        p2.assign(n + 1, 1);
        pre1.assign(n + 1, 0);
        pre2.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            p1[i] = (p1[i - 1] * BASE) % MOD1;
            p2[i] = (p2[i - 1] * BASE) % MOD2;
            ll v = (s[i - 1] - 'a' + 1);
            pre1[i] = (pre1[i - 1] * BASE + v) % MOD1;
            pre2[i] = (pre2[i - 1] * BASE + v) % MOD2;
        }
    }
    pair<ll,ll> getHash(int l, int r) {
        ll x1 = (pre1[r] - pre1[l - 1] * p1[r - l + 1]) % MOD1;
        if (x1 < 0) x1 += MOD1;
        ll x2 = (pre2[r] - pre2[l - 1] * p2[r - l + 1]) % MOD2;
        if (x2 < 0) x2 += MOD2;
        return {x1, x2};
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();
    DoubleHash ha, hb;
    ha.build(a);
    hb.build(b);
    auto hb_val = hb.getHash(1, m);

    vector<int> res;
    for (int i = 1; i + m - 1 <= n; i++) {
        if (ha.getHash(i, i + m - 1) == hb_val) {
            res.push_back(i);
        }
    }
    
    for(int x : res) cout << x << " ";
}