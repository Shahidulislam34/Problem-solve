#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, k;
    cin >> n >> k;
    vector<int>v(k + 5);
    for (int i = 1; i <= k; ++i){
        cin >> v[i];
    }
    sort(v.begin() + 1, v.begin() + k + 1);
    int res = 0;
    for (int i = 1; i < k; ++i){
        res += (v[i] - 1) + v[i];
    }
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}
