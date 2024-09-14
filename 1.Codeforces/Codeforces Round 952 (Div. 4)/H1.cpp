///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 2e5;
vector<vector<pair<int, int>>>store;
vector<vector<int>>vis;
vector<string>str;
int n, m, cnt = 0, num = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool check(int r, int c){
    if (r <= 0 || r > n || c <= 0 || c > m) return false;
    else return true;
}

void dfs1(int r, int c, int &num){
    if (str[r][c] == '.' || vis[r][c] != 0) return;
    vis[r][c] = 1;
    store[r][c].first = num;
    ++cnt;
    for (int i = 0; i < 4; ++i){
        if (check(r + dx[i], c + dy[i])) dfs1(r + dx[i] , c + dy[i], num);
    }
}

void dfs2(int r, int c){
    if (str[r][c] == '.' || vis[r][c] == 2) return;
    vis[r][c] = 2;
    store[r][c].second = cnt;
    for (int i = 0; i < 4; ++i){
        if (check(r + dx[i], c + dy[i])) dfs2(r + dx[i] , c + dy[i]);
    }
}

void sol(){
    str.clear();
    vis.clear();
    store.clear();
    cin >> n >> m;
    str.resize(n + 5);
    for (int i = 1; i <= n; ++i){
        string s; cin >> s;
        s = '0' + s;
        str[i] = s;
    }
    store.resize(n + 5);
    vis.resize(n + 5);
    for (int i = 1; i <= n; ++i) store[i].resize(m + 5, {0, 0}), vis[i].resize(m + 5, 0);

    num = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j){
            if (vis[i][j] == 0 && str[i][j] == '#'){
               dfs1(i, j, ++num);
               dfs2(i, j);
               cnt = 0;
            }
        }
    }

    int res = 0, sum = 0;
    for (int i = 1; i <= n; ++i){
        unordered_map<int, int>mp;
        sum = 0;
        for (int j = 1; j <= m; ++j){
            for (int k = 0; k < 4; ++k){
                if (check(i + dx[k], j + dy[k]) && store[i + dx[k]][j + dy[k]].first != 0 && mp[store[i + dx[k]][j + dy[k]].first] == 0)
                    sum += store[i + dx[k]][j + dy[k]].second, mp[store[i + dx[k]][j + dy[k]].first] = 1;
            }
            if (str[i][j] == '.') ++sum;
        }
        res = max(res, sum);
    }
    for (int i = 1; i <= m; ++i){
        unordered_map<int, int>mp;
        sum = 0;
        for (int j = 1; j <= n; ++j){
            for (int k = 0; k < 4; ++k){
                if (check(j + dy[k], i + dx[k]) && store[j + dy[k]][i + dx[k]].first != 0 && mp[store[j + dy[k]][i + dx[k]].first] == 0)
                    sum += store[j + dy[k]][i + dx[k]].second, mp[store[j + dy[k]][i + dx[k]].first] = 1;
            }
            if (str[j][i] == '.') ++sum;
        }
        res = max(res, sum);
    }
    cout << max(res, 1ll) << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}
