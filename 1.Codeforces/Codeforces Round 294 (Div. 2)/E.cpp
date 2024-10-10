#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

const int N = (int)1e5;
vector<int>gra[N + 5], sub(N + 5), depth(N + 5);
vector<vector<int>>par(N + 5, vector<int>(20));
int level;

int dfs(int cur, int prev) {
    depth[cur] = depth[max(prev, 0ll)] + 1;
    par[cur][0] = prev;
    int sum = 1;
    for (auto chi : gra[cur]) {
        if (chi != prev)
            sum += dfs(chi, cur);
    }
    return sub[cur] = sum;
}

void pre_compute(int n) {
    for (int i = 1; i <=level; ++i) {
        for (int node = 1; node <= n; ++node)
            if (par[node][i - 1] != -1)
                par[node][i] = par[par[node][i - 1]][i - 1];
    }
}

int bin_raise(int uu, int up) {
    for (int i = 0; i <= level; ++i)
        if ((up >> i) & 1)
            uu = par[uu][i];
    return uu;
}

int lca(int uu, int vv) {
    if (depth[uu] < depth[vv]) swap(uu, vv);
    int up = depth[uu] - depth[vv];
    uu = bin_raise(uu, up);
    if (uu == vv) return uu;
    for (int i = level; i >= 0; --i) {
        if (par[uu][i] != par[vv][i])
        {
            uu = par[uu][i];
            vv = par[vv][i];
        }
    }
    return par[uu][0];
}

void sol(){
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
    depth[0] = -1;
    dfs(1, -1);
    pre_compute(n);

    int q; cin >> q;
    while(q--) {
        int uu, vv;
        cin >> uu >> vv;
        int com = lca(uu, vv);
        int dis = depth[uu] + depth[vv] - 2 * depth[com];
        if (dis % 2) cout << 0 << endl;
        else if (uu == vv) cout << n << endl;
        else if (depth[uu] == depth[vv]){
            int up1 = depth[uu] - depth[com] - 1;
            int up2 = depth[vv] - depth[com] - 1;
            int aa = bin_raise(uu, up1);
            int bb = bin_raise(vv, up2);
            cout << sub[1] - (sub[aa] + sub[bb]) << endl;
        }
        else {
            if (depth[uu] < depth[vv]) swap(uu, vv);
            int up1 = dis / 2;
            int up2 = (dis / 2) - 1;
            int aa = bin_raise(uu, up1);
            int bb = bin_raise(uu, up2);
            cout << (sub[aa] - sub[bb]) << endl;
        }
    }
}

int32_t main(){
    faster();
    sol();
    return 0;
}

