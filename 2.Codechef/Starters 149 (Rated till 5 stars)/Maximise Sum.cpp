///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    int pos = 0, neg = 0, mp = INT_MAX, mn = INT_MIN, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (v[i] >= 0) pos += v[i], mp = min(mp, v[i]);
        else {
            neg += v[i];
            if (mn < v[i]) mn = v[i];
            ++cnt;
        }
    }
    int res;
    if (cnt % 2 == 0) {
        res = pos + abs(neg);
    }
    else {
        if (abs(mn) > mp) {
            res = pos + abs(neg) - 2 * mp;
        }
        else res = pos + abs(neg) + 2 * mn;
    }
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}




