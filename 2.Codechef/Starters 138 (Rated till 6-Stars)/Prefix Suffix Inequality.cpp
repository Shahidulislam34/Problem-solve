///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5);
    v[n] = 1;
    for (int i = 1; i <= n - 1; ++i) v[i] = 7;
    for (int i = 1; i <= n; ++i) cout << v[i] << ' '; cout << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}






