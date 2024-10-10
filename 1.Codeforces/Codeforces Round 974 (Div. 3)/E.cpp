#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

const int N = 2e5;
int n, e, h;
vector<pair<int, int>>gra[N + 1];
vector<vector<int>>res1(N + 1, vector<int>(2)), resn(N + 1, vector<int>(2));
vector<int>hor(N + 1, 0);

void pre_cal(vector<vector<int>>&tmp, int ind) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;
    pq.push({0, ind, hor[ind]});
    tmp[ind][hor[ind]] = 0;

    while(!pq.empty()) {
        auto [aa, bb, cc] = pq.top();
        pq.pop();
        if (aa > tmp[bb][cc]) continue;
        for (auto [v, w] : gra[bb]) {
            int lag, hh = cc | hor[bb];
            hh ? lag = w / 2 : lag = w;
            if (aa + lag < tmp[v][hh]) tmp[v][hh] = aa + lag, pq.push({aa + lag, v, hh});
        }
    }
}

void sol(){
    cin >> n >> e >> h;
    for (int i = 1; i <= n; ++i) gra[i].clear(), hor[i] = 0;
    for (int i = 1; i <= n; ++i) res1[i][0] = res1[i][1] = resn[i][0] = resn[i][1] = 1e18;
    for (int i = 1; i <= h; ++i) {
        int val; cin >> val;
        hor[val] = 1;
    }
    while(e--) {
        int aa, bb, ww;
        cin >> aa >> bb >> ww;
        gra[aa].emplace_back(bb, ww);
        gra[bb].emplace_back(aa, ww);
    }
    pre_cal(res1, 1);
    pre_cal(resn, n);
    int ans = 1e18;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, max(min(res1[i][0], res1[i][1]), min(resn[i][0], resn[i][1])));
    }
    ans == (int)1e18 ? ans = -1 : ans = ans;
    cout << ans << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}


