///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int a, b, c;
    cin >> a;
    b = a + a;
    c = a * a;
    if (a == 2) c *= a;
    cout << b << ' ' << c << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}





