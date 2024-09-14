#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    str = '0' + str;
    int tot = 0;
    for (int i = 1; i < n; ++i) if (str[i] != str[i + 1]) ++tot;

    string s;
    int cnt = 0, sum = 0;
    for (int i = 1; i <= n; ++i) {
        s.push_back(str[i]);
        char ch = str[i];
        cnt = 0;
        for (; i <= n; ++i) {
            if (str[i] == ch) ++cnt;
            else {
                --i;
                break;
            }
        }
        sum += (cnt - 1);
    }
//    cout << sum << endl;
    int res;
    res = sum * tot;
    int val = max(0ll, (int)s.size() - 2);
    res += ((val * (val + 1)) / 2);
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}



