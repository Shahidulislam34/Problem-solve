///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
const int N = 2e5;
const int M = 1e9 + 7;

struct Points
{
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
    for (int i = 1; i <= n; ++i) if (v[i] == 0) v[i] = 1e9 + 1;

    int m;
    cin >> m;
    while(m--) {
        string str;
        cin >> str;
        int sz = str.size();
        if (sz != n) {
            cout << "NO" << endl;
            continue;
        }
        str = '0' + str;
        map<int, int>mp1;
        map<int, int>mp2;
        int flag = 0;
        for (int i = 1; i <= n; ++i) {
            if (mp1[v[i]] == 0) mp1[v[i]] = str[i] - 'a' + 1;
            else if (mp1[v[i]] != (str[i] - 'a' + 1)) {
                cout << "NO" << endl;
                flag = 1;
                break;
            }
        }
        if (flag) continue;
        for (int i = 1; i <= n; ++i) {
            if (mp2[str[i] - 'a' + 1] == 0) mp2[str[i] - 'a' + 1] = v[i];
            else if (mp2[str[i] - 'a' + 1] != v[i]) {
                cout << "NO" << endl;
                flag = 1;
                break;
            }
        }
        if (flag) continue;
        cout << "YES" <<endl;
    }
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}










