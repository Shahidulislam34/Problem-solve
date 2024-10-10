#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
const int N = 100, M = (int)1e8;
int dp[N + 1][N + 1][10 + 1][10 + 1], n1, n2, k1, k2;

int DP(int r1, int r2, int b1, int b2, int ind) {
    if (ind > n1 + n2) return 1;
    if (dp[r1][r2][b1][b2] != -1) return dp[r1][r2][b1][b2];

    int sum = 0;
    if (b1 < k1 && r1 > 0) sum += DP(r1 - 1, r2, b1 + 1, 0, ind + 1) % M;
    if (b2 < k2 && r2 > 0) sum += DP(r1, r2 - 1, 0, b2 + 1, ind + 1) % M;
    return dp[r1][r2][b1][b2] = sum % M;
}

void sol(){
    cin >> n1 >> n2 >> k1 >> k2;
    for (int i = 0; i <= n1; ++i)
        for (int j = 0; j <= n2; ++j)
            for (int k = 0; k <= 10; ++k)
                for (int l = 0; l <= 10; ++l)
                    dp[i][j][k][l] = -1;
    int res = DP(n1, n2, 0, 0, 1) % M;
    cout << res << endl;
}

int32_t main(){
    faster();
    sol();
    return 0;
}









