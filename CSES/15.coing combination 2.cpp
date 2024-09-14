#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define _ << " " <<
const int M = 1000000007;
vector<int>coin(100 + 5);
int dp[100 + 1][1000000 + 1], n, sz;
int ways(int ind, int rem){
    if (ind > sz || rem < 0) return 0;
    if (dp[ind][rem] != -1) return dp[ind][rem];
    dp[ind][rem] = ways(ind + 1, rem) + ways(ind, rem - coin[ind]);
    dp[ind][rem] %= M;
    return dp[ind][rem];
}

void sol(){
    cin >> sz >> n;
    for (int i = 1; i <= sz; ++i) cin >> coin[i];
    sort(coin.begin() + 1, coin.begin() + sz + 1);
    for (int i = 0; i <= sz; ++i){
        for (int j = 0; j <= n; ++j)
            dp[i][j] = -1;
    }
    for (int i = 1; i <= sz; ++i) dp[i][0] = 1;
    cout << ways(1, n) << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    sol();
    return 0;
}




