#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void sol(){
    int n, q;
    cin >> n >> q;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i)
        cin >> v[i];

    int cnt[4][n + 5];
    memset(cnt, 0, sizeof(cnt));

    for (int i = 1; i <= n; ++i) {
        cnt[v[i]][i] = 1;
        cnt[1][i] += cnt[1][i - 1];
        cnt[2][i] += cnt[2][i - 1];
        cnt[3][i] += cnt[3][i - 1];
    }

    while(q--) {
        int l, r; cin >> l >> r;
        if ((r - l) % 2 == 0) {
            cout << "No" << endl;
            continue;
        }

        int one = cnt[1][r] - cnt[1][l - 1];
        int two = cnt[2][r] - cnt[2][l - 1];
        int three = cnt[3][r] - cnt[3][l - 1];

        int mx = max({one, two, three});
        int mn = one + two + three - mx;
        if (mn != mx) cout << "No" << endl;
        else cout << "Yes" << endl;
    }

}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}






