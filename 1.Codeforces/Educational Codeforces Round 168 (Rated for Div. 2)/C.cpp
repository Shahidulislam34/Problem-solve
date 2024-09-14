#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define faster(); ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

void sol(){
    int n;
    cin >> n;
    string str;
    cin >> str; str = '0' + str;
    stack<pair<char, int>>pq;
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (pq.empty()) {
            pq.push({str[i], i});
            continue;
        }
        pair<char, int>tmp = pq.top();
        if (tmp.first == '_' && str[i] == ')'){
            str[tmp.second] = '(';
            res += i - tmp.second;
            pq.pop();

        }
        else if (tmp.first == '(' && str[i] == '_') {
            str[i] = ')';
            res += i - tmp.second;
            pq.pop();
        }
        else pq.push({str[i], i});
    }
    cout << res << endl;
}

int32_t main(){
    faster();
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
    return 0;
}



