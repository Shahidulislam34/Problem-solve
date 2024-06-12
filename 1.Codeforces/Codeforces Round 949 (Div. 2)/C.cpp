#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
int n;
int v[50 + 5], res[50 + 5];

void ok(int m){

}

void sol(){
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> v[i];
    int l = 1, r = 1e9, res = 0, m;
    while(l <= r){
        m = (l + r) / 2;
        if (ok(m)) r = m - 1, res = m;
        else l = m + 1;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}





