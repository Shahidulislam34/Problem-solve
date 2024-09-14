#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define faster(); ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5, 0);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    int res = (n * (n + 1) * (n + 2)) / 6;
    map<int, int>mp;
    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        for (int j = i; j >= 1; --j) {
            sum += v[j];
            ++mp[sum];
            res -= mp[sum];
        }
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

