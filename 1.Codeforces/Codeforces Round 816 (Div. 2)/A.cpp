///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, m;
    cin >> n >> m;
    int res;
    if (m <= n)
    res = n + max(m - 1, 0ll) * 2;
    else
        res = m + max(n - 1, 0ll) * 2;
    if (n == 1 && m == 1) res = 0;
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}



