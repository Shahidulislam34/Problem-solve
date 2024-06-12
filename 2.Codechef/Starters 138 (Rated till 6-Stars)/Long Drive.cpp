///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int x, y;
    cin >> x >> y;
    int res = 0;
    for (int i = 1; i <= 10000; ++i){
        if ((x * 10 + (i * 100)) / (10 + i) >= y){
            res = i;
            break;
        }
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






