///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
//#define endl '\n'
#define faster(); ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N = 2e5;
const int M = 1e9 + 7;

struct Points {
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
    vector<pair<int, int>>res;
    for (int i = 2; i <= n; ++i) {
        int a = i, b = 1;
        int x;
        while(1) {
            cout << "? " << a << ' ' << b << endl;
            cin >> x;
            if (x == a) break;
            b = x;
        }
        res.push_back({a, b});
    }
    cout << "! ";
    for (auto [x, y] : res) cout << ' ' << x << ' ' << y;
    cout << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}




