///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int two[2000 + 5][2000 + 5];
void sol(){
    int n;
    cin >> n;
    vector<pair<int, int>>pv;
    pv.push_back({0, 0});
    int x, y;
    for (int i = 1; i <= n; ++i) cin >> x >> y, pv.push_back({x, y});
    memset(two, 0, sizeof(two));
    for (int i = 1; i <= n; ++i) ++two[pv[i].first + 1000][pv[i].second + 1000];
    int res = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = i + 1; j <= n; ++j){
            int x1, y1;
            x1 = pv[i].first + pv[j].first;
            y1 = pv[i].second + pv[j].second;
            if ((abs(x1) % 2 == 1) || (abs(y1) % 2 == 1)) continue;
            res += two[x1 / 2 + 1000][y1 / 2 + 1000];
            if (pv[i].first * 2 == x1 && pv[i].second * 2 == y1) --res;
            if (pv[j].first * 2 == x1 && pv[j].second * 2 == y1) --res;
        }
    }
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    sol();
    return 0;
}



