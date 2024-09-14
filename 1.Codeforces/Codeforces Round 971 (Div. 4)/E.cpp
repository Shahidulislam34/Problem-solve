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
    int n, k;
    cin >> n >> k;
    int l = k, r = n + k - 1, m, res = INT_MAX, x = n + k - 1;
    while(l <= r) {
        m = (l + r) / 2;
        int a = ((m * (m + 1)) / 2) - ((k * (k - 1)) / 2);
        int b = ((x * (x + 1)) / 2) - ((m * (m + 1)) / 2);
        if (a <= b) l = m + 1, res = min(res, abs(b - a));
        else r = m - 1, res = min(res, abs(a - b));
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





