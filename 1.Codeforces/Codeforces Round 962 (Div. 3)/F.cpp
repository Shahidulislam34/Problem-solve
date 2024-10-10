#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);


void sol(){
    int n, k;
    cin >> n >> k;
    vector<int>aa(n + 5), bb(n + 5);
    for (int i = 1; i <= n; ++i) cin >> aa[i];
    for (int i = 1; i <= n; ++i) cin >> bb[i];

    int mn = 0, l = 0, r = (int)1e9, mid;
    while(l <= r) {
        mid = (l + r) / 2;
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            cnt += ceil((double)(max(0ll, aa[i] - mid + 1)) / bb[i]);
        }
        if (cnt >= k) mn = mid, l = mid + 1;
        else r = mid - 1;
    }
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int m = ceil((double)(max(0ll, aa[i] - (mn + 1) + 1)) / bb[i]);
        int a = aa[i] - max(0ll, m - 1) * bb[i];
        int d = bb[i];
        ans += (m * (2 * a + (m - 1) * d)) / 2;
        cnt += m;
    }
    ans += (k - cnt) * mn;
    cout << ans << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}





