///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, s, t;
    cin >> n >> s >> t;
    vector<pair<int, int>>pv;
    pv.push_back({0, 0});
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        pv.push_back({a, b});
    }
    if (pv[1].first >= s || (t - pv[n].second) >= s) {
        cout << "YES" << endl;
        return;
    }
    for (int i = 1; i < n; ++i) {
        if (pv[i + 1].first - pv[i].second >= s) {
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
    while(tt--) sol();
    return 0;
}



