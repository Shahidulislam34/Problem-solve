///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    string s, t;
    cin >> s >> t;
    int ssz = s.size(), tsz = t.size();
    int ind = 0;
    for (int i = 0; i < ssz; ++i) {
        if (ind < tsz) {
            if (t[ind] == s[i]) ++ind;
            else if (s[i] == '?') s[i] = t[ind], ++ind;
        }
    }
    if (ind < tsz) cout << "NO" << endl;
    else {
        for (int i = 0; i < ssz; ++i) if (s[i] == '?') s[i] = 'a';
        cout << "YES" << endl;
        cout << s << endl;
    }

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}




