#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, k;
    cin >> n >> k;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    map<int, int>mp;
    for (int i = 1; i <= n; ++i) ++mp[v[i]];
    int m = 0;
    vector<pair<int, int>>fin;
    for (int i = 1; i <= n; ++i){
        if (mp[v[i]] % 2 == 1){
            mp[v[i]] = 0;
            ++m;
            fin.push_back({v[i] % k, v[i]});
        }
    }
    n = fin.size();
    sort(fin.begin(), fin.end());

    int cnt = 0, res = 0, val;
    if (n % 2 == 1) cnt = 1;
    else cnt = 2;
    for (int i = 0; i < n; ++i){
        val = fin[i].first;
        vector<int>tmp;
        tmp.push_back(0);
        for (; i < n; ++i){
            if (val != fin[i].first) {
                --i;
                break;
            }
            tmp.push_back(fin[i].second);
        }
        int sz = tmp.size();
        --sz;
        if (sz % 2 == 1){
            vector<int>pre(sz + 5, 0), suf(sz + 5, 0);
            for (int j = 2; j <= sz - 1; j += 2) {
                pre[j] = pre[j - 1] + abs(tmp[j] - tmp[j - 1]);
                pre[j + 1] = pre[j];
            }
            for (int j = sz - 1; j > 1; j -= 2){
                suf[j] = suf[j + 1] + abs(tmp[j] - tmp[j + 1]);
                suf[j - 1] = suf[j];
            }
            int mx = INT_MAX;
            for (int j = 1; j <= sz; j += 2) mx = min(mx, pre[j - 1] + suf[j + 1]);
            res += mx / k;
            ++cnt;
        }
        else {
            int mx = 0;
            for (int j = 1; j < sz; j += 2) mx += abs(tmp[j + 1] - tmp[j]) / k;
            res += mx;
        }
        if (cnt > 2){
            res = -1;
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
