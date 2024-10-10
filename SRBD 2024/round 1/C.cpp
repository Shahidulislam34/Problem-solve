#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
vector<int>gra[N + 5], depth(20);
vector<vector<int>>par(N + 5, vector<int>(20, -1));
int level;
void dfs(int cur, int prev) {
    depth[cur] = depth[max(0, prev)] + 1;
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

void sol() {
    int n, e;
    cin >> n; e = n - 1;
    for (int i = 1; i <= n; ++i) gra[i].clear();
    while(e--) {
        int u, v;
        cin >> u >> v;
        gra[u].push_back(v);
        gra[v].push_back(u);
    }
    level = log2(n);
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= level; ++j)
            par[i][j] = -1;
    depth[0] = -1;
    dfs(1, -1); ///depth[0] = -1, depth[1] = 0
    pre_compute(n);
    int q; cin >> q;
    while(q--) {
        int uu, vv;
        cin >> uu >> vv;
        int com = lca(uu, vv);
        int dif = 0;
        if (depth[uu] >= depth[vv]) {
            dif = depth[vv] - depth[com];
            dif = dif + (depth[uu] - depth[com] - dif) / 2;
        }
        else {
            dif = depth[uu] - depth[com];
            dif = dif + (depth[vv] - depth[com] - dif + 1) / 2;
        }
        int node;
        if (depth[uu] >= depth[vv]) node = uu;
        else node = vv;
        int res = node;
        for (int i = 0; i <= level; ++i) {
            if ((dif >> i) & 1)
                node = par[node][i];
        }
        cout << node << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}
