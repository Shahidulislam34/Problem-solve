#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int a, b, c;
    cin >> a >> b >> c;
    vector<int>v = {a, b, c};
    for (int i = 1; i <= 5; ++i){
        sort(v.begin(), v.end());
        ++v[0];
    }
    cout << (v[0] * v[1] * v[2]) << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}
