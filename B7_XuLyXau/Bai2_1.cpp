#include <bits/stdc++.h>
using namespace std;

#define sz size

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
        int n; cin >> n;
		int res = 0;
		string s; cin >> s;
		int maxlen = 1;
		for (int i = 0; i < s.sz(); i++) {
			int l = i, r = i;
			while (l >= 0 && r < s.sz()) {
				if (s[l] == s[r]) {
					maxlen = max(maxlen, r - l + 1);
					l--; r++;
				}
				else break;
			}
		}
		for (int i = 0; i < s.sz() - 1; i++) {
			int l = i, r = i + 1;
			while (l >= 0 && r < s.sz()) {
				if (s[l] == s[r]) {
					maxlen = max(maxlen, r - l + 1);
					l--; r++;
				}
				else break;
			}
		}
		cout << maxlen << "\n";
	}
}