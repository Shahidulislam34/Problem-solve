///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    string str; cin >> str;
    int n = str.size();
    int ind = 0;
    for (int i = n - 1; i >= 0; --i){
        if (str[i] == '1'){
            ind = i;
            break;
        }
    }
    str[n - 1] = '0';
    int res = 0;
    for (int i = ind; i < n; ++i){
        ++res;
        if (str[i] == '0') break;
    }
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}







