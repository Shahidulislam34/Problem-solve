///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    v[0] = 1e10;
    v[n + 1] = 1e10;
    int a = v[0], res = 0;
    for (int i = 1; i <= n; ++i){
        int val = v[i];
        for (; i <= n; ++i){
            if (val != v[i]) break;
        }
        int b = v[i];
        if (a > val && val < b) ++res;
        a = v[i - 1];
        --i;
    }
    if (res == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}



