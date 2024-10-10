#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
struct exercise{
    int n, s, r;
};
vector<exercise>v(7);
void sol(){
    int m; cin >> m;
    int flag = 1;
    while(m--) {
        for (int i = 0; i < 5; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            if (v[i].n != a || v[i].s != b || v[i].r != c) flag = 0;
        }
    }
    if (!flag) cout << "Inconsistent" << endl;
    else cout << "Consistent" << endl;
}

int32_t main(){
    faster();
    v[0].n = 2; v[0].s = 3; v[0].r = 10;
    v[1].n = 2; v[1].s = 3; v[1].r = 10;
    v[2].n = 2; v[2].s = 3; v[2].r = 10;
    v[3].n = 1; v[3].s = 3; v[3].r = 10;
    v[4].n = 3; v[4].s = 3; v[4].r = 10;
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}

