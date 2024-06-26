///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int x, y, z;
    cin >> x >> y >> z;
    vector<int>v;
    v.push_back(x);
    v.push_back(y);
    v.push_back(z);
    sort(v.begin(), v.end());
    int res = 0;
    res = abs(v[0] - v[1]) + abs(v[1] - v[2]);
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}








