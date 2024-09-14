#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define faster(); ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

void sol(){
    int n, q;
    cin >> n >> q;
    vector<int>cnt(n + 5, 0), pre(n + 5, 0);
    for (int i = 1; i <= n; ++i) {
        int val; cin >> val;
        ++cnt[val];
    }
    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + cnt[i];
    vector<int>res(n + 5, 0);
    for (int i = 1; i <= n; ++i) {
        int l = 0, r = i - 1, mid, ans = 0;
        while(l <= r) {
            mid = (l + r) / 2;
            int num = pre[mid];
            for (int j = i; j <= n; j += i) {
                num += pre[min(n, j + mid)] - pre[j - 1];
            }
            if (num < (n + 2) / 2) l = mid + 1;
            else r = mid - 1, ans = mid;
        }
        res[i] = ans;
    }
    while(q--) {
        int x; cin >> x;
        cout << res[x] << ' ';
    }
    cout << endl;
}

int32_t main(){
    faster();
    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}

