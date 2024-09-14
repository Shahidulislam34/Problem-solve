///accepted
#include<bits/stdc++.h>
using namespace std;
#define int int
#define endl '\n'
///ordered_set------zero base index-----only for 'int' data type
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type,
less<T>, rb_tree_tag, tree_order_statistics_node_update>;
///ordered_set-------

void sol(){
    int n;
    cin >> n;
    vector<pair<int, int>>pv(n + 5);
    for (int i = 1; i <= n; ++i) cin >> pv[i].first >> pv[i].second;
    sort(pv.begin() + 1, pv.begin() + n + 1);
    o_set<int>ss;
    long long res = 0;
    for (int i = n; i >= 1; --i){
        res += ss.order_of_key(pv[i].second);
        ss.insert(pv[i].second);
    }
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}
