#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int N = 300;
int n, row, col;
vector<int>v;
vector<pair<int, int>>pos[8];
int dp[N][N][N];
map<int, int>mp;

bool recur(int nn, int rr, int cc) {
    if (nn >= n) return true;
    if (rr >= 0 && cc >= 0 && dp[nn][rr][cc] != -1) return dp[nn][rr][cc];
    int ind = mp[v[nn]];
    bool check = true;
    for (int i = ind; i< pos[v[nn]].size(); ++i) {
        int x = pos[v[nn]][i].first, y = pos[v[nn]][i].second;
        if (x > rr && y > cc) {
            mp[v[nn]] = i + 1;
            if(recur(nn + 1, x, y)) {
                check = false;
                break;
            }
        }
    }
    mp[v[nn]] = ind;
    if (nn == 0) return check;
    return dp[nn][rr][cc] = check;
}

void sol() {
    cin >> n >> row >> col;
    v.assign(n, 0);
    for (int i = 0; i <= 7; ++i) pos[i].clear();

    for (int i = 0; i < n; ++i) cin >> v[i];
    int val;
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            cin>> val, pos[val].push_back({i, j});
    for (int i = 1; i <= 7; ++i) sort(pos[i].begin(), pos[i].end()), mp[i] = 0;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < row; ++j)
            for (int k = 0; k < col; ++k)
                dp[i][j][k] = -1;
    bool res = recur(0, -1, -1);
    if (res == true) cout << "N" << endl;
    else cout << "T" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}
