///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void sol(){
    int n, m;
    cin >> n >> m;
    vector<string>s1(n + 5), s2(n + 5);
    string str;

    for (int i = 1; i <= n; ++i){
        cin >> str;
        string s = '0' + str;
        s1[i] = s;
    }
    for (int i = 1; i <= n; ++i){
        cin >> str;
        string s = '0' + str;
        s2[i] = s;
    }
    int inc, inc2, a, b, c, d;
    for (int i = 1; i <= n - 1; ++i){
        for (int j = 1; j <= m - 1; ++j){
            if (s1[i][j] == s2[i][j]) continue;
            inc = s2[i][j] - '0';
            if (s1[i][j] > s2[i][j]) inc += 3;
            inc = inc - (s1[i][j] - '0');
            inc2 = 3 - inc;
            a = s1[i][j] - '0';
            b = s1[i + 1][j + 1] - '0';
            c = s1[i][j + 1] - '0';
            d = s1[i + 1][j] - '0';
            a = (a + inc) % 3;
            b = (b + inc) % 3;
            c = (c + inc2) % 3;
            d = (d + inc2) % 3;
            s1[i][j] = a + '0';
            s1[i + 1][j + 1] = b + '0';
            s1[i][j + 1] = c + '0';
            s1[i + 1][j] = d + '0';
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (s1[i][j] != s2[i][j]){
                cout << "NO" << endl;
                return;
            }
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



