///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int res = 0;
    if (a > c && (b >= d)) res += 2;
    else if (a >= c && (b > d)) res += 2;

    if (a > d && b >= c) res += 2;
    else if (a >= d && b > c) res += 2;
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}


