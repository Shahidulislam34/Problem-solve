///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    vector<int>v1(n + 5), v2(n + 5), v3(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v1[i];
    for (int i = 1; i <= n; ++i) cin >> v2[i];
    for (int i = 1; i <= n; ++i) cin >> v3[i];

    int sum = 0;
    for (int i = 1; i <= n; ++i) sum += v1[i];
    sum = ceil(1.0 * sum / 3);

    vector<int>pre1(n + 5, 0), pre2(n + 5, 0), pre3(n + 5, 0);
    for (int i = 1; i <= n; ++i) pre1[i] = pre1[i - 1] + v1[i];
    for (int i = 1; i <= n; ++i) pre2[i] = pre2[i - 1] + v2[i];
    for (int i = 1; i <= n; ++i) pre3[i] = pre3[i - 1] + v3[i];

    int ind = 1;
    for (int i = 1; i <= n; ++i) {
        if (pre1[i] - pre1[ind - 1] < sum) continue;
        while(ind < i && pre1[i] - pre1[ind] >= sum) ++ind;
        if (pre2[ind - 1] >= sum && (pre3[n] - pre3[i]) >= sum && ind > 1 && i < n){
            cout << ind << ' ' << i << ' ' << 1 << ' ' << ind - 1 << ' ' << i + 1 << ' ' << n << endl;
            return;
        }
        else if (pre3[ind - 1] >= sum && (pre2[n] - pre2[i]) >= sum && ind > 1 && i < n) {
            cout << ind << ' ' << i << ' ' << i + 1 << ' ' << n << ' ' << 1 << ' ' << ind - 1 << endl;
            return;
        }
    }
    ind = 1;
     for (int i = 1; i <= n; ++i) {
        if (pre2[i] - pre2[ind - 1] < sum) continue;
        while(ind < i && pre2[i] - pre2[ind] >= sum) ++ind;
        if (pre1[ind - 1] >= sum && (pre3[n] - pre3[i]) >= sum && ind > 1 && i < n){
            cout << 1 << ' ' << ind - 1 << ' ' << ind << ' ' << i << ' ' << i + 1 << ' ' << n << endl;
            return;
        }
        else if (pre3[ind - 1] >= sum && (pre1[n] - pre1[i]) >= sum && ind > 1 && i < n) {
            cout << i + 1 << ' ' << n << ' ' << ind << ' ' << i << ' ' << 1 << ' ' << ind - 1 << endl;
            return;
        }
    }
    ind = 1;
     for (int i = 1; i <= n; ++i) {
         if (pre3[i] - pre3[ind - 1] < sum) continue;
        while(ind < i && pre3[i] - pre3[ind] >= sum) ++ind;
        if (pre2[ind - 1] >= sum && (pre1[n] - pre1[i]) >= sum){
            cout << i + 1 << ' ' << n << ' ' << 1 << ' ' << ind - 1 << ' ' << ind << ' ' << i << endl;
            return;
        }
        else if (pre1[ind - 1] >= sum && (pre2[n] - pre2[i]) >= sum) {
            cout << 1 << ' ' << ind - 1 << ' ' << i + 1 << ' ' << n << ' ' << ind << ' ' << i << endl;
            return;
        }
    }
    cout << -1 << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}




