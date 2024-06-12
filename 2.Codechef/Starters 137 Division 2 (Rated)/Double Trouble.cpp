#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    vector<int>v(n + 5), p(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    for (int i = 1; i <= n; ++i) cin >> p[i];
    if (n <= 2){
        cout << "YES" << endl;
        return;
    }
    int cnt = 0, res = 1;
    for (int i = 2; i <= n; ++i) {
        if (v[i - 1] + p[i - 1] >= v[i]) res = i;
        else ++cnt;
        if (cnt == 2) {
            res = i - 1;
            break;
        }
    }
    if (cnt <= 2 && res >= n) {
        cout << "YES" << endl;
        return;
    }

    cnt = 0, res = n;
    for (int i = n - 1; i >= 1; --i){
        if (v[i + 1] - p[i + 1] <= v[i]) res = i;
        else ++cnt;
        if (cnt >= 2) {
            res = i + 1;
            break;
        }
    }
    if (cnt <= 2 && res <= 1){
        cout << "YES" << endl;
        return;
    }

    cnt = 0, res = 1;
    for (int i = 2; i <= n; ++i){
        if (cnt == 0 && v[i - 1] + p[i - 1] >= v[i]) res = i;
        else if (cnt == 1 && i < n && v[i + 1] - p[i + 1] <= v[i]) res = i;
        else ++cnt;
        if (cnt >= 2){
            res = i;
            break;
        }
    }
    if (cnt <= 2 && res >= n) {
        cout << "YES" << endl;
        return;
    }

    cnt = 0, res = 1;
    for (int i = 2; i <= n; ++i){
        if (cnt == 0 && v[i] - p[i] <= v[i - 1]) res = i;
        else if(cnt == 1 && v[i - 1] + p[i - 1] >= v[i]) res = i;
        else ++cnt;
        if (cnt >= 2) {
            res = i - 1;
            break;
        }
    }
    if (cnt <= 2 && res >= n) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}



