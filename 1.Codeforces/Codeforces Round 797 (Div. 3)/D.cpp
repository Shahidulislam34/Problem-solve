///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    str = '0' + str;
    vector<int>pre(n + 5, 0);
    for (int i = 1; i <= n; ++i){
        if (str[i] == 'B') pre[i] = 1;
        pre[i] += pre[i - 1];
    }
    int res = INT_MAX;
    for (int i = k; i <= n; ++i){
        res = min(res, k - (pre[i] - pre[i - k]));
    }
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}


