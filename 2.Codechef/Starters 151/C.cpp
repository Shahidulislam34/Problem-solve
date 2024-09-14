#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define faster(); ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

void sol(){
    int a, b, k;
    cin >> a >> b >> k;
    if (k == 1) {cout << 0 << endl; return;}
    auto bin_search2 = [&](int val) {
        int l2 = 0, r2 = (int)INT_MAX, mid2, res2 = 0;
        while(l2 <= r2) {
            mid2 = (l2 + r2) / 2;
            if (mid2 * b + a <= val) res2 = mid2, l2 = mid2 + 1;
            else r2 = mid2 - 1;
        }
        if (a <= val) ++res2;
        return (int)res2;
    };

    int l = 0, r = (int)LLONG_MAX, res = 0, mid;
    while(l <= r) {
        mid = (l + r) / 2;
        int tot = mid / b + 1 + bin_search2(mid);
        if (tot < k) l = mid + 1;
        else r = mid - 1, res = mid;
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



