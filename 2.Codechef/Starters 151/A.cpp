#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define faster(); ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

void sol(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    int one = 0, zero = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == '0') ++zero;
        else ++one;
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (i >= one && (i - one) % 2 == 0) ++res;
        else if (i >= zero && (i - zero) % 2 == 0) ++res;
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


