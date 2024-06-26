///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, k;
    cin >> n >> k;
    if (k == 1 || k == n){
        int inc = 0, val = 1, m = 0;
        if (k == 1) inc = 1;
        for (int i = 1; i <= n; ++i) cout << val + m << ' ', m += inc; cout << endl;
    }
    else cout << -1 << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}










