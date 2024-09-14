#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define faster(); ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

void sol(){
    int n, k, gcd = 0;
    cin >> n >> k;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i], gcd = __gcd(gcd, v[i]);
    int res = 0, l = 0, r = 1e10, mid;
    while(l <= r) {
        mid = (l + r) / 2;
        int pos;
        if (mid / gcd == n || n == 1) pos = mid + 1 - min(n, (mid / gcd));
        else pos = mid + 1 - min(n, (mid / gcd + 1));
        if (pos < k) l = mid + 1;
        else r = mid - 1, res = mid;
    }
    cout << res << endl;
}

int32_t main(){
    faster();
    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}
