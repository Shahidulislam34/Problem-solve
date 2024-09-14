///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, k, b, s;
    cin >> n >> k >> b >> s;
    if ((k - 1) * n + b * k < s || b * k > s)
        cout << -1 << endl;
    else {
        vector<int>res(n + 5, 0);
        int extra = 0;
        if (k > 1) extra = (s - b * k) / (k - 1);
        int sum = 0;
        for (int i = 1; i <= extra; ++i) res[i] = (k - 1), sum += (k - 1);
        res[n] += (s - sum);
        for (int i = 1; i <= n; ++i) cout << res[i] << ' '; cout << endl;

    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}



