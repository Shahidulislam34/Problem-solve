#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

const int N = 1e5;
vector<pair<int, int>>gra[N + 5];
vector<int>depth(N + 5);
int level;
struct node {
    int anc, mx, mn;
}par[N + 5][20];

void dfs(int cur, int prev, int w) {
    depth[cur] = depth[max(0ll, prev)] + 1;
    par[cur][0].anc = prev;
    par[cur][0].mx = w;
    par[cur][0].mn = w;
    for (auto [chi, wei] : gra[cur]) {
        if (chi != prev)
            dfs(chi, cur, wei);
    }
}

void pre_compute(int n) {
    for (int i = 1; i <= level; ++i) {
        for (int node = 1; node <= n; ++node) {
            if (par[node][i - 1].anc != -1) {
                par[node][i].mx = max(par[node][i - 1].mx, par[par[node][i - 1].anc][i - 1].mx);
                par[node][i].mn = min(par[node][i - 1].mn, par[par[node][i - 1].anc][i - 1].mn);
                par[node][i].anc = par[par[node][i - 1].anc][i - 1].anc;
            }
        }
    }
}

pair<int, int> lca(int uu, int vv) {
    if (depth[uu] < depth[vv]) swap(uu, vv);
    int dif = depth[uu] - depth[vv];
    node res;
    res.anc = uu;
    res.mx = INT_MIN;
    res.mn = INT_MAX;
    for (int i = 0; i <= level; ++i)
    if ((dif >> i) & 1) {
        res.mx = max(par[res.anc][i].mx, res.mx);
        res.mn = min(par[res.anc][i].mn, res.mn);
        res.anc = par[res.anc][i].anc;
    }
    if (res.anc == vv)
        return {res.mn, res.mx};
    for (int i = level; i >= 0; --i) {
        if (par[res.anc][i].anc != par[vv][i].anc) {
            res.mx = max({res.mx, par[res.anc][i].mx, par[vv][i].mx});
            res.mn = min({res.mn, par[res.anc][i].mn, par[vv][i].mn});
            res.anc = par[res.anc][i].anc;
            vv = par[vv][i].anc;
        }
    }
    res.mx = max({res.mx, par[res.anc][0].mx, par[vv][0].mx});
    res.mn = min({res.mn, par[res.anc][0].mn, par[vv][0].mn});
    return {res.mn, res.mx};
}

void sol(){
    int n, e;
    cin >> n; e = n - 1;
    for (int i = 1; i <= n; ++i) gra[i].clear();
    while(e--) {
        int uu, vv, ww;
        cin >> uu >> vv >> ww;
        gra[uu].emplace_back(vv, ww);
        gra[vv].emplace_back(uu, ww);
    }
    level = log2(n);
    for (int i = 0; i <= level; ++i)
        for (int node = 1; node <= n; ++node)
            par[node][i].anc = -1, par[node][i].mx = INT_MIN, par[node][i].mn = INT_MAX;
    depth[0] = -1;
    dfs(1, -1, -1);
    pre_compute(n);

    int q; cin >> q;
    while(q--) {
        int uu, vv;
        cin >> uu >> vv;
        auto [soto, boro] = lca(uu, vv);
        cout << soto << ' ' << boro << endl;
    }
}

int32_t main(){
    faster();
    sol();
    return 0;
}

