#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define double long double
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

void sol(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    int diff[n + 5];
    for (int i = 1; i <= n; ++i) diff[i] = v[i] - i;

    multiset<int>ms;
    map<int, int>mp;
    for (int i = 1; i <= k; ++i) ++mp[diff[i]];
    for (auto x : mp) ms.insert(x.second);


    int res[n + 5];
    res[1] = *ms.rbegin();
    for (int i = k + 1; i <= n; ++i) {
        if (diff[i] == diff[i - k]) {
            res[i - k + 1] = *ms.rbegin();
            continue;
        }
        if (mp[diff[i]] > 0) ms.erase(ms.find(mp[diff[i]]));
        mp[diff[i]] += 1;
        ms.insert(mp[diff[i]]);

        ms.erase(ms.find(mp[diff[i - k]]));
        --mp[diff[i - k]];
        if (mp[diff[i - k]] > 0) ms.insert(mp[diff[i - k]]);
        res[i - k + 1] = *ms.rbegin();
    }
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << k - res[a] << endl;
    }
}

int32_t main(){
    faster();

    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}







