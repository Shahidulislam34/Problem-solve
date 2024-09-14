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
        if (power % 2 == 0) base = (1LL * base * base) % mod, power /= 2;
        else res = (1LL * res * base) % mod, --power;
    }
    return res;
}

void sol(){
    int n, m, q;
    cin >> n >> m >> q;
    int cd = __gcd(n, m), in = n / cd, out = m / cd;
    while(q--) {
        int c1, num1, c2, num2;
        cin >> c1 >> num1 >> c2 >> num2;
        int no1, no2;
        if (c1 == 1) no1 = ceil((long double) num1 / in);
        else no1 = ceil((long double) num1 / out);

        if (c2 == 1) no2 = ceil((long double) num2 / in);
        else no2 = ceil((long double) num2 / out);

        if (no1 == no2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int32_t main(){
    faster();
    sol();
    return 0;
}









