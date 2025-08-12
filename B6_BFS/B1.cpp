#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct State {
    string s;
    int step;
};

string rotateLeft(const string &s) {
    string t = s;
    t[0] = s[3];
    t[1] = s[0];
    t[4] = s[1];
    t[3] = s[4];
    return t;
}

string rotateRight(const string &s) {
    string t = s;
    t[1] = s[4];
    t[2] = s[1];
    t[5] = s[2];
    t[4] = s[5];
    return t;
}

int bfs(string start, string target) {
    if (start == target) return 0;
    queue<State> q;
    unordered_set<string> visited;
    q.push({start, 0});
    visited.insert(start);

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        // Xoay sang trai
        string l = rotateLeft(cur.s);
        if (!visited.count(l)) {
            if (l == target) return cur.step + 1;
            visited.insert(l);
            q.push({l, cur.step + 1});
        }
        // Xoay sang fai
        string r = rotateRight(cur.s);
        if (!visited.count(r)) {
            if (r == target) return cur.step + 1;
            visited.insert(r);
            q.push({r, cur.step + 1});
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string start = "", target = "";
    for (int i = 0; i < 6; i++) {
        int x; cin >> x;
        start.push_back(char('0' + x));
    }
    for (int i = 0; i < 6; i++) {
        int x; cin >> x;
        target.push_back(char('0' + x));
    }
    cout << bfs(start, target) << endl;
}