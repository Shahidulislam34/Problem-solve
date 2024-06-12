#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5, 0);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    int pre[n + 5] = {0}, suf[n + 5] = {0};
    int gc = 0;
    for (int i = 2; i <= n; ++i){
        if (__gcd(v[i], v[i - 1]) >= gc) pre[i] = 0, gc = __gcd(v[i], v[i - 1]);
        else {
            for (; i <= n; ++i) pre[i] = 1;
            break;
        }
    }

    gc = INT_MAX;
    for (int i = n - 1; i >= 1; --i){
        if (__gcd(v[i], v[i + 1]) <= gc) suf[i] = 0, gc = __gcd(v[i], v[i + 1]);
        else {
            for (; i >= 1; --i) suf[i] = 1;
            break;
        }
    }

    if (suf[2] == 0 || pre[n - 1] == 0 || suf[1] == 0 || pre[n] == 0) {
        cout << "YES" << endl;
        return;
    }
    for (int i = 2; i <= n - 1; ++i){
        int a, b, c;
        a = __gcd(v[i - 1], v[i - 2]);
        b = __gcd(v[i - 1], v[i + 1]);
        c = __gcd(v[i + 1], v[i + 2]);
        if (i > 2 && pre[i - 1] == 0 && suf[i + 1] == 0 && a <= b && b <= c){
            cout << "YES" << endl;
            return;
        }
        else if (i == 2 && pre[i - 1] == 0 && suf[i + 1] == 0 && b <= c){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}



