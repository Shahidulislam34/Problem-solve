#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);


void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    sort(v.begin() + 1, v.begin() + n + 1);

    int res = v[1], gcd = v[1], ind, tmp;
    vector<bool>vis(n + 5, false);
    vis[1] = true;
    for (int i = 2; i <= min(30ll, n); ++i) {
        tmp = gcd;
        for (int j = 1; j <= n; ++j) {
            if (vis[j] == true) continue;
            if (__gcd(gcd, v[j]) < tmp) tmp = __gcd(gcd, v[j]), ind = j;
        }
        if (tmp == gcd) break;
        else res += tmp, vis[ind] = true, gcd = tmp;
    }
    for (int i = 1; i <= n; ++i) if (vis[i] == false) res += gcd;
    cout << res << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}
