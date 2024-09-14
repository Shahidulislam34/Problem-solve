#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int>res(n + 5);
    for (int i = 1; i <= n; ++i){
        res[i] = n - i + 1;
    }
    int cnt = m;
    for (int i = n; i >= n - m + 1; --i){
        res[i] = cnt;
        --cnt;
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
