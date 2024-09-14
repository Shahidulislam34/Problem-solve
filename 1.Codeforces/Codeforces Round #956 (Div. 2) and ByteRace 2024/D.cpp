///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

///SEGMENT TREE STARTS-----O(nlogn)-----one base indexing
const int N = 2e5;
vector<int>V(N + 5), TREE(4 * N + 5), PROP(4 * N + 5, 0);
void init_tree(int cn, int li, int ri){
    if (li == ri){
        TREE[cn] = V[li];
        return;
    }
    int mid = (li + ri) / 2;
    int ln = cn * 2, rn = cn * 2 + 1;
    init_tree(ln, li, mid);
    init_tree(rn, mid + 1, ri);
    TREE[cn] = TREE[ln] + TREE[rn];
}

void update_tree(int cn, int li, int ri, int a, int b, int val){
    if (ri < a || li > b) return;
    else if (a <= li && ri <= b){
        TREE[cn] += (ri - li + 1) * val;
        PROP[cn] += val;
        return;
    }
    int mid = (li + ri) / 2;
    int ln = 2 * cn, rn = 2 * cn + 1;
    update_tree(ln, li, mid, a, b, val);
    update_tree(rn, mid + 1, ri, a, b, val);
    TREE[cn] = TREE[ln] + TREE[rn] + PROP[cn] * (ri - li + 1);
}

int get_val(int cn, int li, int ri, int a, int b, int car){
    if (ri < a || li > b) return 0;
    else if (a <= li && ri <= b){
        return TREE[cn] + car * (ri - li + 1);
    }
    int mid = (li + ri) / 2;
    int ln = 2 * cn, rn = 2 * cn + 1;
    int s1 = get_val(ln, li, mid, a, b, car + PROP[cn]);
    int s2 = get_val(rn, mid + 1, ri, a, b, car + PROP[cn]);
    return s1 + s2;
}
///SEGMENT TREE ENDS-------

void sol(){
    int n, mx1 = 0, mx2 = 0;
    cin >> n;
    vector<int>v1(n + 5, 0), v2(n + 5, 0);
    for (int i = 1; i <= n; ++i) cin >> v1[i], mx1 = max(mx1, v1[i]);
    for (int i = 1; i <= n; ++i) cin >> v2[i], mx2 = max(mx2, v2[i]);

    map<int, int>ind1, ind2;
    for (int i = 1; i <= n; ++i) ind1[v1[i]] = i;
    for (int i = 1; i <= n; ++i) ind2[v2[i]] = i;

    for (int i = 1; i <= n; ++i){
        if (v1[i] > mx2 || ind2[v1[i]] == 0){
            cout << "NO" << endl;
            return;
        }
    }

    for (int i = 1; i <= 4 * n; ++i) TREE[i] = PROP[i] = 0;
    int two = 0;
    for (int i = 1; i <= n; ++i){
        int inc = get_val(1, 1, n, ind1[v2[i]], ind1[v2[i]], 0);
        two += (ind1[v2[i]] + inc) - i;
        update_tree(1, 1, n, 1, ind1[v2[i]] - 1, 1);
    }
    if (two % 2) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}



