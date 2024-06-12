///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void sol(){
    int n, k;
    cin >> n >> k;
    map<char, int>mp;
    string str;
    cin >> str;
    for (int i = 0; i < n; ++i) {
        ++mp[str[i]];
    }
    int res = 0;
    for (char ch = 'A'; ch <= 'G'; ++ch){
        if (mp[ch] <= k) res += (k - mp[ch]);
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


