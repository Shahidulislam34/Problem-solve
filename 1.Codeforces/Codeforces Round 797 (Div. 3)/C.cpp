///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    vector<int>v1(n + 5, 0), v2(n + 5, 0);
    for (int i = 1; i <= n; ++i) cin >> v1[i];
    for (int i = 1; i <= n; ++i) cin >> v2[i];

    vector<int>res(n + 5, 0);
    for (int i = 1; i <= n; ++i){
        int mx = max(v1[i], v2[i - 1]);
        res[i] = v2[i] - mx;
    }
    for (int i = 1; i <= n; ++i) cout << res[i] << ' '; cout << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}


