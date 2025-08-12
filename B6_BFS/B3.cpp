#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M, Q;
    cin >> N >> M >> Q;
    vector<string> grid(N);
    for (int i = 0; i < N; i++) cin >> grid[i];

    const int INF = 1e9;
    vector<vector<int>> dist(N, vector<int>(M, INF));
    deque<pair<int,int>> dq;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '*') {
                dist[i][j] = 0;
                dq.emplace_back(i, j);
            }
        }
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!dq.empty()) {
        auto [x, y] = dq.front();
        dq.pop_front();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            int w = (grid[nx][ny] == grid[x][y]) ? 0 : 1;
            if (dist[nx][ny] > dist[x][y] + w) {
                dist[nx][ny] = dist[x][y] + w;
                if (w == 0) dq.emplace_front(nx, ny);
                else dq.emplace_back(nx, ny);
            }
        }
    }

    while (Q--) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        cout << dist[x][y] << "\n";
    }
}