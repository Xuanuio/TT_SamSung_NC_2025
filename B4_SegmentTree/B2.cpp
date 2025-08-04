#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define INF 1e18;
#define int long long

int a[MAXN];       
int tree[4 * MAXN];    

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = l;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);

    int left = tree[2 * node];
    int right = tree[2 * node + 1];
    tree[node] = (a[left] <= a[right]) ? left : right;
}

int query(int node, int l, int r, int u, int v) {
    if (v < l || r < u) return 0; 
    if (u <= l && r <= v) return tree[node];

    int mid = (l + r) / 2;
    int p1 = query(2 * node, l, mid, u, v);
    int p2 = query(2 * node + 1, mid + 1, r, u, v);

    return (a[p1] <= a[p2]) ? p1 : p2;
}

void update(int node, int l, int r, int u, int val) {
    if (u < l || u > r) return;
    if (l == r) {
        a[u] = val;
        tree[node] = l;
        return;
    }

    int mid = (l + r) / 2;
    update(2 * node, l, mid, u, val);
    update(2 * node + 1, mid + 1, r, u, val);

    int left = tree[2 * node];
    int right = tree[2 * node + 1];
    tree[node] = (a[left] <= a[right]) ? left : right;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);               

    int n, m;
    cin >> n >> m;

    a[0] = INF; 

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    build(1, 1, n);

    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, val;
            cin >> u >> val;
            update(1, 1, n, u, val);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
        }
    }
}