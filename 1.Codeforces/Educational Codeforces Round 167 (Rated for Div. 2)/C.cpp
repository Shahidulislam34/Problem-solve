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

    int a = 0, b = 0;
    for (int i = 1; i <= n; ++i) {
        if (v1[i] == 0 && v2[i] == -1) continue;
        else if(v1[i] == -1 && v2[i] == 0) continue;
        else if(v1[i] == 0 && v2[i] == 0) continue;
        if (v1[i] == 1 && (v2[i] == 0 || v2[i] == -1)) ++a;
        else if(v2[i] == 1 && (v1[i] == 0 || v1[i] == -1)) ++b;
    }
    for (int i = 1; i <= n; ++i){
        if (v1[i] == 1 && v2[i] == 1){
            if (a <= b) ++a;
            else ++b;
        }
        else if(v1[i] == -1 && v2[i] == -1){
            if (b >= a) --b;
            else --a;
        }
    }
    cout << min(a, b) << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}







