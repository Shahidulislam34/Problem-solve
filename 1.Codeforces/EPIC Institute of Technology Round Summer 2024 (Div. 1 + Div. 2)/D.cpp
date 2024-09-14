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
int dp[5001][5001], cnt[5001], n;

int rec(int ind, int alice) {
    if (ind > n) return 0;
    if (dp[ind][alice] != -1) return dp[ind][alice];
    int bob = rec(ind + 1, alice + 1);
    if (alice >= cnt[ind])
        bob = max(bob, rec(ind + 1, alice - cnt[ind]) + 1);
    return dp[ind][alice] = bob;
}

void sol(){
    cin >> n;
    map<int, int>mp;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        ++mp[a];
    }
    n = 0;
    for (auto [x, y] : mp) cnt[++n] = y;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            dp[i][j] = -1;
    cout << max(1ll, n - rec(1, 0)) << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}






