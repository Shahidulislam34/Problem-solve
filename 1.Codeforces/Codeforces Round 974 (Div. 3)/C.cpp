#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);


void sol(){
    int n, sum = 0;
    cin >> n;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i], sum += v[i];

    int mx = *max_element(v.begin() + 1, v.begin() + n + 1);
    int ind;
    for (int i = 1; i <= n; ++i) if (v[i] == mx) ind = i;

    int num = 0, mid = 0;
    for (int i = 1; i <= n; ++i) {
            if (i == ind && (sum + mid) > (v[i] + mid) * 2 * n) ++num;
            else if (i != ind && (sum + mid) > v[i] * 2 * n) ++num;
        }
    if (num > (n / 2)) {
        cout << 0 << endl;
        return;
    }

    int res = -1, l = 1, r = (int)1e12;
    while(l <= r) {
        mid = (l + r) / 2;
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (i == ind && (sum + mid) > (v[i] + mid) * 2 * n) ++cnt;
            else if (i != ind && (sum + mid) > v[i] * 2 * n) ++cnt;
        }
        if (cnt > (n / 2)) res = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << res << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}




