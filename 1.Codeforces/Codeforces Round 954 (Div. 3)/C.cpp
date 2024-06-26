///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;

    vector<int>v(m + 5);
    for (int i = 1; i <= m; ++i) cin >> v[i];
    string c;
    cin >> c;

    sort(v.begin() + 1, v.begin() + m + 1);
    sort(c.begin(), c.end());

    int val = -1, ind = -1;
    for (int i = 1; i <= m; ++i){
        if (v[i] > val){
            val = v[i];
            ++ind;
            str[val - 1] = c[ind];
        }
    }
    cout << str << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}










