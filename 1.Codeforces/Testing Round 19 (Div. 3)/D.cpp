#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define faster(); ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N = 4e5;
vector<int>pre(N + 5);
void pre_fun(string str) {
    int n = str.size();
    pre[0] = -1;
    int now = -1;
    for (int i = 1; i < n; ++i) {
        while(str[i] != str[now + 1] && now != -1) now = str[now];
        if (str[now + 1] == str[i]) pre[i] = ++now;
        else pre[i] = -1;
    }
}

void sol(){
    string str;
    cin >> str;
    int n = str.size();
    pre_fun(str);
    if (pre[n - 1] + 1 > n / 2) cout << "YES" << endl << str.substr(0, pre[n - 1] + 1) << endl;
    else cout << "NO" << endl;

}

int32_t main(){
    faster();
    sol();
    return 0;
}
