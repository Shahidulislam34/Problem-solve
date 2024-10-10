#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

void sol(){
    int n, d, k;
    cin >> n >> d >> k;
    vector<int>last[n + 5];
    vector<int>fast(n + 5, 0);

    for (int i = 1; i <= k; ++i) {
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        ++fast[a];
        last[b].push_back(a);
    }

    multiset<int>ms;
    for (int i = 1; i <= d; ++i) {
        for (int j = 1; j <= fast[i]; ++j) ms.insert(i);
    }
    int sz = ms.size();
    int bro = 1, mo = 1, mx = sz, mn = sz;
    for (int i = 2; i <= n - d + 1; ++i) {
        for (auto x : last[i - 1]) {
            auto it = ms.find(x);
            if (it != ms.end()) ms.erase(it);
        }
        for (int j = 1; j <= fast[i + d - 1]; ++j) ms.insert(i + d - 1);
        sz = ms.size();
        if (sz > mx) bro = i, mx = sz;
        if (sz < mn) mo = i, mn = sz;
    }
    cout << bro << ' ' << mo << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}





