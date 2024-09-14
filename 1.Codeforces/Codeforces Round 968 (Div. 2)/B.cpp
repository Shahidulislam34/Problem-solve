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
    int n;
    cin >> n;
    string str;
    cin >> str;
    int cnt[26 + 5] = {0};
    for (int i = 0; i < n; ++i) ++cnt[str[i] - 'a' + 1];

    string ans;
    vector<pair<int, char>>pv;
    for (int i = 1; i <= 26; ++i) if (cnt[i] > 0) pv.push_back({cnt[i], 'a' + (i - 1)});
    sort(pv.begin(), pv.end());
    int sz = pv.size();
    int l = 0, r = sz - 1, cho = 1;
//    for (auto [x, y] : pv) cout << x << ' ' << y << endl;
    while(l <= r) {
        if (cho == 1) {
            if (pv[r].first > 0) ans.push_back(pv[r].second), --pv[r].first, cho ^= 1;
            else --r;
        }
        else {
            if (pv[l].first > 0) ans.push_back(pv[l].second), --pv[l].first, cho ^= 1;
            else ++l;
        }
//        cout << l << ' ' << r << ' ' << ans << endl;
    }
    if (ans[0] != ans[n - 1]) {
        char ch = ans[n - 1];
        for (int i = n - 1; i >= 1; --i) ans[i] = ans[i - 1];
        ans[0] = ch;
    }
    cout << ans << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}





