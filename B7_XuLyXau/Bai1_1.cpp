#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define sz size

vi buildLPS(string pat){
    int m = pat.sz();
    vi lps(m, 0);
    int len = 0;
    for(int i=1; i<m; ){
        if(pat[i] == pat[len]){
            lps[i++] = ++len;
        }
        else{
            if(len != 0) len = lps[len - 1];
            else lps[i++] = 0;
        }
    }
    return lps;
}

void kmp(string txt, string pat){
    int n = txt.sz(), m = pat.sz();
    vi lps = buildLPS(pat);
    int i = 0, j = 0;
    while(i < n){
        if(txt[i] == pat[j]){
            i++; j++;
        }
        if(j == m){
            cout << i - j + 1 << " ";
            j = lps[j - 1];
        }
        else if(i < n && txt[i] != pat[j]){
            if(j != 0) j = lps[j - 1];
            else i++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    kmp(a, b);
}
