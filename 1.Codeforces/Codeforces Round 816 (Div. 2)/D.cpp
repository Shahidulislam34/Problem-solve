#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, q;
    cin >> n >> q;

    int a, b, c;
    vector<bitset<30>>bs(n + 5, bitset<30>(0));
    vector<pair<int, int>>graph[n + 5];
    for (int i = 1; i <= q; ++i) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    for (int i = 1; i <= n; ++i){
        bitset<30>tmp;
        tmp.set();
        int ok = 0;
        for (auto [x, y] : graph[i]){
            ok = 1;
            for (int j = 0; j < 30; ++j)
                tmp[j] = tmp[j] & ((y >> j) & 1);
        }
        if (ok) bs[i] = tmp;
    }

    vector<bitset<30>>res(n + 5, bitset<30>(0));
    for (int i = 1; i <= n; ++i){
        vector<int>ind(30, i);
        int ok = 0;
        for (auto [x, y] : graph[i]){
            for (int j = 0; j < 30; ++j) {
                if (bs[i][j] == 1 && bs[x][j] == 1 && (res[x][j] == 1 || ind[j] < x)){
                    ind[j] = x;
                }
            }
        }
        for (int k = 0; k < 30; ++k) if (bs[i][k] == 1) res[ind[k]][k] = 1;
    }
    for (int i = 1; i <= n; ++i) cout << res[i].to_ullong() << ' '; cout << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    sol();
    return 0;
}

