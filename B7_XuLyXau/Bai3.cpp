#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD1 = 1000000007LL;
const ll MOD2 = 1000000009LL;
const ll BASE = 131;

struct DoubleHash {
    int n;
    vector<ll> p1, p2, pre1, pre2;

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

    inline pair<ll, ll> getHash(int l, int r) {
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
    
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        string S;
        cin >> N >> K >> S;

        DoubleHash H;
        H.build(S);

        int ans = 0;
        int lo = 1, hi = N;

        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            unordered_map<long long, int> cnt;
            bool ok = false;

            for (int i = 1; i + mid - 1 <= N; i++) {
                auto h = H.getHash(i, i + mid - 1);
                long long key = (h.first << 32) ^ h.second; 
                if (++cnt[key] >= K) {
                    ok = true;
                    break;
                }
            }

            if (ok) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        cout << ans << "\n";
    }
}
