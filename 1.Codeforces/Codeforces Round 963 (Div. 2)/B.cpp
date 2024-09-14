///accepted
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
    int n;
    cin >> n;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    int odd = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; ++i) {
        if (v[i] % 2 == 1) odd = max(odd, v[i]), ++cnt1;
        else ++cnt2;
    }
    if (cnt1 == n || cnt2 == n) {
        cout << 0 << endl; return;
    }
    sort(v.begin() + 1, v.begin() + n + 1);
    int res = 0;
    for (int i = n; i >= 1; --i) {
        if (v[i] % 2 == 0 && v[i] < odd) {
            odd += v[i];
            v[i] = odd;
            ++res;
        }
    }
    int even = 0;
    for (int i = 1; i <= n; ++i) {
        if (v[i] % 2 == 0 && v[i] < odd) {
            odd += v[i];
            v[i] = odd;
            ++res;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (v[i] % 2 == 0) ++even;
    }
    if (even > 0) res += even + 1;
    cout << res << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}






