#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, a[505][505], f[505][505];

int qhd(){
    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j]){
                f[i][j] = min(f[i-1][j] + 1, min(f[i][j-1]+1, f[i-1][j-1]+1));
            }
            ans = max(ans, f[i][j]);
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin >> a[i][j];
            }
        }
        cout << qhd() << endl;
    }
}