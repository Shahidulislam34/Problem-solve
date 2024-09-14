#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
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
        if (power % 2 == 0) base = ((base % mod) * (base % mod)) % mod, power /= 2;
        else res = ((res % mod) * (base % mod)) % mod, --power;
    }
    return res;
}

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    vector<int>pre(n + 5, 0);
    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + v[i];

    int sum = 0;
    for (int i = 1; i <= n - 1; ++i) {
        int tmp = ((v[i] % M ) * ((pre[n] - pre[i]) % M)) % M;
        sum = ((sum % M)+ (tmp % M)) % M;
    }
    int B1 = (n * (n - 1)) / 2;
    int val = Big_mod(B1, M - 2, M) % M;
    int res = ((sum % M) * (val % M) ) % M;
    cout << res << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}

