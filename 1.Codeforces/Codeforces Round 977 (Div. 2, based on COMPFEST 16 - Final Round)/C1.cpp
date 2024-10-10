#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

void sol(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<int>v(n + 1);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    vector<int>v2(m + 1);
    for (int i = 1; i <= m; ++i) cin >> v2[i];

    int ind = 0, flag = 1;
    vector<int>vis(n + 1, 0);
    for (int i = 1; i <= m; ++i) {
       if (vis[v2[i]] == 1) continue;
       else {
            ++ind;
            if (ind <= n) vis[v[ind]] = 1;
            if (vis[v2[i]] == 0) {
                flag = 0; break;
            }
       }
    }
    if (flag) cout << "YA" << endl;
    else cout << "TIDAK" << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}








