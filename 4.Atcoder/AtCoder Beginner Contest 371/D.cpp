#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void sol() {
    int n, q;
    cin >> n;
    vector<int>tmp(n + 5);
    for (int i = 1; i <= n; ++i) cin >> tmp[i];
    vector<pair<int, int>>pv(n + 5);
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        pv[i] = {tmp[i], a};
    }
    sort(pv.begin() + 1, pv.begin() + n + 1);

    vector<int>pre(n + 5, 0);
    for(int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + pv[i].second;
    }
    cin >> q;
    while(q--) {
        int l, r, res = 0; cin >> l >> r;
        pair<int, int>val1 = {l, 0}, val2 = {r + 1, 0};
        auto ind1 = lower_bound(pv.begin() + 1, pv.begin() + n + 1, val1) - pv.begin();
        auto ind2 = lower_bound(pv.begin() + 1, pv.begin() + n + 1, val2) - pv.begin();
        if (ind1 <= ind2 - 1) res = pre[ind2 - 1] - pre[ind1 - 1];
        cout << res << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    sol();
    return 0;
}


