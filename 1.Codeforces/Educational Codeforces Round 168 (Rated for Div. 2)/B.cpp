#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define faster(); ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

void sol(){
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    s1 = '0' + s1;
    s2 = '0' + s2;
    int res = 0;
    for (int i = 2; i < n; ++i) {
        if (s1[i] == '.' && s1[i - 1] == '.' && s1[i + 1] == '.' && s2[i] == '.' && s2[i - 1] != '.' && s2[i + 1] != '.') ++res;
        if (s2[i] == '.' && s2[i - 1] == '.' && s2[i + 1] == '.' && s1[i] == '.' && s1[i - 1] != '.' && s1[i + 1] != '.') ++res;
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




