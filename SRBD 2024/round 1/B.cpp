#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

int res = 0, len, sb = 0;
string str;

void recur(int pos) {
    if (pos >= len) {
        int dig = stoi(str);
        int tmp2 = __builtin_popcount(dig);
        if (tmp2 > sb) sb = tmp2, res = dig;
        else if (tmp2 == sb && dig > res) res = dig;
        return;
    }
    if (str[pos] == '?') {
        for (int i = 0; i <= 9; ++i) {
            str[pos] = i + '0';
            recur(pos + 1);
            str[pos] = '?';
        }
    }
    else recur(pos + 1);
}

void sol(){
    sb = 0;
    res = 0;
    cin >> str;
    len = str.size();
    recur(0);
    cout << res << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}


