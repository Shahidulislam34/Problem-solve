///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    vector<int>a(n + 5), p(n + 5), mex(n, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int mx = 0;
    for (int i = 1; i <= n; ++i){
        if (a[i] < 0) p[i] = mx - a[i];
        else p[i] = mx;
        mex[p[i]] = 1;
        for (int j = mx; j < n; ++j) {
            if (mex[j] == 0) {
                mx = j;
                break;
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << p[i] << ' '; cout << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}











