///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5, -1);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    int res = 0;
    for (int i = n - 1; i >= 1; --i){
        if (v[i] < v[i + 1]) continue;
        else {
            while(v[i] >= v[i + 1] && v[i + 1] > 0) v[i] /= 2, ++res;
        }
        if (v[i] == 0) break;
    }
    for (int i = 2; i <= n; ++i) {
        if (v[i - 1] >= v[i]){
            res = -1;
            break;
        }
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






