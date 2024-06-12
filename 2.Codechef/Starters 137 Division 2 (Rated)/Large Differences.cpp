#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void sol(){
    int n, k;
    cin >> n >> k;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    int sum = 0;
    for (int i = 1; i <= n - 1; ++i) sum += abs(v[i] - v[i + 1]);
    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    int ext = 0;
    ext = max(ext, abs(v[2] - 1ll) - abs(v[1] - v[2]));
    ext = max(ext, abs(v[2] - k) - abs(v[1] - v[2]));
    ext = max(ext, abs(v[n - 1] - 1ll) - abs(v[n] - v[n - 1]));
    ext = max(ext, abs(v[n - 1] - k) - abs(v[n] - v[n - 1]));
    for (int i = 2; i <= n - 1; ++i){
        ext = max(ext, max(abs(v[i - 1] - 1ll) + abs(v[i + 1] - 1ll), abs(v[i- 1] - k) + abs(v[i + 1] - k)) - (abs(v[i] - v[i + 1]) + abs(v[i - 1] - v[i])));
    }
    if (ext > 0) sum += ext;
    cout << sum << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}



