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
    int sum = 0;
    for (int i = 1; i <= n; ++i) if(v[i] >= 0) sum += v[i];
    if (sum == 0) {
        cout << 0 << endl;
        return;
    }
    int res = 0, mx = 0;
    set<int>ss;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int val = 0, cnt = 0;
            for (int k = i; k <= j; ++k) {
                if (v[k] >= 0) val += v[k];
                else ++cnt;
            }
            if (mx < val) mx = val, res = cnt;
            else if (mx == val) res = min(res, cnt);
        }
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




