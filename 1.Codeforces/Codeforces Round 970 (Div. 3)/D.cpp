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
    string str;
    cin >> str;
    str = '0' + str;

    int vis[n + 5] = {0}, fst[n + 5] = {0}, mx[n + 5] = {0};
    int con[n + 5] = {0};
    for (int i = 1; i <= n; ++i) con[v[i]] = str[i] - '0';
//    for (int i = 1; i <= n; ++i) cout << con[i] << ' '; cout << endl;
    for (int i = 1; i <= n; ++i) {
       vector<int>tmp;
       int cnt = 0, x = v[i], ind = v[i];
       while(vis[ind] == 0) {
            if (vis[ind] == 0 && con[ind] == 0) ++cnt;
            vis[ind] = 1;
            fst[ind] = cnt;
            tmp.push_back(ind);
            ind = v[ind];
       }
       if (ind != x) cnt += mx[ind];
       for (auto x : tmp) mx[x] = cnt;
//       for (auto x : tmp) cout << x << ' '; cout << endl;
    }
//    for (int i = 1; i <= n; ++i) cout << fst[i] << ' '; cout << endl;
//    for (int i = 1; i <= n; ++i) cout << mx[i] << ' '; cout << endl;
    for (int i = 1; i <= n; ++i) {
        cout << mx[i] << ' ';
    }
    cout << endl;

}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}











