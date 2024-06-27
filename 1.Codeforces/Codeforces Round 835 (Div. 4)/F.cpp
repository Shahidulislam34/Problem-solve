///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, c, d;
    cin >> n >> c >> d;
    vector<int>v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.rbegin(), v.rend());
    v.insert(v.begin(), 0);

    vector<int>pre(n + 5, 0);
    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + v[i];
    if (v[1] * d < c){
        cout << "Impossible" << endl;
        return;
    }
    if (v[1] >= c){
        cout << "Infinity" << endl;
        return;
    }
    int res = 0, l = 1, r = 1e12, mid, tmp = r;
    while(l <= r){
        mid = (l + r) / 2;
        int mn = min(n, mid + 1);
        int sum = (d / (mid + 1)) * pre[mn];
        mn = d % (mid + 1);
        mn = min(n, mn);
        sum += pre[mn];
        if (sum >= c) res = mid, l = mid + 1;
        else r = mid - 1;
    }
    if (tmp == res){
        cout << "Infinity" << endl;
        return;
    }
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}





