///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, k;
    cin >> n >> k;
    int cnt = 1, inc = 3;
    for (int i = 2; i <= k; ++i){
        cnt += inc;
        ++inc;
    }
    if (cnt <= n) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}






