#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

void sol(){
    int n, x;
    cin >> n >> x;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    sort(v.begin() + 1, v.begin() + n + 1);
    int ind = 1, res = n;
    map<int, int>mp;
    for (int i = 0; i <= n; ++i) {
        for (; ind <= n; ++ind) {
            if (v[ind] <= i) ++mp[v[ind] % x];
            else break;
        }
        if (mp[i % x] == 0) {
            res = i;
            break;
        }
        else --mp[i % x];
    }
    cout << res << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}







