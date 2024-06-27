#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, x, y;
    cin >> n >> x >> y;
    vector<int>v(x + 5);
    for (int i = 1; i <= x; ++i) cin >> v[i];
    sort(v.begin() + 1, v.begin() + x + 1);
    int res = x - 2;
    for (int i = 2; i <= x; ++i){
        if (v[i] - 2 == v[i - 1]) ++res;
    }
    if ((v[x] + 2) % n == v[1]) ++res;
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}












