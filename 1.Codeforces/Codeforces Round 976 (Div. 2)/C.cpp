#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

void sol(){
    int b, c, d;
    cin >> b >> c >> d;
    bitset<62>bb(b), cc(c), dd(d), res(0);
    for (int i = 0; i <= 61; ++i) {
        if (bb[i] == 0 && cc[i] == 0 && dd[i] == 1) res[i] = 1;
        else if (bb[i] == 1 && cc[i] == 1 && dd[i] == 1) res[i] = 0;
        else if (bb[i] == 1 && cc[i] == 0 && dd[i] == 1) res[i] = 0;

        else if (bb[i] == 0 && cc[i] == 0 && dd[i] == 0) res[i] = 0;
        else if (bb[i] == 1 && cc[i] == 1 && dd[i] == 0) res[i] = 1;
        else if (bb[i] == 0 && cc[i] == 1 && dd[i] == 0) res[i] = 0;

        else {
            cout << -1 << endl;
            return;
        }
    }
    int ans = 0, mul = 1;
    for (int i = 0; i <= 61; ++i) {
        if (res[i]) ans += mul;
        mul *= 2;
    }
    cout << ans << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}








