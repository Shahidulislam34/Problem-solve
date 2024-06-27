///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    string s1, s2;
    cin >> s1 >> s2;
    int mx = 0, ind1 = 0, ind2 = 0;
    int sz1 = s1.size(), sz2 = s2.size();
    for (int i = 0; i < sz2; ++i){
        ind2 = i;
        int cnt = 0;
        for (int j = 0; j < sz1; ++j){
            if (ind2 < sz2 && s2[ind2] == s1[j]){
                ++cnt;
                ++ind2;
            }
        }
        mx = max(cnt, mx);
    }
    cout << sz1 + (sz2 - mx) << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}







