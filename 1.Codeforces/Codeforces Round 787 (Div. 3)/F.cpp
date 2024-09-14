///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 2e5;
vector<int>vis(N + 5), go(N + 5), col(N + 5);
vector<int>gra[N + 5];
int mov, res, n, k, x, y;

void dfs1(int par) {
    vis[par] = 1;
    if (go[par] == 1) col[par] = 1;
    for (auto chi : gra[par]) {
        if (vis[chi] == 0) {
            dfs1(chi);
            col[par] |= col[chi];
            if (col[chi] == 1) mov += 2;
        }
    }
}

int go_to_y(int par, int val) {
    if (par == y) return val;
    vis[par] = 1;
    int sum = 0;
    for (auto chi : gra[par]) {
        if (vis[chi] == 0) {
            if (col[chi] == 1) sum += go_to_y(chi, val - 1);
            else sum += go_to_y(chi, val + 1);
        }
    }
    return sum;
}


void sol(){
    cin >> n >> k;
    cin >> x >> y;
    for (int i = 1; i <= n; ++i) vis[i] = col[i] = go[i] = 0, gra[i].clear();
    for (int i = 1; i <= k; ++i) {
        int a; cin >> a;
        go[a] = 1;
    }
    for (int i = 1; i <= n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        gra[a].push_back(b);
        gra[b].push_back(a);
    }
    mov = 0;
    dfs1(x);
    for (int i = 1; i <= n; ++i) vis[i] = 0;
    res = go_to_y(x, 0);
    cout << max(0ll, mov + res) << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}



