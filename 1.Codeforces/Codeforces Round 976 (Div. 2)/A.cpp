#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

void sol(){
    int n, k;
    cin >> n >> k;
    vector<int>v;
    int mul = 1;
    while(mul <= n) {
        v.push_back(mul);
        mul *= k;
        if (k == 1) break;
    }
    int res = 0, rem = n;
    for (int i = (int)v.size() - 1; i >= 0; --i) {
        if (v[i] <= rem) res += (rem / v[i]), rem -= (rem / v[i]) * v[i];
    }
    cout << res << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}






