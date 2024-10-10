#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

const int N = 1e5;
vector<int>gra[N + 5], depth(N + 5);
vector<vector<int>>par;
int level;
vector<int>tmp(N + 5), res(N + 5);
map<pair<int, int>, int>mp;

void dfs(int cur, int prev) {
    depth[cur] = depth[max(0ll, prev)] + 1;
    par[cur][0] = prev;
    for (auto chi : gra[cur]) {
        if (chi != prev)
            dfs(chi, cur);
    }
}

void pre_compute(int n) {
    for (int i = 1; i <= level; ++i) {
        for (int node = 1; node <= n; ++node) {
            if (par[node][i - 1] != -1)
                par[node][i] = par[par[node][i - 1]][i - 1];
        }
    }
}

int lca(int uu, int vv) {
    if (depth[uu] < depth[vv]) swap(uu, vv);
    int dif = depth[uu] - depth[vv];
    for (int i = 0; i <= level; ++i) {
        if ((dif >> i) & 1)
            uu = par[uu][i];
    }
    if (uu == vv) return uu;
    for (int i = level; i >= 0; --i) {
        if (par[uu][i] != par[vv][i]) {
            uu = par[uu][i];
            vv = par[vv][i];
        }
    }
    return par[uu][0];
}

void init(int n) {
    level = log2(n);
    par.assign(n + 5, vector<int>(level + 5, -1));
    depth[0] = -1;
    dfs(1, -1);
    pre_compute(n);
}

int dfs2(int cur, int prev) {
    int sum = tmp[cur];
    for (auto chi : gra[cur]) {
        if (chi != prev)
            sum += dfs2(chi, cur);
    }
    if (cur > prev) swap(cur, prev);
    return res[mp[{cur, prev}]] = sum;
}

void sol(){
    int n, e;
    cin >> n; e = n - 1;
    for (int i = 1; i <= n; ++i) gra[i].clear(), tmp[i] = 0;
    for (int i = 1; i <= e; ++i) {
        int uu, vv;
        cin >> uu >> vv;
        if (uu > vv) swap(uu, vv);
        mp[{uu, vv}] = i;
        gra[uu].push_back(vv);
        gra[vv].push_back(uu);
    }
    init(n);
    int q; cin >> q;
    while(q--) {
        int uu, vv;
        cin >> uu >> vv;
        ++tmp[uu];
        ++tmp[vv];
        int com = lca(uu, vv);
        tmp[com] -= 2;
    }
    dfs2(1, -1);
    for (int i = 1; i <= n - 1; ++i) cout << res[i] << ' '; cout << endl;
}

int32_t main(){
    faster();
    sol();
    return 0;
}


