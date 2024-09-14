#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, q;
    cin >> n >> q;
    vector<int>v(n + 5), p(n + 5);
    for (int i = 2; i <= n; ++i) cin >> v[i];
    for (int i = 1; i <= n; ++i) cin >> p[i];

    p[0] = 0;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (abs(p[i] - p[i - 1]) != 1 && (p[i] / 2) != p[i - 1]) ++cnt;
    }
    cout << "ini:" << cnt << endl;
    while(q--) {
        int a, b;
        cin >> a >> b;
        int f1 = 0, f2 = 0;
        if (abs(p[a] - p[a - 1]) != 1 && (p[a] / 2) != p[a - 1]) f1 = 1;
        if (abs(p[b] - p[b - 1]) != 1 && (p[b] / 2) != p[b - 1]) f2 = 1;
        for (int i = 1; i <= n; ++i) cout << p[i] << ' '; cout << endl;
        swap(p[a], p[b]);
        int g1 = 0, g2 = 0;
        if (abs(p[a] - p[a - 1]) != 1 && (p[a] / 2) != p[a - 1]) g1 = 1;
        if (abs(p[b] - p[b - 1]) != 1 && (p[b] / 2) != p[b - 1]) g2 = 1;
        if (f1 == 0 && g1 == 1) ++cnt;
        else if (f1 == 1 && g1 == 0) --cnt;


        if (f2 == 0 && g2 == 1) ++cnt;
        else if (f2 == 1 && g2 == 0) --cnt;
        cout << "cnt:" << cnt << endl;
        for (int i = 1; i <= n; ++i) cout << p[i] << ' '; cout << endl;

        cnt = max(cnt, 0ll);
        if (cnt == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

int32_t main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL); cout.tie(NULL);
    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}




