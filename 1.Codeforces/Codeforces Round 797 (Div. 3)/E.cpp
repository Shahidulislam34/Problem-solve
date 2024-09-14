///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, k;
    cin >> n >> k;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    int res = 0;
    for (int i = 1; i <= n; ++i) res += v[i] / k, v[i] %= k;

    sort(v.begin() + 1, v.begin() + n + 1);
    int l = 1, r = n;
    while(l < r){
        if (v[l] + v[r] >= k) ++res, ++l, --r;
        else ++l;
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


