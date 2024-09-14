#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 3e5;
vector<int>gra[N + 5], vis(N + 5), col(N + 5);

void dfs(int par, int val) {
    vis[par] = 1;
    col[par] = val;
    for (auto chi : gra[par]) {
        if (vis[chi] == 0) {
            dfs(chi, val ^ 1);
        }
    }
}

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i], vis[i] = col[i] = 0, gra[i].clear();
    int e = n - 1;
    while(e--) {
        int a, b;
        cin >> a >> b;
        gra[a].push_back(b);
        gra[b].push_back(a);
    }
    dfs(1, 0);
    int sum = 0, one = 0, zero = 0;
    for (int i = 1; i <= n; ++i) {
        sum += v[i];
        if (col[i] == 1) one += v[i];
        else zero += v[i];
    }
    cout << sum + min(one, zero) << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}
