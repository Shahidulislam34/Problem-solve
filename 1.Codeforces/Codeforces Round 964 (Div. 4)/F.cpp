///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M = 1e9 + 7;
const int N = 2e5;
vector<int>pc(N + 5);

int big_mod(int base, int power, int mod){
    int res = 1;
    while (power != 0){
        if (power % 2 == 0) base = (1LL * base * base) % mod, power /= 2;
        else res = (1LL * res * base) % mod, --power;
    }
    return res;
}

int ncr(int n, int r) {
    if (n < r) return 0;
    else if (r < 0) return 1;
    int base = pc[n - r] * pc[r] % M;
    int inv = big_mod(base, M - 2, M) % M;
    return (pc[n] * inv) % M;
}

void sol(){
    int n, k;
    cin >> n >> k;
    int one = 0, zero = 0;
    for (int i = 1; i <= n; ++i) {
        int m;
        cin >> m;
        if (m) ++one;
        else ++zero;
    }
    int res = 0;
    for (int i = (k + 1) / 2; i <= min(one, k); ++i) {
        res += (1ll * ncr(one, i) * ncr(zero, k - i)) % M;
        res %= M;
    }
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    pc[0] = 1;
    for (int i = 1; i <= N; ++i) pc[i] = (1ll * pc[i - 1] * i) % M;
    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}


