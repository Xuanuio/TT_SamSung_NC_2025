#include <bits/stdc++.h>
using namespace std;

multiset<int> L, R;

void rebalance() {
    while ((int)L.size() > (int)(L.size() + R.size() + 1) / 2) {
        R.insert(*prev(L.end()));
        L.erase(prev(L.end()));
    }
    while ((int)L.size() < (int)(L.size() + R.size() + 1) / 2) {
        L.insert(*R.begin());
        R.erase(R.begin());
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int Q; cin >> Q;
    while (Q--) {
        string op; cin >> op;
        if (op == "add") {
            int x; cin >> x;
            if (L.empty() || x <= *prev(L.end())) L.insert(x);
            else R.insert(x);
            rebalance();
        } else if (op == "del") {
            int x; cin >> x;
            auto itL = L.find(x);
            if (itL != L.end()) L.erase(itL);
            else {
                auto itR = R.find(x);
                if (itR != R.end()) R.erase(itR);
            }
            rebalance();
        } else { // print
            cout << *prev(L.end()) << "\n";
        }
    }
}