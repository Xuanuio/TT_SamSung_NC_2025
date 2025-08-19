#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct SegTree {
    int n;
    vector<ll> st;
    SegTree(int n=0){ init(n); }
    void init(int _n){
        n = _n;
        st.assign(4*n+5, 0);
    }
    inline long long gcdll(long long a, long long b){
        while(b){
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
    void build(int p, int l, int r, const vector<ll> &a){
        if (l==r){
            st[p] = a[l];
            return;
        }
        int m = (l+r)>>1;
        build(p<<1, l, m, a);
        build(p<<1|1, m+1, r, a);
        st[p] = gcdll(st[p<<1], st[p<<1|1]);
    }
    ll query(int p, int l, int r, int L, int R){
        if (L>r || R<l) return 0;
        if (L<=l && r<=R) return st[p];
        int m = (l+r)>>1;
        ll left = query(p<<1, l, m, L, R);
        ll right = query(p<<1|1, m+1, r, L, R);
        return gcdll(left, right);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        int N;
        ll K;
        cin >> N >> K;
        vector<ll> a(N+1);
        for(int i=1;i<=N;i++) cin >> a[i];

        SegTree seg(N);
        seg.build(1,1,N,a);

        int best = INT_MAX;
        for(int i=1;i<=N;i++){
            int lo = i, hi = N, pos = N+1;
            while(lo <= hi){
                int mid = (lo + hi) >> 1;
                ll g = seg.query(1,1,N,i,mid);
                if (g <= K){
                    pos = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            if (pos == N+1) continue; 
            ll gpos = seg.query(1,1,N,i,pos);
            if (gpos == K){
                best = min(best, pos - i + 1);
            }
        }

        if (best == INT_MAX) cout << -1 << "\n";
        else cout << best << "\n";
    }
}