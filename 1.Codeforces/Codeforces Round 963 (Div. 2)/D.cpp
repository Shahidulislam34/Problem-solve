#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define double long double
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
const int N = 2e5;
const int M = 1e9 + 7;

struct Points{
    int x, y, z;
};
int On(int n, int k){
    return n |= (1 << k);
}
int Off(int n, int k){
    return n &= (LLONG_MAX ^ (1 << k));
}
int Flip(int n, int k){
    return n ^= (1 << k);
}
bool Check(int n, int k){
    if ((n & (1 << k)) != 0) return true;
    else return false;
}
double Distance(Points a, Points b){
    return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int Distance_sq(Points a, Points b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int Big_mod(int base, int power, int mod){
    int res = 1;
    while (power != 0)
    {
        if (power % 2 == 0) base = (1LL * base * base) % mod, power /= 2;
        else res = (1LL * res * base) % mod, --power;
    }
    return res;
}

void sol(){
    int n, k;
    cin >> n >> k;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    if (n <= k) {
        int l = 1, r = 1e9, m, res = 1;
        while(l <= r) {
            m = (l + r) / 2;
            int cnt = 0;
            for (int i = 1; i <= n; ++i) if (v[i] >= m) ++cnt;
            if (cnt > n / 2) res = m, l = m + 1;
            else r = m - 1;
        }
        cout << res << endl;
    }
    else {
        int l = 1, r = 1e9, m, res = 1, x = n % k;
        if (x == 0) x = k;
        while(l <= r) {
            m = (l + r) / 2;
            int vis[n + 5] = {0}, dp[n + 5] = {0};
            for (int i = 1; i <= n; ++i) {
                if (v[i] >= m) vis[i] = 1;
                else vis[i] = 0;
            }
            for (int i = 1; i <= k; ++i) dp[i] = dp[i - 1] + vis[i];
            for (int i = k + 1; i <= n; ++i) {
                if (i % k == 1) {
                    dp[i] = max(dp[i - k], vis[i]);
                }
                else dp[i] = max(dp[i - 1] + vis[i], dp[i - k]);
            }
            if (dp[n] > x / 2) res = m, l = m + 1;
            else r = m - 1;
        }
        cout << res << endl;
    }
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}






