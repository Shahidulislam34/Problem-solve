///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
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
    int n, m;
    cin >> n >> m;
    vector<int>v[n + 5], sz(n + 5);
    for (int i = 1; i <= n; ++i) {
        cin >> sz[i];
        int val;
        set<int>st;
        for (int j = 0; j < sz[i]; ++j) cin >> val, st.insert(val);
        v[i].assign(st.begin(), st.end());
        sz[i] = st.size();
    }
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < sz[i]; ++j) {
            if (v[i][j] - j > 1) {
                mx = max(mx, j + 1);
                break;
            }
            mx = max(mx, j + 2);
        }
    }
    int res = mx * (min(mx, m) + 1);
    if (mx < m) {
        res += ((m * (m + 1)) / 2) - ((mx * (mx + 1)) / 2);
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
