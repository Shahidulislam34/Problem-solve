#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int M = 998244353;

void sol(){
    int l, r;
    cin >> l >> r;
    int mx = 0, tmp = r;
    while(l <= tmp) {
        ++mx;
        if (tmp / 2 < l) break;
        tmp /= 2;
    }
    int res = (tmp - l + 1) % M;
    tmp = (tmp * 2) / 3;
    if (l <= tmp) {
        res += (((tmp - l + 1) / 2) * (mx - 1)) % M;
        if ((l + tmp) % 2 == 0) res += (mx - 1) % M;
    }
    int cnt = 0;
    tmp = 3;
    while(tmp <= r) {
        ++cnt;
        tmp *= 2;
    }
    if (l == 1 && cnt + 1 >= mx && cnt != 0) res += cnt;
    cout << mx << ' ' << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}







