#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
const int N = 2e5, M = 1e9 + 7;
vector<pair<int, int>>pv(N + 5), tree(4 * N + 5);
int m;

void init_tree(int cn, int li, int ri) {
    if (li == ri) {
        tree[cn] = pv[li];
        return;
    }
    int ln = cn * 2, rn = cn * 2 + 1;
    int mid = (li + ri) / 2;
    init_tree(ln, li, mid);
    init_tree(rn, mid + 1, ri);
    tree[cn] = max(tree[ln], tree[rn]);
}

void update_tree(int cn, int li, int ri, int ind, pair<int, int>pp) {
//    cout << cn << ' ' << li << ' ' << ri << endl;
    if (ind < li || ri < ind) return;
    else if (li == ind && ri == ind) {
        tree[cn] = pp;
        return;
    }
    int ln = cn * 2, rn = cn * 2 + 1;
    int mid = (li + ri) / 2;
    update_tree(ln, li, mid, ind, pp);
    update_tree(rn, mid + 1, ri, ind, pp);
    tree[cn] = max(tree[ln], tree[rn]);
}

pair<int, int> get_tree(int cn, int li, int ri, int a, int b) {
    if (b < li || ri < a) return {INT_MIN, 0};
    else if (a <= li && ri <= b) return tree[cn];
    int ln = cn * 2, rn = cn * 2 + 1;
    int mid = (li + ri) / 2;
    return max(get_tree(ln, li, mid, a, b), get_tree(rn, mid + 1, ri, a, b));
}

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5), pre(n + 5, 0);
    for (int i = 1; i <= n; ++i) cin >> v[i], pre[i] = pre[i - 1] + v[i];
//    for (int i = 1; i <= n; ++i) cout << pre[i] << ' '; cout << endl;

    map<int, int>mp;
    mp[0] = 0;
    for (int i = 1; i <= n; ++i) mp[pre[i]] = 1;
    m = -1;
    for (auto [x, y] : mp) mp[x] = ++m;
    for (int i = 0; i <= n; ++i) pre[i] = mp[pre[i]];
    for (int i = 0; i <= n; ++i) cerr << pre[i] << ' '; cout << endl;

    for (int i = 0; i <= m; ++i) pv[i] = {LLONG_MIN, i};

    int dp[n + 5];
    dp[0] = 0;
    init_tree(1, 0, m);
    for (int i = 1; i <= 9; ++i) cerr << tree[i].first << ' '; cout << endl;
    cerr << "update 0: " << endl;
    update_tree(1, 0, m, pre[0], {dp[0] - 0, 0});
    for (int i = 1; i <= 9; ++i) cerr << tree[i].first << ' '; cout << endl;
    for (int i = 1; i <= n; ++i) {
        pair<int, int>gg = get_tree(1, 0, m, 0, pre[i]);
        dp[i] = max(dp[i - 1], gg.first + i);
        update_tree(1, 0, m, pre[i], {dp[i] - i, i});
    }
    cout << dp[n] << endl;
}

int32_t main(){
    faster();
    sol();
    return 0;
}

