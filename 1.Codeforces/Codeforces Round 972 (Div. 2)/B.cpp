#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster(); ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

void sol(){
    int n, t, q;
    cin >> n >> t >> q;

    int t1, t2, s1, res;
    cin >> t1 >> t2;
    cin >> s1;
    if (t1 > t2) swap(t1, t2);

    if (t1 < s1 && s1 < t2) res = (t1 + t2) / 2 - t1;
    else if (s1 < t1) res = t1 - 1;
    else res = n - t2;
    cout << res << endl;
}

int32_t main(){
    faster();
    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}


