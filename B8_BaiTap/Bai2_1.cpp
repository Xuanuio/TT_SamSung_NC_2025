#include <bits/stdc++.h>
using namespace std;

const int MAXA = 1000000;
int BIT[MAXA+5];
int n = 0; // số phần tử hiện tại

// update BIT[x] += val
void update(int x, int val) {
    for (; x <= MAXA; x += x & -x) BIT[x] += val;
}

// prefix sum [1..x]
int getSum(int x) {
    int s = 0;
    for (; x > 0; x -= x & -x) s += BIT[x];
    return s;
}

// tìm chỉ số nhỏ nhất pos sao cho prefix_sum(pos) >= k
int kth(int k) {
    int pos = 0, sum = 0;
    for (int i = 20; i >= 0; i--) { // 2^20 > 1e6
        int next = pos + (1 << i);
        if (next <= MAXA && sum + BIT[next] < k) {
            pos = next;
            sum += BIT[next];
        }
    }
    return pos + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q; cin >> Q;
    while (Q--) {
        string op; cin >> op;
        if (op == "add") {
            int x; cin >> x;
            update(x, 1);
            n++;
        } else if (op == "del") {
            int x; cin >> x;
            update(x, -1);
            n--;
        } else { // print
            int k = (n + 1) / 2;
            cout << kth(k) << "\n";
        }
    }
}