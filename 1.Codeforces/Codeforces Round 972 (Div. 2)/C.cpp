#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster(); ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N = 3000;
int n, m;
vector<string>v(N + 5);
int dp[N + 5][10];
string ss = "narek";

int recur(int ind, int chp) {
    if (ind > n) return -chp;
    if (dp[ind][chp] != INT_MIN) return dp[ind][chp];

    int val1 = recur(ind + 1, chp);
    int cgpt = 0, nar = 0, tmp = chp;
    for (int i = 1; i <= m; ++i) {
        if (ss[chp] == v[ind][i]) ++chp;
        else if (ss.find(v[ind][i]) != string::npos) ++cgpt;
        if (chp == 5) ++nar;
        chp %= 5;
    }
    int val2 = recur(ind + 1, chp) + nar * 5 - cgpt;
    return dp[ind][tmp] = max(val1, val2);

}

void sol(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        string str; cin >> str; str = '0' + str;
        v[i] = str;
    }
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= 5; ++j) dp[i][j] = INT_MIN;
    int res = recur(1, 0);
    cout << res << endl;
}

int32_t main(){
    faster();
    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}




