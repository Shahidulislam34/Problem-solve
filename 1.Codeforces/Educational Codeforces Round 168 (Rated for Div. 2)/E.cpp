#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster(); ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N = 2e5;
int n, q;
vector<int>v(N + 5), tree[4 * N + 5];

void mergee(int cn, int ln, int rn) {
    int ls = tree[ln].size(), rs = tree[rn].size();
    int l = 0, r = 0;
    while(l < ls & r < rs) {
        if (tree[ln][l] <= tree[rn][r]) tree[cn].push_back(tree[ln][l]), ++l;
        else tree[cn].push_back(tree[rn][r]), ++r;
    }
    while(l < ls) tree[cn].push_back(tree[ln][l]), ++l;
    while(r < rs) tree[cn].push_back(tree[rn][r]), ++r;
}

void divide(int cn, int li, int ri) {
    if (li == ri) {
        tree[cn].push_back(v[li]);
        return;
    }
    int mid = (li + ri) / 2;
    int ln = cn * 2, rn = cn * 2 + 1;
    divide(ln, li, mid);
    divide(rn, mid + 1, ri);
    mergee(cn, ln, rn);
}

int cnt(int cn, int k) {
    return (int)tree[cn].size() - (lower_bound(tree[cn].begin(), tree[cn].end(), k) - tree[cn].begin());
}

int get(int cn, int li, int ri, int x, int y, int k) {
    if (x <= li && ri <= y) return cnt(cn, k);
    else if (y < li || ri < x) return 0;
    int mid = (li + ri) / 2;
    int ln = cn * 2, rn = cn * 2 + 1;
    return get(ln, li, mid, x, y, k) + get(rn, mid + 1, ri, x, y, k);
}

void sol(){
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> v[i];
    divide(1, 1, n);

    while(q--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << get(1, 1, n, l, r, k) << endl;
    }
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}






