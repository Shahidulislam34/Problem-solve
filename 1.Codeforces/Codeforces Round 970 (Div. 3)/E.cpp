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
        if (power % 2 == 0) base = ((base % mod) * (base % mod)) % mod, power /= 2;
        else res = ((res % mod) * (base % mod)) % mod, --power;
    }
    return res;
}

int pre[N + 5][26 + 5];

void sol(){
    int n;
    cin >> n;
    string str;
    cin >> str;

    str = '0' + str;
    for (int i = 0; i <= n + 2; ++i) {
        for (int j = 0; j <= 26; ++j)
            pre[i][j] = 0;
    }

    for (int i = 1; i <= n + 2; ++i) {
        if (i <= n)
        pre[i][str[i] - 'a' + 1] += 1;
        for (int j = 1; j <= 26; ++j) {
            pre[i][j] += pre[max(0ll, i - 2)][j];
        }
    }

    if (n % 2 == 0) {
        int even = 0, odd = 0;
        for (int i = 1; i <= 26; ++i) odd = max(odd, pre[n - 1][i]);
        for (int i = 1; i <= 26; ++i) even = max(even, pre[n][i]);
        cout << n - (even + odd) << endl;
    }
    else {
        int mx = 0;
        for (int i = 1; i <= n; ++i) {
            int s1 = 0, s2 = 0;
            for (int j = 1; j <= 26; ++j) {
                if (i % 2 == 1) {
                    s1 = max(s1, pre[i - 1][j] + (pre[n + 2][j] - pre[i][j]));
                    s2 = max(s2, pre[max(0ll, i - 2)][j] + (pre[n + 1][j] - pre[i - 1][j]));
                }
                else {
                    s1 = max(s1, pre[i - 1][j] + (pre[n + 1][j] - pre[i][j]));
                    s2 = max(s2, pre[max(0ll, i - 2)][j] + (pre[n][j] - pre[i - 1][j]));
                }
            }
            mx = max(mx, s1 + s2);
        }
    cout << n - mx << endl;
    }
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}












