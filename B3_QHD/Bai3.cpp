#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 1005;
const int MOD = 1e9 + 9;

ll dp[MAXN][MAXN][11];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;

    int a[MAXN], b[MAXN];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            dp[i][j][0] = 1;

    // QHD
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int t = 1; t <= k; t++) {
                dp[i][j][t] = (dp[i-1][j][t] + dp[i][j-1][t] - dp[i-1][j-1][t] + MOD) % MOD;
                if(a[i-1] > b[j-1]) {
                    dp[i][j][t] = (dp[i][j][t] + dp[i-1][j-1][t-1]) % MOD;
                }
            }
        }
    }

    cout << dp[n][m][k] << "\n";
    return 0;
}