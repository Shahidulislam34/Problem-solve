#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    string str;
    cin >> str;
    map<int, int>mp;
    for (int i = 0; i < str.size(); ++i) ++mp[str[i]];
    if (mp['A'] + mp['C'] == mp['B']) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}








