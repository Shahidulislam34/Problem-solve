#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

const int N = 2e5;
vector<int>uni(N + 1);
int vis[N + 1][10 + 1], n, m;

int find_par(int ff) {
    if (uni[ff] == ff) return ff;
    return uni[ff] = find_par(uni[ff]);
}

void update_par(int a, int b) {
    int par1 = find_par(a);
    int par2 = find_par(b);
    uni[par1] = par2;
}

void sol(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) uni[i] = i;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 10; ++j)
            vis[i][j] = 0;
    }
    while(m--) {
        int fst, inc, lst;
        cin >> fst >> inc >> lst;
        vis[fst][inc] = max(vis[fst][inc], fst + inc * lst);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 10; ++j) {
            int mx = vis[i][j], val = i;
            vis[i][j] = 0;
            while(val < mx) {
                update_par(val, val + j);
                vis[val][j] = 0;
                val += j;
                mx = max(vis[val][j], mx);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) if (find_par(i) == i) ++ans;
    cout << ans << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}



