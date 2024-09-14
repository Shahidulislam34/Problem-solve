///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    bitset<63>bs(n);
    vector<int>res;
    res.push_back(n);
    for (int i = 0; i <= 63; ++i) {
        if (bs[i] == 1) {
            bs[i] = 0;
            int val = bs.to_ullong();
            if (val > 0)
            res.push_back(val);
            bs[i] = 1;
        }
    }
    int sz = res.size();
    cout << sz << endl;
    for (int i = sz - 1; i >= 0; --i) cout << res[i] << ' '; cout << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}






