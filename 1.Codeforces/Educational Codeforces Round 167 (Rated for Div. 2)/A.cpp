///accepted
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    while(n--){
        int x, y;
        cin >> x >> y;
        y -= (abs(x) - 1);
        if (x > 0) x *= -1;
        if (y < x) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    sol();
    return 0;
}
