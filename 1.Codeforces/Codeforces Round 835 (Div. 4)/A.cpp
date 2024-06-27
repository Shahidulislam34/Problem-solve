///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    vector<int>v(3 + 5);
    for (int i = 1; i <= 3; ++i) cin >> v[i];
    sort(v.begin() + 1, v.begin() + 3 + 1);
    cout << v[2] << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}


