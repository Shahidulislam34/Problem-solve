///accepted
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n;
string str, tmp;

int cal_res(int len) {
    tmp.clear();
    int sz = str.size();
    for (int i = 1; i <= len / sz; ++i) tmp = tmp + str;
    for (int i = 1; i <= len % sz; ++i) tmp.push_back(str[i - 1]);
    if (tmp.empty()) return 0;
    return stoi(tmp);
}


void sol(){
    cin >> n;
    str = to_string(n);
    int res = 0;
    vector<pair<int, int>>pv;
    for (int a = 1; a <= 1e4; ++a) {
        for (int len = 1; len <= 7; ++len) {
            int val = cal_res(len);
            int b = a * str.size() - tmp.size();
            if (b <= 0 || b > min(10000LL, a * n)) continue;
            else if (a * n - b == val) ++res, pv.push_back({a, b});
        }
    }
    cout << res << endl;
    for (auto [x, y] : pv) cout << x << ' ' << y << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1; cin >> tt;
    while(tt--) sol();
    return 0;
}
