///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    vector<int>pre(n + 5, 0);
    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + v[i];

    int q;
    cin >> q;
    int l, u;
    while(q--){
        cin >> l >> u;
        int a = l, b = n, res = n, mid;
        while(a <= b){
            mid = (a + b) / 2;
            if (pre[mid] - pre[l - 1] >= u) res = mid, b = mid - 1;
            else a = mid + 1;
        }
        if (res == l) cout << res << ' ';
        else {
            int s1 = pre[res - 1] - pre[l - 1], s2 = pre[res] - pre[l - 1];
            if (s2 <= u){
                cout << res << ' ';
                continue;
            }
            else {
                if (u - s1 > s2 - u - 1) cout << res << ' ';
                else cout << res - 1 << ' ';
            }

        }
    }
    cout << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}


