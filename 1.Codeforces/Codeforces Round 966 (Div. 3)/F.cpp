#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define ff first
#define ss second
#define pb push_back
const int N = 2e5;
const int M = 1e9 + 7;

struct Points
{
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
long double Distance(Points a, Points b){
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
    vector<pair<int, int>>pv(n + 5);
    for (int i = 1; i <= n; ++i) {
        cin >> pv[i].ff >> pv[i].ss;
        if (pv[i].ff > pv[i].ss) swap(pv[i].ff, pv[i].ss);
    }
    int dp[n + 2][k + 2];
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        int ind = 1, sum = 0;
        while(pv[i].ss > pv[i].ff) {
            sum += pv[i].ff;
            dp[i][ind] = sum;
            ++ind;
            --pv[i].ss;
        }
        int sel = 0, m = pv[i].ff;
        while(m) {
            dp[i][ind] = sum + m;
            ++ind;
            dp[i][ind] = sum + (2 * m - 1);
            ++ind;
            sum += 2 * m - 1;
            --m;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j)
            cout << dp[i][j] << ' ';
        cout << endl;
    }
    vector<pair<int, int>>minv(k + 5);
    for (int i = 1; i <= n; ++i)

}

int32_t main(){
//    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}

