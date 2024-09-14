///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 2e5;
int dp[N + 5], pre[N + 5];
void sol(){
    int l, r;
    cin >> l >> r;
    cout << pre[r] - pre[l - 1] + dp[l] << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dp[0] = 0;
    for (int i = 1; i <= 2e5; ++i) {
        dp[i] = dp[i / 3] + 1;
    }
    pre[0] = 0;
    for (int i = 1; i <= 2e5; ++i) pre[i] = pre[i - 1] + dp[i];
    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}
