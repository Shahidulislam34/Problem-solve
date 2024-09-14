#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
const int N = 2e5;
const int M = 1e9 + 7;

struct Points {
    int x, y, z;
};
int On(int n, int k){
    return n |= (1 << k);
}
int Off(int n, int k){
    return n &= (LLONG_MAX ^ (1 << k));
}
int Flip(int n, int k){
    return n ^= (1 << k);
}
bool Check(int n, int k){
    if ((n & (1 << k)) != 0) return true;
    else return false;
}
long double Distance(Points a, Points b){
    return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int Distance_sq(Points a, Points b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int Big_mod(int base, int power, int mod){
    int res = 1;
    while (power != 0)
    {
        if (power % 2 == 0) base = (1LL * base * base) % mod, power /= 2;
        else res = (1LL * res * base) % mod, --power;
    }
    return res;
}
vector<int>v1(N + 5), v2(N + 5);
vector<pair<int, int>>pv(N + 5);

int ok(int n, int k) {
    int cnt = 0;
    bool vis[n + 5];
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 0) {
            int ind = -1, dif;
            if (pv[i].second == 1) {
                for (int j = i + 1; j <= n; ++j) {
                    dif = abs(pv[j].first - pv[i].first);
                    if (pv[j].second == 2 && vis[j] == 0 && dif >= k) {
                        ind = j;
                        break;
                    }
                }
            }
            else {
                for (int j = i + 1; j <= n; ++j) {
                    dif = abs(pv[j].first - pv[i].first);
                    if (pv[j].second == 1 && vis[j] == 0 && dif >= k) {
                        ind = j;
                        break;
                    }
                }
            }
            cout << "i:" << i << ' ' << ind << endl;
            if (ind > i) {
                ++cnt;
                vis[i] = vis[ind] = true;
            }
        }
    }
    cout << "cnt:" << cnt << endl;
    if (cnt == n) return true;
    else return false;
}

void sol(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> v1[i], pv[i] = {v1[i], 1};
    for (int i = 1; i <= n; ++i) cin >> v2[i], pv[n + i] = {v2[i], 2};

    sort(pv.begin() + 1, pv.begin() + 2 * n + 1);
    for (int i = 1; i <= 2 * n; ++i) cout << pv[i].first << ' '; cout << endl;

    int l = 0, r = 5, res = 0, mid;
    while(l <= r) {
        mid = (l + r) / 2;
        bool ret = ok(2 * n, mid);
        cout << "mid:" << mid << ' ' << ret << endl;
        if (ret == true) res = max(mid, res), l = mid + 1;
        else r = mid - 1;
    }
    cout << res << endl;
}

int32_t main(){
//    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}


