#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
const int N = 2e5;
const int M = 1e9 + 7;

void sol(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<set<int>>row(n + 5), col(m + 5);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    auto rem = [&](int i, int j) {
        row[i].erase(j);
        col[j].erase(i);
    };

    while(q--) {
        int r, c;
        cin >> r >> c;

        if (row[r].count(c) == 1 && col[c].count(r) == 1) {
            row[r].erase(c);
            col[c].erase(r);
            continue;
        }

        if (row[r].lower_bound(c) != row[r].end()) {
            rem(r, *row[r].lower_bound(c));
        }
        if (row[r].lower_bound(c) != row[r].begin()) {
            rem(r, *prev(row[r].lower_bound(c)));
        }
        if (col[c].lower_bound(r) != col[c].end()) {
            rem(*col[c].lower_bound(r), c);
        }
        if (col[c].lower_bound(r) != col[c].begin()) {
            rem(*prev(col[c].lower_bound(r)), c);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res += (int)row[i].size();
    }
    cout << res << endl;

}

int32_t main(){
    sol();
    return 0;
}

