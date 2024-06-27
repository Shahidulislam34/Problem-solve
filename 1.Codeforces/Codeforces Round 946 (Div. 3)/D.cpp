///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    string ew, ns;
    for (int i = 0; i < n; ++i){
        if (str[i] == 'E' || str[i] == 'W') ew.push_back(str[i]);
        else ns.push_back(str[i]);
    }
    sort(ew.begin(), ew.end());
    sort(ns.begin(), ns.end());

    map<char, int>rov, hel;
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    int sz1 = ew.size(), sz2 = ns.size();
    for (int i = 0; i < sz1; ++i){
        if (ew[i] == 'E'){
            if (x1 <= x2) ++x1, ++rov[ew[i]];
            else ++x2, ++hel[ew[i]];
        }
        else {
            if (x1 >= x2) --x1, ++rov[ew[i]];
            else --x2, ++hel[ew[i]];
        }
    }
    for (int i = 0; i < sz2; ++i){
        if (ns[i] == 'N'){
            if (y1 >= y2) ++y2, ++hel[ns[i]];
            else ++y1, ++rov[ns[i]];
        }
        else {
            if (y1 <= y2) --y2, ++hel[ns[i]];
            else --y1, ++rov[ns[i]];
        }
    }
    int rovm = 0, helm = 0;
    string ch = "EWNS";
    for (int i = 0; i < 4; ++i){
        if (rov[ch[i]] > 0) rovm = 1;
        if (hel[ch[i]] > 0) helm = 1;
    }
    if (x1 != x2 || y1 != y2 || rovm == 0 || helm == 0){
        cout << "NO" << endl;
        return;
    }
    string res;
    for (int i = 0; i < n; ++i){
        if (rov[str[i]] > 0) res.push_back('R'), --rov[str[i]];
        else res.push_back('H'), --hel[str[i]];
    }
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}

