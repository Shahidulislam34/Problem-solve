#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

void sol(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == j) cout << 3 << ' ';
            else if (i < j && i == n) cout << 3 << ' ';
            else if (i > j && j == m) cout << 3 << ' ';
            else cout << 2 << ' ';
        }
        cout << endl;
    }
}
int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}




