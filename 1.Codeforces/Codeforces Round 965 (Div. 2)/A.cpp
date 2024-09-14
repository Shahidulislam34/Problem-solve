///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int x, y, k;
    cin >> x >> y >> k;

    int inc = 200000;
    vector<pair<int, int>>res(k + 5);
    int sz;
    if ((k % 2) == 1) sz = k - 1;
    else sz = k - 2;
    for (int i = 2; i <= sz; i += 2) {
        res[i - 1].first = inc;
        res[i].first = -1 * inc;
        ++inc;
    }
    for (int i = 2; i <= sz; i += 2) {
        res[i - 1].second = inc;
        res[i].second = -1 * inc;
        ++inc;
    }
    if ((k % 2) == 1) {
        res[k].first = k * x;
        res[k].second = k * y;
    }
    else {
        res[k - 1] = {0, 0};
        res[k] = {k * x, k * y};
        if (x == 0 && y == 0) {
            res[k - 1].first = inc;
            res[k].first = -1 * inc;
            ++inc;
            res[k - 1].second = inc;
            res[k].second = -1 * inc;
        }
    }
    for (int i = 1; i <= k; ++i) cout << res[i].first << ' ' << res[i].second << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}



