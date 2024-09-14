///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    int zero = 0, one = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == '1') {
            ++one;
            continue;
        }
        else {
            ++zero;
            for (; i < n; ++i) {
                if (str[i] == '1') break;
            }
            --i;
        }
    }
    if (one > zero) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}





