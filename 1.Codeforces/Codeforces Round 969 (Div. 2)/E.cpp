#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int N = 2e5;
int n, w;
vector<int>tree[N + 5], vis, cnt(N + 5), dis(N + 5), up(N + 5);

void count_node(int node) {
    vis[node] = 1;
    int val = node;
    for (auto x : tree[node]) {
        if (vis[x] == 0) {
            up[x] = up[node] + 1;
            count_node(x);
            val = max(val, cnt[x]);
        }
    }
    cnt[node] = val;
}

void find_distance(int node, int par) {
    vis[node] = 1;
    int tmp = cnt[node];
    if (dis[tmp] == -1) {
        dis[tmp] = max(1ll, up[tmp] + up[tmp + 1] - 2 * up[par]);
    }
    for (auto x : tree[node]) {
        if (vis[x] == 0) {
            find_distance(x, node);
        }
    }
}


void sol() {
    cin >> n >> w;
    vis.assign(n + 5, 0);
    for (int i = 1; i <= n; ++i) tree[i].clear(),dis[i] = -1;
    vector<int>v(n + 5);
    for (int i = 2; i <= n; ++i) {
        cin >> v[i];
        tree[v[i]].push_back(i);
        tree[i].push_back(v[i]);
    }
    up[0] = up[1] = up[n + 1] = 0;
    count_node(1);

    vis.assign(n + 5, 0);
    find_distance(1, 0);
    for (int i = 1; i <= n; ++i) dis[i] = max(dis[i], 1ll);

    int tot = n, sum = 0;
    vector<int>res;
    for (int i = 2; i <= n; ++i) {
        int node, wei;
        cin >> node >> wei;
        sum += wei;;
        int a = v[node], b = node;
        --dis[cnt[b]];
        --dis[b - 1];
        if (dis[cnt[b]] <= 0) --tot;
        if (dis[b - 1] <= 0) --tot;
        int tmp = sum * 2 + (max(0ll, tot) * max(0ll, (w - sum))); res.push_back(tmp);
    }
    for (auto x : res) cout << x << ' '; cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}

