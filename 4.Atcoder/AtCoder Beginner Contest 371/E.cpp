#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void sol() {
    int n;
    cin >> n;
    vector<int>v(n + 5);
    for (int i =1 ; i <= n; ++i) cin >> v[i];

    int last[n + 5];
    fill(last, last + n + 5, n + 1);

    int res = (n * (n + 1) * (n + 2)) / 6;
    for (int i = 1; i <= n; ++i) {
        if (last[v[i]] < i) {
            res -= last[v[i]] * (n - i + 1);
        }
        last[v[i]] = i;
    }
    cout << res << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    sol();
    return 0;
}



