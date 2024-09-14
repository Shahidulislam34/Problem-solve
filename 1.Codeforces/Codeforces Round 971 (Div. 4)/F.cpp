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
    int n, q;
    cin >> n >> q;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    vector<int>pre(n + 5, 0);
    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + v[i];

    while(q--) {
        int l, r, x, y;
        cin >> l >> r;
        int res = 0;
        int a, b;
        a = ceil((long double)l / n);
        b = ceil((long double)r / n);
        res += max(0ll, max(0ll, b - a - 1) * pre[n]);
//        cout << "ab:" << a << ' ' << b << ' ' << res << endl;
        if (a == b) {
            x = l % n; if (x == 0) x = n;
            y = r % n; if (y == 0) y = n;
            x += (a - 1);
            y += (b - 1);
            if (x > n) x -= n;
            if (y > n) y -= n;
            if (x <= y) res += pre[y] - pre[x - 1];
            else res += pre[n] - pre[x - 1] + pre[y];
        }
        else {
            x = l % n; if (x == 0) x = n;
            y = n;
            x += (a - 1);
            y += (a - 1);
            if (x > n) x -= n;
            if (y > n) y -= n;
            if (x <= y) res += pre[y] - pre[x - 1];
            else res += pre[n] - pre[x - 1] + pre[y];
//            cout << "xy:" << x << ' ' << y << ' ' << res << endl;
            x = 1;
            y = r % n; if (y == 0) y = n;
            x += (b - 1);
            y += (b - 1);
            if (x > n) x -= n;
            if (y > n) y -= n;
            if (x <= y) res += pre[y] - pre[x - 1];
            else res += pre[n] - pre[x - 1] + pre[y];
//            cout << "xy:" << x << ' ' << y << ' ' << res << endl;
        }
        cout << res << endl;
    }
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}






