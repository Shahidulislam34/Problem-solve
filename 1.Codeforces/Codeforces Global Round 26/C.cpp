#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    int pre[n + 5] = {0};
    int sum1 = 0;
    for (int i = n; i >= 1; --i){
        sum1 += v[i];
        pre[i] = sum1;
    }
    int res = 0;
    int sum = 0;
    for (int i = 1; i <= n; ++i){
        sum += v[i];
        res = max(res, abs(sum + pre[i + 1]));
        res = max(res, abs(abs(sum) + pre[i + 1]));
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
