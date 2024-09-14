///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, k;
    cin >> n >> k;
    string str; cin >> str;

    str.insert(str.begin(), '0');
    char mx = 'a';
    for (int i = 1; i <= n; ++i) {
        if ((str[i] - 'a') > k) break;
        else mx = max(mx, str[i]);
    }
    for (int i = 1; i <= n; ++i) if (str[i] <= mx) str[i] = 'a';

    k -= (mx - 'a');
    mx = 'a';
    for (int i = 1; i <= n; ++i) {
        if (str[i] > mx) {
            mx = str[i];
            break;
        }
    }
    char ch = mx - k;
    ch = max(ch, 'a');
    for (int i = 1; i <= n; ++i) {
        if (str[i] >= ch && str[i] <= mx) str[i] = ch;
    }
    for (int i = 1; i <= n; ++i) cout << str[i]; cout << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--)
    sol();
    return 0;
}


