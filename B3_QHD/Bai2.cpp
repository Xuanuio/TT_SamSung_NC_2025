#include <bits/stdc++.h>

using namespace std;

const int MAX = 6003;
int a, b, v, d, e;
int grid[MAX][MAX];       
int prefix[MAX][MAX];      

int getSum(int x1, int y1, int x2, int y2) {
    return prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1];
}

bool check(int len) {
    for (int i = 1; i + len - 1 <= a; ++i) {
        for (int j = 1; j + len - 1 <= b; ++j) {
            int x1 = i, y1 = j;
            int x2 = i + len - 1, y2 = j + len - 1;
            if (getSum(x1, y1, x2, y2) <= e)
                return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> v >> d >> e;
    for (int i = 0; i < v; ++i) {
        int x, y;
        cin >> x >> y;
        grid[x][y] = 1;
    }
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            prefix[i][j] = grid[i][j]
                        + prefix[i-1][j]
                        + prefix[i][j-1]
                        - prefix[i-1][j-1];
        }
    }
    int l = d, r = min(a, b), res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        int len = mid - (mid % d); 
        if (len < d) {
            l = mid + 1;
            continue;
        }
        if (check(len)) {
            res = len;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << res << '\n';
}