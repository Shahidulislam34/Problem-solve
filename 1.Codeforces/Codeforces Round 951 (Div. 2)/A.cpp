///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    int res = INT_MAX;
    for (int i = 1; i <= n - 1; ++i){
        int mx = max(v[i], v[i + 1]);
        res = min(res, mx - 1);
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



