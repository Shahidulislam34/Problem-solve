///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    char ch = 'a';
    for (int i = 0; i < n; ++i) ch = max(ch, str[i]);
    cout << (ch - 'a' + 1) << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}



