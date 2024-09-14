#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
const int N = 2e5;
const int M = 1e9 + 7;

void sol(){
    int n, k;
    cin >> n >> k;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    map<int, int>mp;
    int res = 0, sum = 0;
    for (int i = 1; i <= n; ++i) res += mp[sum - k], sum += v[i], ++mp[sum - k];
    cout << res << endl;

    int ans = 1;
    for (int i = 1; i <= n - 1; ++i) ans *= 2;
    cout << ans << endl;

}

int32_t main(){
    sol();
    return 0;
}


