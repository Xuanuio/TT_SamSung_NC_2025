#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXN = 1e5 + 5;

ll a[MAXN];
ll tree[4 * MAXN];

// Build tree từ mảng a[]
void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

// Truy vấn tổng đoạn [l, r]
ll query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0; // ngoài đoạn
    if (l <= start && end <= r) return tree[node]; // nằm trong đoạn
    int mid = (start + end) / 2;
    ll p1 = query(2 * node, start, mid, l, r);
    ll p2 = query(2 * node + 1, mid + 1, end, l, r);
    return p1 + p2;
}

// Cập nhật: tăng a[u] thêm val
void update(int node, int start, int end, int u, ll val) {
    if (u < start || u > end) return;
    if (start == end) {
        tree[node] += val;
        return;
    }
    int mid = (start + end) / 2;
    update(2 * node, start, mid, u, val);
    update(2 * node + 1, mid + 1, end, u, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);               

    int n; cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    build(1, 1, n);

    int q; cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int u; ll k;
            cin >> u >> k;
            update(1, 1, n, u, k);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
        }
    }
}

// Segment Tree