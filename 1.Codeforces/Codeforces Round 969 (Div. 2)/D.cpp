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
    vector<int>cnt(n + 5, 0);
    for (int i = 1; i <= n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        ++cnt[a];
        ++cnt[b];
    }
    string str;
    cin >> str; str = '0' + str;

    int one = 0, zero = 0, ques = 0, other = 0;
    for (int i = 2; i <= n; ++i) {
        if (cnt[i] == 1 && str[i] == '1') ++one;
        else if (cnt[i] == 1 && str[i] == '0') ++zero;
        else if (cnt[i] == 1 && str[i] == '?') ++ques;
        else if (str[i] == '?') ++other;
    }
    int res = 0;
    if (str[1] != '?') {
        if (str[1] == '1') res = zero + (ques + 1) / 2;
        else res = one + (ques + 1) / 2;
    }
    else {
        if (one != zero) {
            if (one > zero) res = one + (ques / 2);
            else res = zero + ques / 2;
        }
        else {
            if (other % 2 == 1) res = one + (ques + 1) / 2;
            else res = one + (ques / 2);
        }
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












