///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, m;
    cin >> n >> m;
    int v[n + 5][m + 5];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> v[i][j];
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            int mx = INT_MIN;
            if (i - 1 > 0) mx = max(mx, v[i - 1][j]);
            if (i + 1 <= n) mx = max(mx, v[i + 1][j]);
            if (j - 1 > 0) mx = max(mx, v[i][j - 1]);
            if (j + 1 <= m) mx = max(mx, v[i][j + 1]);
            if (v[i][j] > mx) v[i][j] = mx;
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}









