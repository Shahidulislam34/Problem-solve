///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void sol(){
    int p, t;
    cin >> p >> t;
    vector<int>ps(p + t + 5, 0), ts(p + t + 5, 0);
    for (int i = 1; i <= p + t + 1; ++i) cin >> ps[i];
    for (int i = 1; i <= p + t + 1; ++i) cin >> ts[i];

    int taken[p + t + 5] = {0}, totp = 0, tott = 0, pos = -1, neg = p + t + 2,cnt = 0, last = -1;
    for (int i = 1; i <= p + t + 1; ++i){
        if (cnt < p && ps[i] > ts[i]) totp += ps[i], ++cnt, last = i, taken[i] = 1;
    }
    for (int i = p + t + 1; i >= 1 && cnt < p; --i){
        if (taken[i] == 0) totp += ps[i], taken[i] = 1, ++cnt, neg = i;
    }

    pos = -1;
    for (int i = last + 1; i <= p + t + 1; ++i){
        if (taken[i] == 0 && ps[i] > ts[i]){
            pos = i;
            break;
        }
    }
    for (int i = neg - 1; i >= 1; --i){
        if (taken[i] == 0){
            neg = i;
            break;
        }
    }

    for (int i = 1; i <= p + t + 1; ++i) {
        if (taken[i] == 0) tott += ts[i];
    }
    int res[p + t + 5] = {0};
    for (int i = 1; i <= p + t + 1; ++i){
        if (taken[i] == 0){
            res[i] = totp + tott - ts[i];
        }
        else {
            if (pos != -1) res[i] = totp - ps[i] + ps[pos] - ts[pos] + tott;
            else res[i] = totp - ps[i] + ps[neg] - ts[neg] + tott;
        }
    }
    for (int i = 1; i <= p + t + 1; ++i) cout << res[i] << ' '; cout << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}

