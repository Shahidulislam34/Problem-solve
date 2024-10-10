#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, k;
vector<pair<int, int>>aa;

int median(int op, int ex) {
    int l = 1, r = aa[n].first, mid, res = 0;
    while(l <= r) {
        mid = (l + r) / 2;
        int cnt = 0;
        int per = op;
        for (int i = n; i >= 1; --i) {
            if (i == ex) continue;
            if (aa[i].first >= mid) ++cnt;
            else if (aa[i].second == 1 && aa[i].first + per >= mid) ++cnt, per -= mid - aa[i].first;
        }
        if ((n + 1) / 2 <= cnt) res = mid, l = mid + 1;
        else r = mid - 1;
    }
    return res;
}

void sol(){
    cin >> n >> k;
    aa.assign(n + 5, {0, 0});
    for (int i = 1; i <= n; ++i) cin >> aa[i].first;
    for (int i = 1; i <= n; ++i) cin >> aa[i].second;
    sort(aa.begin() + 1, aa.begin() + n + 1);

    int ex = 0;
    for (int i = 1; i <= n; ++i) if (aa[i].second == 1) ex = i;
    int res = median(k, n) + aa[n].first;
    if (ex > 0) res = max(res, median(0, ex) + aa[ex].first + k);
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}




