#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005                
#define int long long  
#define endl '\n'            

int a[MAXN], bit[MAXN];

void update(int idx, int val) {
    while (idx < MAXN) {
        bit[idx] += val; 
        idx += (idx & -idx); 
    }
}

int getSum(int idx) {
    int ans = 0;
    while (idx > 0) {
        ans += bit[idx];   
        idx -= (idx & -idx);     
    }
    return ans;                 
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);               

    int n;
    cin >> n;          

    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; 
        update(i, a[i]); 
    }

    int q;
    cin >> q;
    while (q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int u, val;
            cin >> u >> val;
            update(u, val);
        } else if (cmd == 2) {
            int u, v;
            cin >> u >> v;
            cout << getSum(v) - getSum(u - 1) << endl;
        }
    }
}

// Cay BIT