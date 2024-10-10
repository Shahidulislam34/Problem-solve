#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

void sol(){
    int n, m;
    cin >> n >> m;
    string ss, tt;
    cin >> ss; ss = '0' + ss;
    cin >> tt; tt = '0' + tt;

    if (ss[1] != tt[1]) cout << -1 << endl;
    else {
        int ind = 0;
        while(ind <= n && ind <= m) {
            if (ss[ind] != tt[ind]) break;
            ++ind;
        }
        if (ind > n && ind > m) cout << 0 << endl;
        else if (ind > n || ind > m) cout << 1 << endl;
        else {
            int flag = 0, tmp = m;
            if (n > m && ss.substr(n - (m - ind), m - ind + 1) == tt.substr(ind, m - ind + 1)) cout << 1 << endl;
            else if (m > n && ss.substr(ind, n - ind + 1) == tt.substr(m - (n - ind), n - ind + 1)) cout << 1 << endl;
            else cout << 2 << endl;
        }
    }
}
int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}





