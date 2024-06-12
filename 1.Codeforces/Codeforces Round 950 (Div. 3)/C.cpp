///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    vector<int>ori(n + 5), get(n + 5);
    for (int i = 1; i <= n; ++i) cin >> ori[i];
    for (int i = 1; i <= n; ++i) cin >> get[i];

    int m;
    cin >> m;
    vector<int>ope(m + 5);
    for (int i = 1; i <= m; ++i) cin >> ope[i];

    map<int, int>mp;
    for (int i = 1; i <= n; ++i){
        if (ori[i] != get[i]) ++mp[get[i]];
    }
    map<int, int>mp2;
    for (int i = 1; i <= m; ++i) ++mp2[ope[i]];
    for (auto x : mp){
        if (mp2[x.first] < x.second){
            cout << "NO" << endl;
            return ;
        }
    }
    for (int i = 1; i <= n; ++i){
        if (get[i] == ope[m]){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}



