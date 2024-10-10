#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

void sol(){
    int k; cin >> k;
    int res = LLONG_MAX, l = 1, r = (int)2e18, mid;
    while(l <= r) {
        mid = (l + r) / 2;
        int purno = floor((double) sqrtl(mid));
        int tot = mid - purno;
        if (tot >= k) res = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << res << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}







