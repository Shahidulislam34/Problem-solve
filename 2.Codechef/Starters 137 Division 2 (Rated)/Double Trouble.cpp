///accepted
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

    ///right,right
    int cnt = 0, flag = 0;
    for (int i = 1; i < n; ++i){
        if (v[i] + p[i] >= v[i + 1])continue;
        else ++cnt;
        if (cnt >= 2 && i < n) flag = 1;
    }
    if (cnt <= 2 && flag == 0) {
        cout << "YES" << endl;
        return;
    }

    ///left,left
    cnt = 0, flag = 0;
    for (int i = n; i > 1; --i){
        if (v[i] - p[i] <= v[i - 1])continue;
        else ++cnt;
        if (cnt >= 2 && i > 1) flag = 1;
    }
    if (cnt <= 2 && flag == 0){
        cout << "YES" << endl;
        return;
    }

    ///right,left
    cnt = 0, flag = 0;
    for (int i = 1; i < n; ++i){
        if (cnt == 0 && v[i] + p[i] >= v[i + 1])continue;
        else if (cnt == 1 && v[i + 1] - p[i + 1] <= v[i])continue;
        else ++cnt;
        if (cnt >= 2 && i < n)flag = 1;
    }
    if (cnt <= 2 && flag == 0) {
        cout << "YES" << endl;
        return;
    }

    ///left,right
    cnt = 0, flag = 0;
    for (int i = 1; i < n; ++i){
        if (cnt == 0 && v[i + 1] - p[i + 1] <= v[i]) continue;
        else if (cnt == 1 && v[i] + p[i] >= v[i + 1]) continue;
        else ++cnt;
        if (cnt >= 2 && i < n)flag = 1;
    }
    if (cnt <= 2 && flag == 0) {
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



