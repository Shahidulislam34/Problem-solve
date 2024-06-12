///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    int sum = 0, mx = 0, res = 0;
    for (int i = 1; i <= n; ++i){
        if (mx < v[i]) {
            sum += mx;
            mx = v[i];
        }
        else {
            sum += v[i];
        }
        if (sum == mx) ++res;
    }
    cout << res << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}






