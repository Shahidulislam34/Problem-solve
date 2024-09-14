///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    vector<int>v1(n + 5), v2(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v1[i];
    for (int i = 1; i <= n; ++i) cin >> v2[i];

    for (int i = 1; i <= n; ++i){
        if (v1[i] < v2[i]){
            cout << "NO" << endl;
            return;
        }
    }
    set<int>non, zero;
    for (int i = 1; i <= n; ++i){
        if (v2[i] == 0){
            zero.insert(v1[i] - v2[i]);
        }
        else non.insert(v1[i] - v2[i]);
    }
    if (non.size() == 0){
        cout << "YES" << endl;
    }
    else if (non.size() == 1){
        int val = *(non.begin());
        for (auto x : zero){
            if (x > val){
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}


