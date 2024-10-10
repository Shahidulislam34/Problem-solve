#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void sol() {
    int node;
    cin >> node;
    int G[node + 5][node + 5], H[node + 5][node + 5], val[node + 5][node + 5];
    memset(G, 0, sizeof(G));
    memset(H, 0, sizeof(H));
    memset(val, 0, sizeof(val));
    int eg; cin >> eg;
    while(eg--) {
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        G[a][b] = 1;
    }

    int eh; cin >> eh;
    while(eh--) {
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        H[a][b] = 1;
    }

    for (int i = 1; i <= node; ++i)
        for (int j = i + 1; j <= node; ++j)
            cin >> val[i][j];

    vector<int>v(node + 5);
    for (int i = 1; i <= node; ++i) v[i] = i;

    int res = LLONG_MAX;
    do {
        int cnt = 0;
        for (int i = 1; i <= node; ++i) {
            for (int j = i + 1; j <= node; ++j) {
                int a = v[i], b = v[j];
                if (a > b) swap(a, b);
                if (H[i][j] != G[a][b]) cnt += val[i][j];
            }
        }
        res = min(res, cnt);
    } while(next_permutation(v.begin() +  1, v.begin() + node + 1));
    cout << res << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    sol();
    return 0;
}

