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
        int val = i + 1;
        for (int j = 1; j <= m; ++j) {
            cout << val << ' '; ++val;
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



