#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, m, k;
    cin >> n >> m >> k;
    string str;
    cin >> str;
    str = 'L' + str;
    int w = 0, ind = 0;
    while(ind <= n) {
        if (str[ind] == 'L') {
            if (n + 1 - ind <= m) {cout << "YES" << endl; return;}
            int posl = ind, posw = ind;
            for (int j = ind + 1; j <= ind + m && j <= n; ++j){
                if (str[j] == 'L') posl = j;
                else if (str[j] == 'W') posw = j;
            }
            if (posl > ind) ind = posl;
            else if (posw > ind) ind = posw;
            else {cout << "NO" << endl; return;}
        }
        else if (str[ind] == 'W') {
            ++w;
            ++ind;
            if (w > k || (ind <= n && str[ind] == 'C')) {cout << "NO" << endl; return;}
        }

    }
    cout << "YES" << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}
