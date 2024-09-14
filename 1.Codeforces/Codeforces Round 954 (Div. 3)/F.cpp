///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e5;
vector<int>gra[N + 5], dis(N + 5), low(N + 5), tot(N + 5);
bool vis[N + 5];
int timer = 0, res = 0, n, e;

void dfs(int par, int anc){
    vis[par] = 1;
    dis[par] = low[par] = ++timer;
    tot[par] = 1;
    for (auto chi : gra[par]){
        if (chi != anc){
            if (vis[chi] == 0) dfs(chi, par), tot[par] += tot[chi];
            low[par] = min(low[par], low[chi]);
        }
    }
    if (dis[par] <= low[par]) res = max(res, tot[par] * (n - tot[par]));
}

void sol(){
    cin >> n >> e;
    for (int i = 1; i <= n; ++i) gra[i].clear(), dis[i] = low[i] = tot[i] = vis[i] = 0;
    while(e--){
        int a, b;
        cin >> a >> b;
        gra[a].push_back(b);
        gra[b].push_back(a);
    }
    res = timer = 0;
    dfs(1, 0);
    res = (n * (n - 1)) / 2 - res;
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}




