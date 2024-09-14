#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, x;
    cin >> n >> x;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    set<int, greater<int>>div;
    div.insert(x);
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0){
            div.insert(i);
            div.insert(x / i);
        }
    }
    unordered_map<int, int>mp;
    int res = 1;
    for (int i = 1; i <= n; ++i) {
        if ((x % v[i]) == 0) {
            for (auto m : div) {
                if (mp[m] == 1 && (x % (v[i] * m)) == 0) mp[v[i] * m] = 1;
            }
            mp[v[i]] = 1;
            if (mp[x] == 1) {
                mp.clear();
                ++res;
                mp[v[i]] = 1;
            }
        }

    }
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}
