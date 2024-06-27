///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    vector<int>tmp = v;
    sort(tmp.begin() + 1, tmp.begin() + n + 1);
    map<int, int>mp;
    for (int i = 1; i <= n; ++i) ++mp[tmp[i]];
    vector<int>res(n + 5, 0);
    for (int i = 1; i <= n; ++i){
        if (tmp[n] == v[i] && mp[tmp[n]] == 1) res[i] = v[i] - tmp[n - 1];
        else res[i] = v[i] - tmp[n];
    }
    for (int i= 1; i <= n; ++i) cout << res[i] << ' '; cout << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}



