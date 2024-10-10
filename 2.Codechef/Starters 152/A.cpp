#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    sort(v.begin() + 1, v.begin() + n + 1);
    int res = INT_MAX;
    res = min(res, abs(v[n - 2] - v[1]));
    res = min(res, abs(v[n] - v[3]));
    res = min(res, abs(v[n - 1] - v[2]));
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}





