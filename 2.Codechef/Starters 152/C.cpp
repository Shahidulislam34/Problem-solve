#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void sol(){
    int n, m;
    cin >> n >> m;
    vector<string>v(m + 5);
    for (int i = 1; i <= m; ++i) {
        string str; cin >> str;
        str = '0' + str;
        v[i] = str;
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        int one = 0, zero = 0, ques = 0;
        for (int j = 1; j <= m; ++j) {
            if (v[j][i] == '1') ++one;
            else if (v[j][i] == '0') ++zero;
            else ++ques;
        }
        int o1 = one, z1 = zero;
        if (one < zero) one += min(ques, zero - one), ques -= min(ques, zero - o1);
        else zero += min(ques, one - zero), ques -= min(ques, one - z1);
        one += ques / 2;
        zero += ques / 2;
        one += (ques % 2);
        res += one * zero;

    }
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}







