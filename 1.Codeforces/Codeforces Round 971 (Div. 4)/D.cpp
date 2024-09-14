#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ld long double
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
    int n;
    cin >> n;
    int vis[n + 5][2 + 5];
    memset(vis, 0, sizeof(vis));
    int pre[n + 5][2 + 5];
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        vis[x][y] = 1;
    }
    pre[0][0] = vis[0][0];
    pre[0][1] = vis[0][1];
    for (int i = 1; i <= n; ++i) {
        pre[i][0] = pre[i - 1][0] + vis[i][0];
        pre[i][1] = pre[i - 1][1] + vis[i][1];
    }

    int res = 0;
    for (int i = 0; i <= n; ++i) {
        if (vis[i][0] == 1 && vis[i][1] == 1) {
            if (i > 0) {
                res += pre[i - 1][0];
                res += pre[i - 1][1];
            }
            if (i < n) {
                res += (pre[n][0] - pre[i][0]);
                res += (pre[n][1] - pre[i][1]);
            }
        }
        if (i > 0 && i < n && vis[i][0] == 1 && vis[i - 1][1] == 1 && vis[i + 1][1] == 1) res += 1;
        if (i > 0 && i < n && vis[i][1] == 1 && vis[i - 1][0] == 1 && vis[i + 1][0] == 1) res += 1;
    }
    cout << res << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}




