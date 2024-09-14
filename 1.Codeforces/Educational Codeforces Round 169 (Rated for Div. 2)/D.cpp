#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
const int N = 2e5;
const int M = 1e9 + 7;

struct Points{
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

map<string, int>mp;


void sol(){
    int n, q;
    cin >> n >> q;
    vector<string>v(n + 5);
    set<int>ss[6 + 2];
    set<int, greater<int>>ssr[6 + 5];
    for (int i = 1; i <= n; ++i) {
        string str; cin >> str;
        v[i] = str;
        int ind = mp[str];
        ss[ind].insert(i);
        ssr[ind].insert(i);
    }

    while(q--) {
        int l, r;
        cin >> l >> r;
        if (l > r) swap(l, r);

        string s1, s2, s3, s4;
        s1.push_back(v[l][0]); s1.push_back(v[r][0]);
        s2.push_back(v[l][0]); s2.push_back(v[r][1]);
        s3.push_back(v[l][1]); s3.push_back(v[r][0]);
        s4.push_back(v[l][1]); s4.push_back(v[r][1]);

        if (s1[0] > s1[1]) swap(s1[0], s1[1]);
        if (s2[0] > s2[1]) swap(s2[0], s2[1]);
        if (s3[0] > s3[1]) swap(s3[0], s3[1]);
        if (s4[0] > s4[1]) swap(s4[0], s4[1]);
//        cout << s1 << endl << s2 << endl << s3 << endl << s4 << endl;

        int res = INT_MAX;
        vector<int>index{mp[s1], mp[s2], mp[s3], mp[s4]};
        for (int j = 0; j < 4; ++j) {
            if (ss[index[j]].empty()) continue;
            int fst = *ssr[index[j]].rbegin(), lst = *ss[index[j]].rbegin();
            if (lst >= l) {
                int val = *ss[index[j]].lower_bound(l);
                res = min(res, abs(l - val) + abs(val - r));
            }
            if (fst <= r) {
                int val = *ssr[index[j]].lower_bound(r);
                res = min(res, abs(l - val) + abs(val - r));
            }
        }
        if (res == INT_MAX) res = -1;
        cout << res << endl;
    }

}

int32_t main(){
    faster();
    mp["BG"] = 1, mp["BR"] = 2, mp["BY"] = 3, mp["GR"] = 4, mp["GY"] = 5, mp["RY"] = 6;
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}














