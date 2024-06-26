#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, k;
    cin >> n >> k;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    multiset<int>left,right;
    for (int i = 1; i <= n; ++i)right.insert(v[i]);

    int res[n + 5] = {0}, cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 1; i <= n; ++i){
        auto it2 = right.lower_bound(v[i]);
        right.erase(it2);
        cout << "LEFT:" ;
        for (auto x : left) cout << x << ' '; cout << endl;
        cout << "RIGHT:";
        for (auto x : right) cout << x << ' '; cout << endl;

        auto it1 = left.lower_bound(v[i] - k);
        cnt1 = distance(left.begin(), it1);
        cnt1 = i - cnt1 - 1;
        cnt1 = max(cnt1, 0ll);

        it2 = right.upper_bound(v[i]);
        cnt2 = distance(right.begin(), it2);
        cnt2 = n - i - cnt2;
        cnt2 = max(cnt2, 0ll);
        it2 = right.upper_bound(v[i] + k);
        cnt3 = distance(right.begin(), it2);
        cnt3 = n - i - cnt3;
        cout << cnt1 << ' ' << cnt2 << ' ' << cnt3 << ' ' << i - 1 << endl;
        res[i] = min(cnt3 + i - 1, cnt1 + cnt2);
        res[i] = max(0ll, res[i]);
        left.insert(v[i]);
    }
    for (int i = 1; i <= n; ++i) cout << res[i] << ' '; cout << endl;
}

int32_t main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}






