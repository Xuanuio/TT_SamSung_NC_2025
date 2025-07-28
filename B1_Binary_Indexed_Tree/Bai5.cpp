#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end()

const int MAXN = 200005;

void fast_io(bool use_file = false)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (use_file)
    {
        freopen("INPUT.IN", "r", stdin);
        freopen("OUTPUT.OUT", "w", stdout);
    }
}

// Binary Indexed Tree (Fenwick Tree)
class BIT
{
private:
    vector<int> tree;
    int n;

public:
    BIT(int size)
    {
        n = size + 2;
        tree.resize(n, 0);
    }

    void update(int idx, int delta)
    {
        while (idx < n)
        {
            tree[idx] += delta;
            idx += idx & -idx;
        }
    }

    int query(int idx)
    {
        int res = 0;
        while (idx > 0)
        {
            res += tree[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};

int dist(pair<int, int> a, pair<int, int> b)
{
    long long dx = 1LL * (a.first - b.first);
    long long dy = 1LL * (a.second - b.second);
    return (int)ceil(sqrt(dx * dx + dy * dy));
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &p : a)
        cin >> p.first >> p.second;

    pair<int, int> A1, A2;
    int q;
    cin >> A1.first >> A1.second >> A2.first >> A2.second >> q;

    struct Query
    {
        int r1, r2, id;
    };

    vector<Query> que(q);
    for (int i = 0; i < q; i++)
    {
        cin >> que[i].r1 >> que[i].r2;
        que[i].id = i;
    }

    for (auto &p : a)
    {
        int x = p.first, y = p.second;
        p.first = dist({x, y}, A1);
        p.second = dist({x, y}, A2);
    }

    sort(all(a));

    sort(all(que), [](const Query &x, const Query &y)
        { return x.r1 < y.r1; });

    BIT bit(MAXN);
    vector<int> ans(q);
    int idx = 0;

    for (auto &p : a)
        bit.update(p.second, 1);

    for (auto &qr : que)
    {
        while (idx < n && a[idx].first <= qr.r1)
        {
            bit.update(a[idx].second, -1);
            idx++;
        }

        ans[qr.id] = idx + bit.query(qr.r2);
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << '\n';
}

int32_t main()
{
    fast_io(false);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}