///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void sol(){
    int h, n;
    cin >> h >> n;
    vector<int>atk(n + 5), cdn(n + 5);
    for (int i = 1; i <= n; ++i) cin >> atk[i];
    for (int i = 1; i <= n; ++i) cin >> cdn[i];

    int res = 0, l = 1, r = 1e13, mid;
    while(l <= r){
        mid = (l + r) / 2;
        int cnt = 0;
        for (int i = 1; i <= n; ++i){
            cnt += (atk[i] * (1 + ((mid - 1) / cdn[i])));
            if (cnt >= h) break;
        }
        if (cnt >= h) res = mid, r = mid - 1;
        else l = mid + 1;
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







