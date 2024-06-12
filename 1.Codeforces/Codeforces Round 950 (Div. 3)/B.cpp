///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void sol(){
    int n, ind, k;
    cin >> n >> ind >> k;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    int val = v[ind];
    sort(v.begin() + 1, v.begin() + n + 1);
    int fst = 0;
    for (int i = n; i >= 1; --i){
        if (v[i] == val){
            fst = i;
            break;
        }
    }
    int cnt = 0, lst = 0;
    for (int i = fst; i >= 1; --i){
        if (v[i] == val){
            lst = i;
        }
        else break;
    }
    fst = n - fst + 1;
    lst = n - lst + 1;
    if (lst <= k) cout << "YES" << endl;
    else if (fst > k) cout << "NO" << endl;
    else cout << "MAYBE" << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}



