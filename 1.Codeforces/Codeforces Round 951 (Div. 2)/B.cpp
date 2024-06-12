///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void sol(){
    int x, y;
    cin >> x >> y;
    bitset<31>bs_x(x), bs_y(y);
    int res = 1, m = 1;
    for (int i = 0; i <= 30; ++i){
        if (bs_x[i] != bs_y[i]) break;
        res += m;
        m *= 2;
    }
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}




