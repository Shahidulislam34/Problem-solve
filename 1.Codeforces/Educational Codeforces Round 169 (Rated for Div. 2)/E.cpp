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

int gru[10000001];
bool vis[10000001];
void sieve() {
    int n = 1e7;
    memset(gru, -1, sizeof(gru));
    gru[0] = 0;
    gru[1] = 1;
    gru[2] = 0;
    int inc = 1;
    for (int i = 2; i * i <= n; ++i) {
        if (vis[i] == 0) {
            if (i % 2 == 1) ++inc, gru[i] = inc, vis[i] = 1;
            for (int j = i + i; j <= n; j += i) {
                vis[j] = 1;
                if (gru[j] == -1) gru[j] = gru[i];
            }
        }
    }
    int mx = 0;
    for (int i = 1; i <= 1e7; ++i) {
        if (gru[i] == -1) ++mx, gru[i] = mx;
        else mx = max(mx, gru[i]);
    }
}

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    int xr = 0;
    for (int i = 1; i <= n; ++i) xr ^= gru[v[i]];
    if (xr > 0) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}

int32_t main(){
    faster();
    sieve();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}







