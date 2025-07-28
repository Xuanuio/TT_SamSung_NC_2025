#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005
#define int long long

int n, q;
int a[100005], f[100005], bit[MAXN];
int ans = 0;

void update(int idx, int val) {
    while (idx < MAXN) {
        bit[idx] += val;          
        idx += (idx & -idx);     
    }
}

int get(int idx) {
    int ans = 0;
    while (idx > 0) {
        ans += bit[idx];          
        idx -= (idx & -idx);      
    }
    return ans;                  
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    // for(int i=n; i>=1; i--){
    //     int sum = 0;
    //     for(int j=1; j<=a[i]-1; j++){
    //         sum = sum + dem[j];
    //     }
    //     f[i] = sum;
    //     ans += f[i];
    //     dem[a[i]]++;
    //     cout << i << " " << sum << endl;
    // }
    for(int i=n; i>=1; i--){
        f[i] = get(a[i] - 1);
        ans += f[i];
        update(a[i], 1);
    }
    cout << ans << endl;
}