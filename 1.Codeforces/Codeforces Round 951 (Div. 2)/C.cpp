///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5), res(n + 5, 0);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    int ans = -1, l = 1, r = 1e9, mid;
    while(l <= r){
        mid = (l + r) / 2;
        int cnt = mid, ind = 0;
        for (int i = 1; i <= n; ++i){
            int tmp = mid / v[i] + 1;
            if (tmp <= cnt) res[i] = tmp, cnt -= tmp;
            else break;
            ind = i;
        }
        if (ind == n) r = mid - 1, ans = mid;
        else l = mid + 1;
    }

    if (ans == -1) cout << ans << endl;
    else {
        for (int i = 1; i <= n; ++i) cout << res[i] << ' '; cout << endl;
    }

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}




