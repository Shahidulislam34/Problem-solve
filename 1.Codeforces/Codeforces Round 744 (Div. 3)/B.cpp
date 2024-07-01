#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    vector<pair<pair<int, int>, int>>res;
    for (int i = n; i >= 1; --i){
        int val = INT_MIN, ind;
        for (int j = 1; j <= i; ++j){
            if (val <= v[j]){
                val = v[j];
                ind = j;
            }
        }
        if (ind == i) continue;
        res.push_back({{ind, i}, 1});
        int tmp = val;
        for (int j = ind + 1; j <= i; ++j) v[j - 1] = v[j];
        v[i] = val;
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i){
        cout << res[i].first.first << ' ' << res[i].first.second << ' ' << res[i].second << endl;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}









