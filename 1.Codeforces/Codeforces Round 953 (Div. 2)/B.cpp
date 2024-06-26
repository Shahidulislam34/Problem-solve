#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, a, b;
    cin >> n >> a >> b;
    int res = 0;
    int mx = max(0ll, b - a);
    mx = min(n, mx);
    n -= mx;
    res = n * a;
    int m = max(0ll, b - mx);
    res += (((b * (b + 1)) / 2) - (m * (m + 1)) / 2);
    cout << res  << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}






