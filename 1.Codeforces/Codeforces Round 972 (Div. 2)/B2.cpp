#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster(); ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

void sol(){
    int n, t, q;
    cin >> n >> t >> q;
    vector<int>tec(t);
    for (int i = 0; i < t; ++i) cin >> tec[i];

    sort(tec.begin(), tec.end());
    while(q--) {
        int val, res;
        cin >> val;
        auto it = lower_bound(tec.begin(), tec.end(), val);
        if (it == tec.begin()) res = (*it) - 1;
        else if (it == tec.end()) res = n - (*prev(it));
        else res = (*prev(it) + *it) / 2 - *prev(it);
        cout << res << endl;
    }
}

int32_t main(){
    faster();
    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}



