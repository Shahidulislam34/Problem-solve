///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    vector<int>v1(n + 5), v2(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v1[i];
    for (int i = 1; i <= n + 1; ++i) cin >> v2[i];
    int add = INT_MAX;
    for (int i = 1; i <= n; ++i){
        int a,b;
        a = min(v1[i], v2[i]);
        b = max(v1[i], v2[i]);
        if (a <= v2[n + 1] && v2[n + 1] <= b){
            add = 0;
            break;
        }
        else {
            add = min(add, abs(v2[n + 1] - v1[i]));
            add = min(add, abs(v2[n + 1] - v2[i]));
        }
    }
    int res = 0;
    res = add + 1;
    for (int i = 1; i <= n; ++i){
        res += abs(v1[i] - v2[i]);
    }
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}

