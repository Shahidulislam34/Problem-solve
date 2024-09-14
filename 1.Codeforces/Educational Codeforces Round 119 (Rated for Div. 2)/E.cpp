#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int q;
    cin >> q;
    int n = 0;
    vector<int>v;
    v.push_back(0);

    int val, a, b;
    vector<pair<pair<int, int>, int>>pv;
    int sz = 0;
    while(q--) {
        int choice;
        cin >> choice;
        if (choice == 1) {
            cin >> val;
            v.push_back(val);
            ++n;
            sz = max(sz, val);
        }
        else {
            cin >> a >> b;
            pv.push_back({{a, b}, n});
            sz = max(sz, max(a, b));
        }
    }

    unordered_map<int, int>mp;
    for (int i = 1; i <= sz; ++i) mp[i] = i;
    sz = pv.size();
    for (int i = sz - 1; i > 0; --i) {
        mp[pv[i].first.first] = mp[pv[i].first.second];
        for (int j = pv[i].second; j > pv[i - 1].second; --j) {
            v[j] = mp[v[j]];
        }
    }
    if (sz > 0) {
        mp[pv[0].first.first] = mp[pv[0].first.second];
        for (int i = pv[0].second; i >= 1; --i) v[i] = mp[v[i]];
    }
    for (int i = 1; i <= n; ++i) cout << v[i] << ' '; cout << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    sol();
    return 0;
}

