#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define faster(); ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    int last[n + 5] = {0};
    for (int i = n; i >= 1; --i) {
        if (last[v[i]] == 0) last[v[i]] = i;
    }

    vector<bool>vis(n + 5, false);
    vector<int>res;
    multiset<int>ss;
    int cnt = 1, r = 1, val, bef = 0;
    for (int i = 1; i <= n; ++i) {
        for (; r <= n; ++r) {
            if (vis[v[r]] == true) continue;
            if(vis[v[r]] == false && r != bef)ss.insert(v[r]), bef = r;
            if (last[v[r]] == r) break;
        }
        if (ss.empty()) break;
        if (cnt % 2 == 1) val = *ss.rbegin();
        else val = *ss.begin();
        for (; i <= n; ++i) {
            if (val == v[i] && vis[val] == false) {
                res.push_back(val);
                ss.erase(val);
                ++cnt;
                vis[val] = true;
                if (v[r] == val) ++r;
                break;
            }
            else if (vis[v[i]] == false) ss.erase(ss.find(v[i]));
        }
    }
    cout << res.size() << endl;
    for (auto x : res) cout << x << ' '; cout << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}
