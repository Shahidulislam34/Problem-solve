///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    int point[n + 5][5];
    for (int i = 1; i <= n; ++i) cin >> point[i][0] >> point[i][1];
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int dis = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    for (int i = 1; i <= n; ++i) {
        int m = (x2 - point[i][0]) * (x2 - point[i][0]) + (y2 - point[i][1]) * (y2 - point[i][1]);
        if (dis >= m) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}





