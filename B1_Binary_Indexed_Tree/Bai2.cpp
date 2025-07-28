#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005
#define int long long

int a[MAXN], bit[MAXN];

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
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int diff = a[i] - a[i - 1];
        update(i, diff); 
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int cmd, u, v, val;
        cin >> cmd;
        if (cmd == 1) {
            cin >> u >> v >> val;
            update(u, val);       
            update(v + 1, -val);  
        } else {
            cin >> u;
            cout << get(u) << '\n';
        }
    }
}