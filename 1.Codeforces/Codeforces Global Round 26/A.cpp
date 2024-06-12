#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    if (v[1] == v[n]){
        cout << "NO" << endl;
        return;
    }
    string str;
    str.push_back('B');
    str.push_back('R');
    for (int i = 3; i <= n; ++i) str.push_back('B');
    cout << "YES" << endl;
    cout << str << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}
