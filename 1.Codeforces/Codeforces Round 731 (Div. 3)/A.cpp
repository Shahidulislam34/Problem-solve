#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
const int N = 2e5;
const int M = 1e9 + 7;

struct Point{
    int x, y, z;
};

int On(int n, int k) { return n |= (1 << k); }
int Off(int n, int k) { return n &= (LLONG_MAX ^ (1 << k)); }
int Flip(int n, int k) { return n ^= (1 << k); }
bool Check(int n, int k) { if ((n & (1 << k)) != 0) return true; else return false; }
long double Distance(Point a, Point b) {return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }
int Distance_sq(Point a, Point b) {return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y); }
int Big_mod(int base, int power, int mod){
    int res = 1;
    while (power != 0){
        if (power % 2 == 0) base = (1LL * base * base) % mod, power /= 2;
        else res = (1LL * res * base) % mod, --power;
    }
    return res;
}

void sol() {
    struct Point s, f, o;
    cin >> s.x >> s.y;
    cin >> f.x >> f.y;
    cin >> o.x >> o.y;
    vector<int>x = {s.x, f.x, o.x}, y = {s.y, f.y, o.y};
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int res = abs(s.x - f.x) + abs(s.y - f.y);
    if ((s.x == f.x && f.x == o.x && y[1] == o.y) || (s.y == f.y && f.y == o.y && x[1] == o.x)) res += 2;
    cout << res << endl;
}

int32_t main() {
    faster();
    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}

