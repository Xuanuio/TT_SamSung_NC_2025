#include<bits/stdc++.h>

using namespace std;

#define MAXN 100005
#define int long long

int a[MAXN], bit[MAXN];

void update(int idx, int val){
    while(idx < MAXN){
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

int get(int idx){
    int ans = 0;
    while(idx > 0){
        ans += bit[idx];
        idx -= (idx & -idx);
    }
    return ans;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

}