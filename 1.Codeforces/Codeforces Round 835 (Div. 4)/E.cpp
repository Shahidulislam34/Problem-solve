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

    int res = 0, sum = 0, one = 0;
    for (int i = 1; i <= n; ++i){
        if (v[i] == 1) ++one;
        else sum += one;
    }
    vector<int>pre(n + 5, 0), suf(n + 5, 0);
    for (int i = 1; i <= n; ++i){
        if (v[i] == 0)pre[i] = 1;
        pre[i] += pre[i - 1];
    }
    for (int i = n; i >= 1; --i){
        if (v[i] == 0) suf[i] = 1;
        suf[i] += suf[i + 1];
    }
    res = sum;
//    cout << "SUM:" << sum << endl;
//    for (int i = 1; i <= n; ++i) cout << pre[i] << ' '; cout << endl;
//    for (int i = 1; i <= n; ++i) cout << suf[i] << ' '; cout << endl;
    for (int i = 1; i <= n; ++i){
        if (v[i] == 1){
            res = max(res, sum + (i - 1 - pre[i - 1]) - suf[i + 1]);
        }
        else {
            res = max(res, sum - (i - 1 - pre[i - 1]) + suf[i + 1]);
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




