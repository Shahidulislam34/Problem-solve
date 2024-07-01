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
    vector<int>tmp;
    int mx = v[1];
    for (int i = 2; i <= n; ++i){
        if (v[i] >= mx) mx = v[i];
        else tmp.push_back(mx - v[i]);
    }
    sort(tmp.begin(), tmp.end());
    int res = 0, sum = 0;
    n = tmp.size();
    for (int i = 0; i < n; ++i){
        if (tmp[i] - sum > 0){
            res += (n - i + 1) * (tmp[i] - sum);
            sum += (tmp[i] - sum);
        }
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
