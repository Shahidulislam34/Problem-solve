///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    vector<int>even(n + 5, 0), odd(n + 5, 0);
    for (int i = 1; i <= n; ++i) {
        if (i % 2) odd[i] = v[i];
        else even[i] = v[i];
        odd[i] += odd[i - 1];
        even[i] += even[i - 1];
    }
    map<int, int>mp;
    ++mp[0];
    for (int i = 1; i <= n; ++i){
        ++mp[odd[i] - even[i]];
        if (mp[odd[i] - even[i]] > 1){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}

