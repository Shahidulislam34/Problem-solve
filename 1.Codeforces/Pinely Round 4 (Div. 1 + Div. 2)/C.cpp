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
    vector<int>res;
    for (int i = 1; i <= 40; ++i) {
        int mn = INT_MAX, mx = INT_MIN;
        for (int j = 1; j <= n; ++j) {
            mn = min(mn, v[j]);
            mx = max(mx, v[j]);
        }
        int tmp = (mx + mn + 1) / 2;
        res.push_back(tmp);
        for (int j = 1; j <= n; ++j) {
            v[j] = abs(v[j] - tmp);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (v[i] != 0) {
            cout << -1 << endl;
            return;
        }
    }
    cout << 40 << endl;
    for (auto x : res) cout << x << ' '; cout << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}
