///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void sol(){
    int n, m;
    cin >> n >> m;
    vector<string>v;
    string str;
    v.push_back("::::");
    for (int i = 1; i <= n; ++i){
        cin >> str;
        str = '0' + str;
        v.push_back(str);
    }

    int r = 1, c = 1, num = -1, cnt = 0;
    for (int i = 1; i <= n; ++i){
        cnt = 0;
        for (int  j = 1; j <= m; ++j){
            if (v[i][j] == '#') ++cnt;
        }
        if (cnt > num) num = cnt, r = i;
    }
    num = -1;
    for (int i = 1; i <= m; ++i){
        cnt = 0;
        for (int j = 1; j <= n; ++j){
            if (v[j][i] == '#') ++cnt;
        }
        if (cnt > num) num = cnt, c = i;
    }
    cout << r << ' ' << c << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while (tt--) sol();
    return 0;
}







