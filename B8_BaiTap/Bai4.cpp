#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll costHorizontal(vector<ll> X, vector<ll> Y) {
    int n = X.size();
    sort(X.begin(), X.end());

    vector<ll> diff(n);
    for (int i = 0; i < n; i++) diff[i] = X[i] - i;
    sort(diff.begin(), diff.end());
    ll p = diff[n / 2];

    ll costX = 0;
    for (int i = 0; i < n; i++) {
        costX += llabs(X[i] - (p + i));
    }

    sort(Y.begin(), Y.end());
    ll c = Y[n / 2];
    ll costY = 0;
    for (int i = 0; i < n; i++) {
        costY += llabs(Y[i] - c);
    }

    return costX + costY;
}

ll costVertical(vector<ll> X, vector<ll> Y) {
    int n = X.size();
    sort(Y.begin(), Y.end());

    vector<ll> diff(n);
    for (int i = 0; i < n; i++) diff[i] = Y[i] - i;
    sort(diff.begin(), diff.end());
    ll p = diff[n / 2];

    ll costY = 0;
    for (int i = 0; i < n; i++) {
        costY += llabs(Y[i] - (p + i));
    }

    sort(X.begin(), X.end());
    ll c = X[n / 2];
    ll costX = 0;
    for (int i = 0; i < n; i++) {
        costX += llabs(X[i] - c);
    }

    return costX + costY;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<ll> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

    ll ans = min(costHorizontal(X, Y), costVertical(X, Y));
    cout << ans << "\n";
}