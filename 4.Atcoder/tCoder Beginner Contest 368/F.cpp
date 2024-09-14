#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define double long double
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
int N = 1e5;
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

vector<int>factor(N + 5), gru(N + 5);

void prime_factor() {
    for (int i = 1; i <= N; ++i) factor[i] = i;
    vector<bool>vis(N + 5, false);
    for (int i = 2; i<= N; ++i) {
        if (vis[i] == false) {
            for (int j = i * i; j <= N; j += i) {
                factor[j] = min(factor[j], i);
                vis[j] = true;
            }
        }
    }
}

void grundy() {
    for (int i = 1; i <= N; ++i) {
        int cnt = 0, val = i;
        while(val != 1) {
            ++cnt;
            val /= factor[val];
        }
        gru[i] = cnt;
    }
}


void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    N = *max_element(v.begin() + 1, v.begin() + n + 1);
    prime_factor();
    grundy();

    int xr = 0;
    for (int i = 1; i <= n; ++i) xr ^= gru[v[i]];
    if (xr > 0) cout << "Anna" << endl;
    else cout << "Bruno" << endl;
}

int32_t main(){
    faster();
    sol();
    return 0;
}






