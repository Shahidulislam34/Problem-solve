#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);


void sol(){
    int n, k;
    cin >> n >> k;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    int sum = 0, res = 0;
    for (int i = 1; i <= n; ++i) {
        if (v[i] >= k) sum += v[i];
        else if (v[i] == 0 && sum > 0) ++res, --sum;
    }
    cout << res << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}



