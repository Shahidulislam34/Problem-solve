///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5, 0);
    for (int i = 1; i <= n - 1; ++i) cin >> v[i];
    vector<int>res(n + 5);
    for (int i = 1; i <= n; ++i) {
        res[i] = v[i - 1] | v[i];
    }
    for (int i = 1; i <= n - 1; ++i) {
        if ((res[i] & res[i + 1]) != v[i]) {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 1; i <= n; ++i) cout << res[i] << ' '; cout << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}








