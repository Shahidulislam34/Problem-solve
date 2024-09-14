#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define faster(); ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N = 2e5;
vector<int>tree[N + 5], val(N + 5);
vector<bool>vis(N + 5);
int n;

int dfs(int node) {
    vis[node] = true;
    int mn = INT_MAX;
    for (auto x : tree[node]) {
        if (vis[x] == false) {
            mn = min(mn, dfs(x));
        }
    }
    if (mn == INT_MAX) mn = val[node];
    else if (node == 1) return val[node] + mn;
    else if(mn >= val[node]) mn = (mn + val[node]) / 2;
    return mn;
}

void sol(){
    cin >> n;
    for (int i = 1; i <= n; ++i) tree[i].clear(), vis[i] = false;
    for (int i = 1; i <= n; ++i) cin >> val[i];
    for (int i = 2; i <= n; ++i) {
        int node; cin >> node;
        tree[node].push_back(i);
        tree[i].push_back(node);
    }
    int res = dfs(1);
    cout << res << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}





