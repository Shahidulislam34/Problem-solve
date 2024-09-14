///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, q;
    cin >> n >> q;
    vector<int>v(n + 5, 0);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    vector<int>pre(n + 5, 0);
    int res = 0, sum = 0;
    for (int i = 1; i <= n; ++i){
        if (v[i] != v[i - 1]) ++sum;
        pre[i] = sum;
    }
    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + pre[i];
    for (int i = 1; i <= n; ++i)
        res += pre[n] - pre[i - 1] - (n - i + 1) * (pre[i] - pre[i - 1] - 1);
    while(q--){
        int ind, m;
        cin >> ind >> m;
        if (ind == 1 && ind == n){
            res = 1;
        }
        else if (v[ind] == m) {
            res = res;
        }
        else if (ind == 1){
            if (v[1] == v[2]) res += max(0ll, n - 1);
            else if (v[2] == m) res -= max(0ll, n - 1);
        }
        else if (ind == n){
            if (v[n - 1] == v[n]) res += max(0ll, n - 1);
            else if (v[n - 1] == m) res -= max(0ll, n - 1);
        }
        else if (v[ind - 1] != v[ind] && v[ind] != v[ind + 1] && v[ind - 1] != v[ind + 1] && v[ind - 1] != m && m != v[ind + 1]) {
            res = res;
        }
        else if (v[ind - 1] != v[ind] && v[ind] != v[ind + 1] && v[ind - 1] != v[ind + 1] && v[ind - 1] == m) {
             res -= max(0ll, (ind - 1)) * max(0ll, n - ind + 1);
        }
        else if (v[ind - 1] != v[ind] && v[ind] != v[ind + 1] && v[ind - 1] != v[ind + 1] && v[ind + 1] == m) {
            res -= (ind * (n - ind));
        }
        else if (v[ind - 1] == v[ind] && v[ind] == v[ind + 1]){
            res += (max(ind - 1, 0ll) * ((n - ind) * 2 + 1)) + (n - ind);
        }
        else if (v[ind - 1] == v[ind + 1]){
            if (m == v[ind + 1])
                res -= (max(ind - 1, 0ll) * ((n - ind) * 2 + 1)) + (n - ind);
        }
        else if (v[ind] == v[ind - 1]){
            if (m != v[ind + 1])
                res += max(ind - 1, 0ll) * (n - ind + 1);
            else res = res + max(ind - 1, 0ll) - max(0ll, n -ind);
        }
        else if (v[ind] == v[ind + 1]){
            if (m == v[ind - 1]) res = res - max(ind - 1, 0ll) + max(0ll, n - ind);
            else res += max(0ll, n - ind) * (ind);
        }
        v[ind] = m;
        cout << res << endl;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    sol();
    return 0;
}
