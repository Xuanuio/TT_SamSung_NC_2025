#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int a[MAXN];
pair<int, int> tree[4 * MAXN]; 

pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
    vector<int> vals = {a.first, a.second, b.first, b.second};
    sort(vals.begin(), vals.end(), greater<int>());
    return {vals[0], vals[1]};
}

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = {a[l], 0}; 
        return;
    }

    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);

    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

void update(int node, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) {
        a[pos] = val;
        tree[node] = {val, 0};
        return;
    }

    int mid = (l + r) / 2;
    update(2 * node, l, mid, pos, val);
    update(2 * node + 1, mid + 1, r, pos, val);

    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

pair<int, int> query(int node, int l, int r, int u, int v) {
    if (v < l || r < u) return {0, 0};
    if (u <= l && r <= v) return tree[node];

    int mid = (l + r) / 2;
    auto left = query(2 * node, l, mid, u, v);
    auto right = query(2 * node + 1, mid + 1, r, u, v);
    return merge(left, right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);               

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    build(1, 1, n);

    while (m--) {
        string cmd;
        int u, v;
        cin >> cmd >> u >> v;
        if (cmd == "Q") {
            auto res = query(1, 1, n, u, v);
            cout << res.first + res.second << "\n";
        } else if (cmd == "U") {
            update(1, 1, n, u, v);
        }
    }
}