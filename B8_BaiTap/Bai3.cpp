#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll tri(ll k){ 
    return k*(k+1)/2; 
}

ll value_at(ll x, ll y){
    ll k = x + y - 1;
    return k*(k-1)/2 + y;
}

pair<ll,ll> pos_of(ll z){
    long double t = (sqrtl(8.0L*z + 1) - 1) / 2;
    ll k = (ll)floor(t);
    if(tri(k) < z) ++k;              
    while (tri(k-1) >= z) --k;       
    ll y = z - tri(k-1);
    ll x = k - y + 1;
    return {x, y};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll x, y, z;
    cin >> x >> y >> z;

    cout << value_at(x, y) << "\n";
    auto [r, c] = pos_of(z);
    cout << r << " " << c << "\n";
}