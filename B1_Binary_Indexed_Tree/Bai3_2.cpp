#include<bits/stdc++.h>

using namespace std;

#define MAXN 100005
#define int long long

int a[MAXN], f[MAXN], bit[MAXN];
int ans = 0, n, t;

void update(int idx, int val){
    while(idx < MAXN){
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

int get(int idx){
    int ans = 0;
    while(idx > 0){
        ans += bit[idx];
        idx -= (idx & -idx);
    }
    return ans;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--){
        memset(f, 0, sizeof(f));
        memset(bit, 0, sizeof(bit));
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int j=n; j>=1; j--){
            f[j] = get(a[j]-1);
            update(a[j], 1);
        }
        memset(bit, 0, sizeof(bit));
        ans = 0;
        for(int i=n; i>=1; i--){
            ans += get(a[i]-1);
            update(a[i], f[i]);
        }
        cout << ans << "\n";
    }
}